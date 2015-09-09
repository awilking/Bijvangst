/** 
	\namespace Version
	Show version and copyright.

!Purpose:
	Retrieve, set or check version.	
	©André 02/2007 Bommer\@allasoft.de
\internal Version management.
*/

#include <stdio.h>
#include <string.h>

#include "def.h"
#include "buildnumber.h"

#include "version.h"

/**<Quiet member indicator var.*/
static BOOL m_bQuiet = FALSE;					

/**
	Set output mode to <yes> or <no>.
	@bFlag Yes or no.
*/
void setQuietMode (BOOL bFlag)
{
	m_bQuiet = bFlag;
}

/**
	Get output mode.
	@return TRUE or FALSE.
*/
BOOL getQuietMode ()
{
	return (m_bQuiet);
}

/**
	Print version to the screen.
*/
void Version ()
{
	char szBuffer[255+1];

	/* init.*/
	memset( szBuffer, '\0', sizeof (szBuffer));

	sprintf (szBuffer,  "AllaSoft - Bommer - Bommer@wilkinghoff.de (%d.%d)\n", VER_BIJVANGST_MAJOR, VER_BIJVANGST_MINOR);
	printf (szBuffer);
}

/**
	Print internal version. Buffer must be large enough to set buildnumber and version.
	If nLen is greater than length of buffer <no version> is returned.
	@pBuffer Handle to destination buffer.
	@nLen Maximal length of buffer.
	@return Handle to buffer.
*/
char *InternalVersion (char *pBuffer, int nLen)
{
	if (VER_BIJVANGST_MICRO != 0) {
		sprintf (pBuffer, "ver %d.%d patch %d build " BUILDNUMBER_STR, VER_BIJVANGST_MAJOR, VER_BIJVANGST_MINOR, VER_BIJVANGST_MICRO); 
	}
	else {
		sprintf (pBuffer, "ver %d.%d build " BUILDNUMBER_STR, VER_BIJVANGST_MAJOR, VER_BIJVANGST_MINOR); 
	}

	if ((int) strlen (pBuffer) > nLen)
		return ("no version");
	else
		return (pBuffer);
}


/**
	Print copyright message to the screen.
*/
void Copyright()
{
	printf( "Confidential property of AllaSoft,Inc. Copyright 2009 all rights reserved.\n");
	printf( "Unpublished rights reserved under U.S., German and European copyright laws. \n\n");
}

