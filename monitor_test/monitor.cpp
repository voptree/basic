#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <ctime>

#include "monitor.h"
#include "common.h"

CMonitor::CMonitor():
        fd(inotify_init())
{
    last_trigger=0;
    monitor_map=new map<int,string>();
    event_map=new map<string,EVENT>();
}

CMonitor::~CMonitor(){
    if(monitor_map!=nullptr){
        if(fd>0){
            for(map<int,string>::iterator it=monitor_map->begin();it!=monitor_map->end();it++){
                ( void ) inotify_rm_watch( fd, it->first );
            }
            ( void ) close( fd );
        }
        
        delete monitor_map;
    }
    if(event_map!=nullptr){
        event_map->clear();
        delete event_map;
    }
}

long CMonitor::get_last_trigger(){
    return last_trigger;
}

void CMonitor::enqueue(EVENT event){
    auto it=monitor_map->find(event.wd);
    string path=it->second;
    string name=event.name;
    string full_path=path+"/"+name;

    if(name[0]!='.'){
        m_mtx.lock();

        if(event_map->find(full_path) != event_map->end()){
            event_map->erase(full_path);
        }
        event_map->insert(make_pair(full_path , event));
        last_trigger=time(NULL);
                
        m_mtx.unlock();
    }
}

void CMonitor::handle_event(struct EVENT * event)
{
    if ( event->len ) {
        auto it=monitor_map->find(event->wd);
        string path=it->second;
        string name=event->name;
        string full_path=path+"/"+name;
        
        CDataManager * m_dm = CDataManager::get();
                        
        if(name[0]!='.'){
            if ( event->mask & IN_CREATE ) {
                if ( event->mask & IN_ISDIR ) {
                    _watch("",full_path);
                    m_dm->proc_create(path,name,true);
                }
                else {
                    m_dm->proc_create(path,name,false);
                }
            }else if ( event->mask & IN_MOVED_TO ) {
                if ( event->mask & IN_ISDIR ) {
                    _watch("",full_path);
                    m_dm->proc_movein(path,name,true);
                }
                else {
                    m_dm->proc_movein(path,name,false);
                }
            }else if ( event->mask & IN_DELETE ) {
                if ( event->mask & IN_ISDIR ) {
                    _rm_watch(full_path);
                    m_dm->proc_delete(path,name,true);
                }
                else {
                    m_dm->proc_delete(path,name,false);
                }
            }else if ( event->mask & IN_MODIFY ) {
                if ( event->mask & IN_ISDIR ) {
                    printf("may not be happend . ");
                }
                else {
                    m_dm->proc_modify(path,name);
                }
            }else if ( event->mask & IN_MOVED_FROM ) {
                if ( event->mask & IN_ISDIR ) {
                    _rm_watch(full_path);
                    m_dm->proc_movefrom(path,name,true);
                }else {
                    m_dm->proc_movefrom(path,name,false);
                }
            }
        }
    }
}

void CMonitor::_rm_watch(const string & path){
    int cwd=-1;    
    for(map<int,string>::iterator it=monitor_map->begin();it!=monitor_map->end();it++){
        if(it->second==path){
            cwd=it->first;
            break;
        }
    }

    if(cwd==-1){
        printf("[Monitor] can not find watcher description for path : %s ",path.c_str());
    }else{
        monitor_map->erase(cwd);
        ( void ) inotify_rm_watch( fd, cwd );
        printf("[Monitor] --- remove watcher at path : %s ",path.c_str());
    }
}

