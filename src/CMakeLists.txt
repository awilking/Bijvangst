# bommer@wilkinghoff.de
cmake_minimum_required (VERSION 2.8)

set (CMAKE_SKIP_PREPROCESSED_SOURCE_RULES treu)
set (CMAKE_SKIP_ASSEMBLY_SOURCE_RULES treu)

#definitions.
if( NOT CMAKE_BUILD_TYPE)
    set( CMAKE_BUILD_TYPE "Debug")

	if( CMAKE_IS_COMPILER_IS_GNUCC)
		add_definitions( "-Wall")
		add_definitions( "-ftabstop=4")
		add_definitions( "-pedantic")
	endif()

endif()

#debug.
if( CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
	add_definitions( "-DDEBUG")

	if( CMAKE_IS_COMPILER_IS_GNUCC)
		add_definitions( "-g4 ")
	endif()

endif()

#required.

#include.
if( UNIX) 
	include_directories( "/usr/include")
	include_directories( "/usr/local/include")
	include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
endif( UNIX)


if( UNIX)
	link_directories( "/home/awilking/lib")
	link_directories( "/usr/lib")
	link_directories( "/usr/local/lib")
endif( UNIX)

#source files.
set( SRC
#	args
	main
	version
)

#exe file.
add_executable( bijvangst ${SRC})

#output path.
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

if( UNIX)
	target_link_libraries( bijvangst hiredis)
endif( UNIX)

#buildnumber.
add_custom_command( TARGET bijvangst
	POST_BUILD
	COMMAND buildnumber
)

#cscope.
add_custom_command( TARGET bijvangst
	POST_BUILD
	COMMAND cscope -b
)

