#include "data_manager.h"
#include "common.h"
#include "log_wrapper.h"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using std::string;
CDataManager * CDataManager::m_data_manager = new CDataManager();

CDataManager::CDataManager():
{}

CDataManager * CDataManager::get()
{
    return m_data_manager;
}

void CDataManager::clear()
{
}

int CDataManager::initialize()
{
    int ret = LOADER_OK;
    clear(); //clear all data

    //init_matcher

    //init_rankgroup

    //init_calc_library

    //init_model_library

    //init_smooth
    //init_allocation

    return DATA_MANAGER_OK;
}



const std::string & CDataManager::get_mddata_dir(){
    return m_mddata_dir;
}

bool CDataManager::startWith(const std::string & str, const std::string & head) {
    return head.length() <= str.length()
            && equal(head.begin(), head.end(), str.begin());
}

bool CDataManager::endWith(const std::string & str, const std::string & tail) {
    return tail.length()<=str.length()                                                    
            && equal(str.begin()+(str.length()-tail.length()), str.end(), tail.begin());  
}

bool CDataManager::is_data_dir(const std::string & path) const{
    return startWith(path,m_mddata_dir);
}

void CDataManager::proc_modify(const std::string & path, const std::string & f_name) const
{
    std::string full_path=path+"/"+f_name;
    RANK_SERVER_LOG_DEBUG("[DataManager] [proc_modify] <modified> path : %s , name : %s , full_path : %s ",path.c_str(),f_name.c_str(),full_path.c_str());
    
    
}

void CDataManager::proc_delete(const std::string& path, const std::string& f_name, bool isdir) const {
    std::string full_path=path+"/"+ f_name;
    RANK_SERVER_LOG_DEBUG("[DataManager] [proc_delete] <delete> path : %s , name : %s , full_path : %s ",path.c_str(),f_name.c_str(),full_path.c_str());
    
    std::vector<std::string> path_vec;
    boost::split(path_vec,path,boost::is_any_of("/"),boost::token_compress_on);

}

void CDataManager::proc_movefrom(const std::string& path, const std::string& f_name, bool isdir) const {
    std::string full_path=path+"/"+ f_name;
    RANK_SERVER_LOG_DEBUG("[DataManager] [proc_movefrom] <movefrom> path : %s , name : %s , full_path : %s ",path.c_str(),f_name.c_str(),full_path.c_str());
    
    std::vector<std::string> path_vec;
    boost::split(path_vec,path,boost::is_any_of("/"),boost::token_compress_on);
}

void CDataManager::proc_movein(const string & path,const string & f_name, bool isdir) const {
    std::string full_path=path+"/"+ f_name;
    RANK_SERVER_LOG_DEBUG("[DataManager] [proc_movein] <movein> path : %s , name : %s , isdir : %d, full_path : %s ",path.c_str(),f_name.c_str(),isdir,full_path.c_str());
    
    std::vector<std::string> path_vec;
    boost::split(path_vec,path,boost::is_any_of("/"),boost::token_compress_on);
    
}

void CDataManager::proc_create(const string & path,const string & f_name, bool isdir) const {
    std::string full_path=path+"/"+ f_name;
    RANK_SERVER_LOG_DEBUG("[DataManager] [proc_create] <create> path : %s , name : %s , full_path : %s ",path.c_str(),f_name.c_str(),full_path.c_str());
    
    std::vector<std::string> path_vec;
    boost::split(path_vec,path,boost::is_any_of("/"),boost::token_compress_on);
    
}
