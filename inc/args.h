#ifndef INC_ARGS_H
#define INC_ARGS_H

/**
\unit
    !Argument list.
\note
 */

/**
    Number of max args.
 */
#ifndef MAX_ARG_COUNT 
#define MAX_ARG_COUNT 2
#endif

/**
    Public interfacec.
 */
///DOXYS_OFF
long ArgsParse(int, char **, char **, char **, int *);
long ArgsSrvFlags();
long ArgsCtxFlags();
long ArgsCtcFlags();
long ArgsDbgFlags();
long ArgsDebugFlags();
///DOXYS_ON

#endif
