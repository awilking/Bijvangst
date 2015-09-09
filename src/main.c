/**
\mainpage "Bijvangst

	#Purpose#:
\internal Under construction
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>

static redisContext *pContext = NULL;

///DOXYS_OFF
static void cleanup();
///DOXYS_ON

/** 
	main entry.
*/
int main( int nArg, char **pArgv)
{
	int nRetCode = 0;
	redisReply *pReply;
	struct timeval timeout = { 1, 500000};

	const char *sHostname = "127.0.0.1";
	int nPort = 6379;

	atexit( cleanup);

	pContext = redisConnectWithTimeout( sHostname, nPort, timeout);

	if( pContext != NULL) {
		if( pContext->err != 0) {
			printf( "Connection error: %s", pContext->errstr);

			exit( 1);
		}

	}

	/* ping.*/
	pReply = redisCommand( pContext, "PING");
	printf( "PING: %s\n", pReply->str);
	freeReplyObject( pReply);

	/* set key.*/
	pReply = redisCommand( pContext, "SET %s %s", "foo", "hello world");
	printf( "SET: %s\n", pReply->str);
	freeReplyObject( pReply);
	
	/* get key.*/
	pReply = redisCommand( pContext, "GET %s", "foo");
	printf( "GET: %s\n", pReply->str);
	freeReplyObject( pReply);

	cleanup();

	return( nRetCode);
}

/**
	cleanup.
*/
static void cleanup()
{
	if( pContext != NULL) {
		redisFree( pContext);
	
		pContext = NULL;
	}
}



