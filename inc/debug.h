/** $Workfile: debug.h $ ,v $Revision: 1.1 $, $Date: 2013/01/20 11:24:01 $ */

#ifndef INC_DEBUG_H
#define INC_DEBUG_H

/**
\unit
    !Debug.
    Output information to deliver debug information.
\note
 */

/* system.*/
#include <stdarg.h>
#include <assert.h>
#include <bool.h>

/* Makro ASSERT.*/
#ifdef DEBUG
#undef ASSERT
#define ASSERT(f)	\
		assert(f)
#else
#define ASSERT(f)
#endif

/* 
    Public interface.
 */
void DebugEnable();
void DebugDisable();
BOOL DebugIsEnabled();

/**
    debug message with var args.
 */
///DOXYS_OFF
int _vdebug(const char *, const char *fmt, va_list args);
int _debug(const char *pFmt, ...);
int _vdiag(const char *pFmt, ...);
///DOXYS_ON

#endif
