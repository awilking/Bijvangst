#ifndef INC_ERROR_CODE_H
#define INC_ERROR_CODE_H

#include "bool.h"

/**
\unit
    !Error code definition.
\note
 */

/* 
    Error code.
 */
#define ERR_EXIT -1										/**<Fatal error code.*/
#define ERR_SRV_INIT -2									/**<Init server error code.*/
#define ERR_LOG -3										/**<Error logging.*/
#define ERR_BACKUP -4									/**<Error backup.*/
#define ERR_HANDLER -5									/**<Error internal handler.*/
#define ERR_SQL -6										/**<Error SQL Driver.*/
#define ERR_CONNECT -7									/**<Error Login.*/
#define ERR_SRV -8										/**<Error Srv setup.*/

#define INIT_OK 0										/**<Init ok.*/

#define ERR_CONFIG -101									/**<Configuration error.*/
#define ERR_FILENAME -102								/**<Error filename.*/
#define ERR_LOG_INIT -103								/**<Error log.*/
#define	ERR_LOG_READ -104								/**<Error log read.*/
#define ERR_CHECK -105									/**<Error check.*/
#define ERR_MEMORY -106									/**<Error memory.*/
#define ERR_INIT_CONFIG -107							/**<Error configuration file.*/
#define ERR_CONFIG_READ -108							/**<Error configuration read.*/
#define ERR_PROCESS -109								/**<Error processing.*/
#define ERR_DIAGNOSE -110				    			/**<Problem with diagnose.*/
#define ERR_ARGS -111									/**<Wrong argument list.*/
#define ERR_PATTERN -112								/**<Pattern invalid.*/

/* application error level.*/
typedef enum {
    APP_ERR_NONE = 0,                                   /**<none.*/
    APP_ERR_WARNING = 1,                                /**<warning.*/
    APP_ERR_ERROR = 2,                                  /**<error.*/
    APP_ERR_FATAL = 3,                                  /**<fatal error.*/
} APP_ERROR_LEVEL;

/* application error domain.*/
typedef enum {
    APP_FROM_NONE = 0,                                  /**<none.*/
} APP_ERROR_DOMAIN;

/* application error type.*/
typedef struct _app_error_t *P_APP_ERROR;

/* application error struct.*/
typedef struct _app_error_t {
    APP_ERROR_LEVEL level;                              /**<error level.*/
    APP_ERROR_DOMAIN domain;                            /**<domain.*/
    int nCode;                                          /**<error code.*/
    char *pMsg;                                         /**<message.*/
    int nUsrCode;                                       /**<user code.*/
    char *pUsrMsg;                                      /**<user message.*/
    int nSysCode;                                       /**<system code.*/
    char *pSysMsg;                                      /**<system message.*/
} APP_ERROR;

/**
    Public interface.
 */
///DOXYS_OFF
P_APP_ERROR getAppError();
void setAppError(APP_ERROR_LEVEL, APP_ERROR_DOMAIN, int);
void setAppUsrMsg(int, char *);
void setAppSysMsg(int, char *);
BOOL isAppError();
///DOXYS_ON

#endif
