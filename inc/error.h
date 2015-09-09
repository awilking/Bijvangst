/** $Workfile: error.h $ ,v $Revision: 1.1 $, $Date: 2011/11/22 07:17:15 $ */

#ifndef INC_ERROR_H
#define INC_ERROR_H

/**
\note
 */

/* system.*/
#include <stdarg.h>

/* error code.*/
#include "error_code.h"

/*
    Member function with variable argument list.
 */
///DOXYS_OFF
int _verror(const char *, const char *fmt, va_list args);
int _error(const char *fmt, ...);
///DOXYS_ON

#endif
