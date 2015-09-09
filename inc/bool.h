#ifndef INC_BOOL_H
#define INC_BOOL_H

/* undefine BOOL and use C99 _Bool type.*/
#ifdef BOOL
#undef BOOL
#endif

#ifndef WIN32
#include <stdbool.h>	/**<C99.*/
typedef _Bool BOOL;		/**<Boolean datatype from type _Bool.*/
#else 
#ifndef _Bool			/**<C99.*/
typedef int _Bool;
#endif
typedef _Bool BOOL;		/**<Boolean datatype fron type _Bool.*/
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif
#endif

#ifndef FALSE
#define FALSE false		/**<False value set to 1.*/
#endif

#ifndef TRUE
#define TRUE true		/**<True value set to 0.*/
#endif

#endif