int CMonitor::_watch(const string & parent , const string & dir) {
    if ( fd < 0 ) {
        printf("[Monitor] inotify init error . failed to start monitor .");
        return -1;
    }

    if(dir.empty()){
        printf("[Monitor] empty path .");
        return -1;
    }

    string full_path=parent.empty()?dir:parent+"/"+dir;
    
    int wd = inotify_add_watch(fd,dir.c_str(), EVENTS_TO_WATCH);
    monitor_map->insert(make_pair(wd,full_path));

    DIR* dir_p;
    struct dirent* dirent_p;
    struct stat buf;

    if(!(dir_p=opendir(dir.c_str()))){
        printf( "[Monitor] open dir : %s failed . ",dir.c_str());
        return -1;
    }

    int nback=1;
    if(*dir.begin()!='/'){
        vector<string> p_vec;
        boost::split(p_vec,dir,boost::is_any_of("/"));
        nback=p_vec.size();
        if(*(dir.end()-1)=='/'){
            nback=(nback>1)?nback-1:1;
        }
    }
    
    chdir(dir.c_str());
    
    while((dirent_p=readdir(dir_p)) != NULL){
        lstat(dirent_p->d_name,&buf);

        string name(dirent_p->d_name);
        string f_path=dir+"/"+name;
        
        if(S_ISDIR(buf.st_mode)){
            if(name!="." && name!=".."){
                if(dir[0]=='/'){
                    _watch("",f_path.c_str());
                }
                else{
                    _watch(full_path,name.c_str());
                }
            }
        }
    }

    for(int i=0;i<nback;i++)
        chdir("..");
    
    closedir(dir_p);
    printf( "[Monitor] watched dir : %s on wd : %d . ",full_path.c_str(), wd);
    
    return wd;
}

void * _sentinel(void * args){
    CMonitor * m = (CMonitor *)args;
    
    if(m!=nullptr){
        try{
            printf("[Monitor] >>> MONITOR SENTINEL THREAD START <<<");

            
            std::string model_root="data/model";
            std::string smth_root="data/ad_smooth";
            std::string alloc_root="data/allocation"
            
            printf("[Monitor] model root : %s , ready in loop . ", model_root.c_str());
            uint root_sz=model_root.size();
            
            while(1){
                long last = m->get_last_trigger();

                if(last>0){
                    long now = time(NULL);
                    if(m->event_map->size() >0 && now - last > 5){
                        printf("[Monitor] there is no event over 5 seconds , begin update . now : %ld , last trigger : %ld " , now ,last);

                        m->m_mtx.lock();
                        std::map<std::string,EVENT> e_map(m->event_map->begin(),m->event_map->end());
                        m->event_map->clear();
                        m->m_mtx.unlock();

                        for(auto it=e_map.begin();it!=e_map.end();it++){
                            std::string fullpath=it->first;
                            
                            if(fullpath.size() > root_sz && (CDataManager::startWith(fullpath,model_root) || CDataManager::startWith(fullpath,smth_root) || CDataManager::startWith(fullpath,alloc_root)) ){
                                auto nit=it;
                                nit++;
                                while(nit!=e_map.end()){
                                    if(CDataManager::startWith(nit->first,fullpath)){
                                        e_map.erase(nit++);
                                    }else
                                        nit++;
                                }
                            }
                        }

                        for(auto it=e_map.begin();it!=e_map.end();it++){
                            EVENT evt=it->second;
                            m->handle_event(&(it->second));
                        }
                    }
                }

                sleep(1);
            }
        }catch(...){
            printf("[Initiator] monitor error . ");
        }
    }else{
        printf("[Monitor] can not pass this to sentinel . ");
    }
    return NULL;
}

void CMonitor::sentinel(){
    pthread_t t; 
    if( pthread_create(&t, NULL , _sentinel , this) != 0 )
    {
        printf("[Monitor] start monitor sentinel thread error " );
    }
}

void CMonitor::monitor(const vector<string> & dirs){
    if(fd>0){
        if(dirs.size()>0){
            char buffer[_buf_len];

            for(auto it=dirs.begin();it!=dirs.end();it++)
                _watch("",*it);

#ifdef __DEBUG__
            for (auto idx = monitor_map->begin();idx!=monitor_map->end();idx++) {
                printf("[Monitor] <monitor-pair> %d : %s ",idx->first,idx->second.c_str());
            }
#endif
            sentinel();
            int length, i = 0 ;

            while(1){
                i=0;
                length = read( fd, buffer,_buf_len);
      
                if ( length < 0 ){
                    printf("[Monitor] read event error . ERRNO : %d",errno);
                }
            
                while ( i < length ) {
                    struct inotify_event * event = ( struct inotify_event * )& buffer[ i ];
                    std::string name=event->name;

                    if(name.size()>2){
                        EVENT e;
                        e.len=event->len;
                        e.wd=event->wd;
                        e.mask=event->mask;
                        e.name=event->name;
                        enqueue(e);
                    }
                    i += _event_size + event->len;
                }
            }
        }else{
            printf("[Monitor] no path to watch . ");
        }
    }else{
        printf("[Monitor] init inotify failed . ");
    }
}

