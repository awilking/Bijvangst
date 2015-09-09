/** 
	\namespace args
	Scan commandline and read arguments.
	Read arguments from commandline and split into flags. Servername, configuration file must be given. 
	All other arguments are optional.  Configuration file describes the configuration of the server and 
	is needed to proper initialization of the server.

!Purpose:
	Read flags from cmdline.
\endexample
 */

/* system.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

#include "def.h"
#include "error.h"
#include "debug.h"
#include "diagnose.h"
#include "version.h"

/* local.*/
#include "args.h"

#define ARG_START 2
#define CONFIG_EXT ".cfg"

/*
	Local prototype.
 */
///DOXYS_OFF
static BOOL checkNumberOfArgs( int );
static BOOL check( char *);
static void displayHelp( );
static void displayVersion( );
///DOXYS_ON

/**
	CT Debugfile.
 */
static char szCtDbgFile[255] = "";

/**
	Certificate.*/
static char szCertificate[255] = "";

/**
	Short options with char as buffer. 
	Followed by <:> indicates arg.
 */
static const char * const sOpt = "hql:n:vd";

/**
	Long options.

	1. long option as string
	2. <1> requires arg, <0> not
	3. <null>
	4. corresponding short option char
 */
static const struct option lOpt[] = {
	{ "help", 0, NULL, 'h'},
	{ "quiet", 0, NULL, 'q'},
	{ "config", 1, NULL, 'c'},
	{ "log", 1, NULL, 'l'},
	{ "version", 0, NULL, 'v'},
	{ "diag", 0, NULL, 'd'},
	{ NULL, 0, NULL, 0}
};

/** 
	Strip args from commandline to configure the application and startup.
	If no Servername is given, then DSLISTEN or the default Servername is used.
	\example
	Extract boom: -s <server name> -c <config file>
	\endexample
	@param nArg Number of arguments
	@param pArgv Array of Pointer to Strings
	@param pConfigName Pointer to String, to hold configuration name
	@return 1
	\note
	Actual -s -c are supported.
 */
long ArgsParse( int nArg, char **pArgv, char **pConfigName)
{
	int nOption = 0;

	/* check number of args.*/
	if (checkNumberOfArgs( nArg ) == FALSE) {
		/* wrong args.*/
		displayHelp( );
		return (0);
	}

	do {
#ifdef WIN32
		nOption = _getopt_internal (nArg, pArgv, sOpt, lOpt, NULL);
#else
		nOption = getopt_long (nArg, pArgv, sOpt, lOpt, NULL);
#endif

		/* switch by.*/
		switch (nOption) {
		case 'c':
			/* configname must exist.*/
			*pConfigName = optarg;
			break;
		case 'l':
			/* logging flags.*/
			g_dbgflags |= atoi( optarg );
			break;
		case 'v':
			/* version.*/
			displayVersion( );

			exit( 0 );
			break;
		case 'd':
			/* Diagnostic.*/
			DebugEnable( );

			if (Diagnose( ) == DIAG_NOK) {
				/* error diagnostic.*/
				exit( ERR_DIAGNOSE );
			}
			exit( 0 );
			break;
		case 'h':
		case '?':
			/* help.*/
			displayHelp( );

			exit( 0 );
			break;
		case 'q':
			/* quiet.*/
			setQuietMode( TRUE );
			break;
		case -1:
			break;
		default:
		{
			/* unknown flag.*/
			displayHelp( );

			exit( 0 );
		}
			break;
		}
	}
	while (nOption != -1);

	/* set ConfigFile. */
	if ((*pConfigName != NULL) && (!(strlen( *pConfigName )))) {
		/* set servername = config.*/
		strcpy( *pConfigName, *pServerName );
		/* append extension.*/
		strcat( *pConfigName, CONFIG_EXT );
	}
	else {
		return (0);
	}

	return (1);
}

/**
	Check number of aurguments.
	Arg 1: Name of executable.
	Arg 2,3: Name of server. name of config.
	@param nArg Number of arguments.
	@return int Return true or false.
 */
static BOOL checkNumberOfArgs( int nArg )
{
	BOOL bRetCode = TRUE;

	/* min n arguments.*/
	if (nArg < MAX_ARG_COUNT) {
		bRetCode = FALSE;
	}

	return (bRetCode);
}

/**
	Check parsed aurguments. At minimal server, configuration file and max number of connections must be given.
	@param pServerName Handle to server name.
	@param pConfigName Handle to configuration name.
	@param nMaxConnect Number of maximal connections.
	@return int Return true or false.
 */
static BOOL check( char *pConfigName)
{
	BOOL bRetCode = TRUE;

	return (bRetCode);
}

/**
	Display help on argument list.
 */
static void displayHelp( )
{
	printf( "This is bijvangst. Usage:" );
	printf( "bijvangst [options] [...]\n\n" );
	printf( "Options:\n\n" );
	printf( "  [-c] [--config]     configuration file\n" );
	printf( "  [-d] [--diag]       diagnostic messages\n" );
	printf( "  [-l] [--log]        logging file\n" );
	printf( "  [-v] [--version]    version string\n" );
}

/**
	Display version on argument list.
 */
static void displayVersion( )
{
	char sVersion [255 + 1] = "";

	printf( "%s - %s\n", DEF_NAME, InternalVersion( sVersion, sizeof (sVersion) ) );
}
