# wilkinghoff@ap.com
cmake_minimum_required(VERSION 2.8)

#Project Bijvangst.
project (Bijvangst C)

#Version.
set (VER_BIJVANGST_MAJOR 0)
set (VER_BIJVANGST_MINOR 0)
set (VER_BIJVANGST_MICRO 1)

#Log Level.
set (LOG_LEVEL 1)

if (UNIX)
	configure_file (inc/version.h.in inc/version.h @only)
endif( UNIX)

if( UNIX)
    configure_file( log4crc.in log4crc @ONLY)
    configure_file( ${PROJECT_NAME}.cfg.in ${PROJECT_NAME}.cfg @ONLY)
endif()

subdirs( src)
subdirs( UnitTest)


