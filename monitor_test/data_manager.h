#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_

#include <map>
#include <string>


const int DATA_MANAGER_OK = 0;
const int DATA_MANAGER_ERR = -1;

class CDataManager
{
    public:
        static CDataManager * get();
		static bool startWith(const std::string & str,const std::string & head);
		static bool endWith(const std::string & str, const std::string & tail);
		

		const std::string & get_mddata_dir();

		int initialize();
		
		void proc_modify(const std::string & path, const std::string& f_name) const ;
		void proc_delete(const std::string & path,
                const std::string & f_name, bool isdir) const ;
		void proc_movefrom(const std::string & path,
                const std::string & f_name, bool isdir) const ;
		void proc_movein(const std::string & path,
                const std::string & f_name, bool isdir) const ;
		void proc_create(const std::string & path,
                const std::string & f_name, bool isdir) const ;

    private:
        CDataManager();
        virtual ~CDataManager() {};

    private:
        void clear();
		bool is_data_dir(const std::string & path) const;
		
    private:
		static CDataManager * m_data_manager;

		
};

#endif //DATA_MANAGER_H_
