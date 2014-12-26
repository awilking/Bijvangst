# wilkinghoff@ap.com
cmake_minimum_required(VERSION 2.8)

#Project Bijvangst.
project (Bijvangst C)

#Version.
set (VER_MAJOR 0)
set (VER_MINOR 0)
set (VER_MICRO 1)

#Log Level.
set (LOG_LEVEL 1)

if (UNIX)
	configure_file (inc/version.h.in inc/version.h @only)
endif( UNIX)

subdirs( src)
subdirs( UnitTest)

