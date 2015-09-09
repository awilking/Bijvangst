#ifndef INC_DEF_H
#define INC_DEF_H

/**
\unit
    !Definition and limits.
    Set global limits.
    -added _Bool to reflect changes in C99.
\note
 */

/* limit.*/
#include "limit.h"

/* memory check.*/
#ifdef _DEBUG_MEMORY
#include "mem_leak.h"
#endif

/* datatype bool.*/
#include "bool.h"

/**<Stderr.*/
#ifndef STDERR
#define STDERR stderr									
#endif

/**<Stdout.*/
#ifndef STDOUT
#define STDOUT stdout									
#endif

/**<newline constant*/
#ifndef NEWLINE
#define NEWLINE "\n"									
#endif

/**<tabulator constant.*/
#ifndef TAB
#define TAB "\t"										
#endif

/**<blank character.*/
#ifndef BLANK
#define BLANK " "										
#endif

/**<True default.*/
#ifndef STR_TRUE
#define STR_TRUE "TRUE"									
#endif

/**<False default.*/
#ifndef STR_FALSE
#define STR_FALSE "FALSE"								
#endif

/**<NULL.*/
#ifndef STR_NULL
#define STR_NULL "NULL"									
#endif

/**<UNKNOWN.*/
#ifndef STR_UNKNOWN
#define STR_UNKNOWN "UNKNOWN"							
#endif

/**<NAME.*/
#ifndef DEF_NAME
#define DEF_NAME "BIJVANGST"								
#endif

/**
    Handle.
 */
#ifndef P_HANDLE
typedef unsigned int * P_HANDLE;
#endif

/**
    void pointer.
 */
#ifndef P_VOID
typedef void * P_VOID;
#endif

/**
    char pointer.
 */
#ifndef PSTR
typedef char * PSTR;
#endif

/** 
    const char pointer.
 */
#ifndef CPSTR
typedef const char * CPSTR;
#endif

/**
    unsigned.
 */
#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

/**
    unsigned pointer.
 */
#ifndef P_UCHAR
typedef unsigned char * P_UCHAR;
#endif

/**
    const unsigned pointer.
 */
#ifndef CP_UCHAR
typedef const unsigned char * CP_UCHAR;
#endif

#endif
