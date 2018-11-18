#ifndef COMMON_H_
#define COMMON_H_
#include <string>

//STATUS CODE
const int SERVER_OK = 0;

const int SERVER_ERR = -1;

const int SERVER_ERR_INIT = -2;

//TP SIZE
const int TP_PROTO_MESSAGE_SIZE = 40;
const int TP_GATHERER_SIZE = 10;
const int TP_EXECUTE_SIZE = 40;

//RANDOM_MODEL
const std::string RANDOM = "_RANDOM_";

//matcher all
const std::string MC_ALL = "_ALL_";

//CONFIG
const std::string SERVER_CONFIG_PORT("server_port");

const std::string SERVER_CONFIG_TIMEOUT("server_timeout");

const std::string SERVER_CONFIG_MAXTHREADS("max_threads");

const std::string SERVER_CONFIG_MAXCONNECTIONS("max_connections");

const std::string SERVER_CONFIG_REQ_QUEUE("req_queue");

const std::string SERVER_CONFIG_LOG("log");

const std::string HANDLER_CONFIG_TIMEOUT("timeout");

const std::string THREADPOOL_CONFIG_MAXWORKERS("max_workers");

const std::string THREADPOOL_CONFIG_MAX_QUEUE_SIZE("max_queue_size");

const std::string MATCHER_CONFIG_PATH("matcher_path");

const std::string RANKGROUP_CONFIG_PATH("rankgroup_path");

const std::string MODELLIBRARY_CONFIG_PATH("model_path");

const std::string CALCLIBRARY_CONFIG_PATH("calc_path");

const std::string SMOOTH_ENABLE_CONFIG("smooth_enable");

const std::string SMOOTH_DATA_PATH("smooth_data");

const std::string ALLOC_ENABLE_CONFIG("alloc_enable");

const std::string ALLOC_DATA_PATH("alloc_data");

const std::string CONF_MONITOR_PATH("conf_monitor_path");

const std::string DATA_MONITOR_PATH("data_monitor_path");

const std::string SMOOTH_MONITOR_PATH("smooth_monitor_path");

const std::string ALLOC_MONITOR_PATH("alloc_monitor_path");


//DEFAULT
const int SERVER_DEFAULT_PORT = 23333;

const int SERVER_DEFAULT_TIMEOUT = 100;

const int SERVER_DEFAULT_MAXTHREADS = 40;

const int SERVER_DEFAULT_MAXCONNECTIONS= 500;

const int SERVER_DEFAULT_REQ_QUEUE = 5000;

const int HANDLER_DEFAULT_TIMEOUT = 60;

const int THREADPOOL_DEFAULT_MAXWORKERS = 40;

const int THREADPOOL_DEFAULT_MAX_QUEUE_SIZE = 40000;


//cast const for utest
const std::string MATCHER_DEFAULT_PATH("conf/matchers.xml");

const std::string RANKGROUP_DEFAULT_PATH("conf/rankgroup.xml");

const std::string CALCLIBRARY_DEFAULT_PATH("conf/calc.xml");

const std::string MODELLIBRARY_DEFAULT_PATH("conf/models.xml");

//EXP 
const std::string SERVER_EXPERIMENT_LAYER("algorithm");

//default 
const std::string DEFAULT_CONF_MONITOR_PATH("conf");

const std::string DEFAULT_DATA_MONITOR_PATH("data/model");

const std::string DEFAULT_SMOOTH_MONITOR_PATH("data/ad_smooth");

const std::string DEFAULT_ALLOC_MONITOR_PATH("data/allocation");

const std::string DEFAULT_SMOOTH_DATA_PATH("data/ad_smooth/ad_smooth");

const std::string DEFAULT_ALLOC_DATA_PATH("data/allocation/allocation_plan");

//KPI
const std::string ADRANKSERVER_KPI("adrankserver");

const std::string KPI_REQUEST("request");

const std::string KPI_REQUEST_TOTAL("total");

const std::string KPI_REQUEST_RANKGROUP("rankgroup");

const std::string KPI_REQUEST_MODELGROUP("modelgroup");

const std::string KPI_REQUEST_CLACULATOR("calculator");

const std::string KPI_TIME("time");

const std::string KPI_TIME_TOTAL("total");

const std::string KPI_TIME_CALCULATE("calculator");

// remote log config
const std::string REMOTELOG_CONFIG_ENABLE("enable");
const std::string REMOTELOG_CONFIG_IP("ip");
const std::string REMOTELOG_CONFIG_PORT("port");
const std::string REMOTELOG_CONFIG_TIMEOUT("timeout");
const std::string REMOTELOG_CONFIG_TRY_TIMES("try_times");
// remote log default
const bool REMOTELOG_DEFAULT_ENABLE = 0;
const std::string REMOTELOG_DEFAULT_IP("192.168.219.241");
const int REMOTELOG_DEFAULT_PORT = 55000;
const int REMOTELOG_DEFAULT_TIMEOUT = 100;
const int REMOTELOG_DEFAULT_TRY_TIMES = 3;

// model debug info json key
const std::string JK_IS_DEBUG("is_debug");
const std::string JK_SESSIONID("sessionid");
const std::string JK_PVID("pvid");
const std::string JK_PROVINCE("province");
const std::string JK_CITY("city");
const std::string JK_USER_AGENT("user_agent");
const std::string JK_PSID("psid");
const std::string JK_PLATFORM("platform");
const std::string JK_TOPN("topn");
const std::string JK_FILE_NAME("file_name");
const std::string JK_FILE_TIME("file_time");
const std::string JK_FILE_DETAIL("file_detail");
const std::string JK_LAB_NAME("lab_name");
const std::string JK_LOG_TIME("log_time");
const std::string JK_MODEL("model");
const std::string JK_CREATIVE("creative");
const std::string JK_FEATURES("features");
const std::string JK_FIT_FEATURES("fit_features");
const std::string JK_USE_COLD_BOOT("cold_boot");
const std::string JK_WEIGHT("weight");
const std::string JK_ECPM("ecpm");
const std::string JK_ALGO_NAME("algo_name");
const std::string JK_EXP_DATA("exp_data");
const std::string JK_EXP_SELECTED("selected");
const std::string JK_LAYER_NAME("layer_name");
const std::string JK_EXP_NAME("exp_name");
const std::string JK_BUCKET_ID("bucket_id");
const std::string JK_FILTER("filter");
const std::string JK_EXP_ID("dyer_exp_id");
const std::string JK_EXP_INFO("exp_info");
const std::string JK_ALLOCATE_TYPE("allocate_type");
const std::string JK_AREA_ID("area_id");
const std::string JK_EXP_PATH("path");
const std::string JK_CTR_CORRECTION("ctr_correction");
const std::string JK_BROWSER("browser");
const std::string JK_STATUS("status");
const std::string JK_FILTERED("filtered");
const std::string JK_PRIORITY("priority");
const std::string JK_RANKRESULT("rankresult");

#endif
