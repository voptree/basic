#ifndef MONITOR_H
#define MONITOR_H

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <sys/stat.h>

#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <mutex>
#include "data_manager.h"


struct EVENT{
	int len;
	int wd;
	int mask;
	std::string name;
};

using namespace std;

class CMonitor{
public:
	CMonitor();
	~CMonitor();

public:
	static const int _event_size=sizeof(struct inotify_event);
	static const uint32_t _buf_len=1024*(_event_size*16);
	const int fd ;
	const int EVENTS_TO_WATCH = IN_CREATE | IN_MOVED_TO | IN_DELETE | IN_MODIFY | IN_MOVED_FROM ;

public:	
	void monitor(const vector<string> & dirs);
	void sentinel();
	void enqueue(EVENT evt);
	long get_last_trigger();
	void handle_event(struct EVENT *event);
	
public:
	std::map<std::string,EVENT> * event_map;
	std::mutex m_mtx;
	
private:
	std::map<int,string> * monitor_map;
	long last_trigger;
	
private:
	int _watch(const string & parent , const string& dir);
	void _rm_watch(const string& path);
	
};

#endif
