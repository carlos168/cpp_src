#include <stdlib.h>
#include <stdio.h>
#include <zlog.h>

enum err_code
{
    err_success = 0,
    err_system = 1
};

typedef enum err_level
{
    LOG_EMERG = 0,
    LOG_ALERT = 1,
    LOG_CRIT = 2,
    LOG_ERR = 3,
    LOG_WARNING = 4,
    LOG_NOTICE = 5,
    LOG_INFO = 6,
    LOG_DEBUG = 7
} ERR_LEVEL;

#define TEST 168

//char *glog_level[] = {"LOG_EMERG", "LOG_ALERT", "LOG_CRIT", "LOG_ERR", "LOG_WARNING", "LOG_NOTICE", "LOG_INFO", "LOG_DEBUG"};

/*
#define DZLOG_FATAL
#define DZLOG_ERROR
#define DZLOG_WARN
#define DZLOG_NOTICE
#define DZLOG_INFO
*/
//#define DZLOG_DEBUG(...) dzlog_debug(...)

#define getParamName(param) (#param)

int main(int argc, char *argv[])
{
    printf("main is running ...\n");
    printf("err_success=%d\n", err_success);
    printf("err_success=%s\n", getParamName(err_success));   
    printf("TEST=%s, test=%d\n", getParamName(TEST), TEST);
    
    ERR_LEVEL test123 = LOG_ERR;
    printf("test123=%s, test123=%d, test123=%s\n", getParamName(test123), test123, getParamName(test23));
    

    int ret = dzlog_init("log.conf", "my_cat");
    if (ret < 0) {
        printf(" ! dzlog_init failed\n");
        return -1;
    }
    dzlog_fatal("fatal");
    dzlog_error("[LOG_ERR] [%d] error", err_system);
    dzlog_warn("warn");
    dzlog_notice("notice");
    dzlog_info("info");
    dzlog_debug("[LOG_DEBUG] [%d] debug", err_success);    

	return 0;
}

