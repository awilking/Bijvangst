# wilkinghoff@sap.com
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
	include_directories( "~/boost-1.46.1")
	include_directories( "~/dld2-evulationkit-2.4.12")
	include_directories( "~/dld2-evulationkit-2.4.12/interface")
	include_directories( "$ENV{SQLANYWHERE}/sdk/c")
endif( UNIX)


if( UNIX)
	link_directories( "/usr/lib")
	link_directories( "/usr/local/lib")
	link_directories( "~/dld2-evulationkit-2.4.12/delivery/libraries/target")
	link_directories( "$ENV{SQLANYWHERE}/lib")

endif( UNIX)

#source files.
set( SRC
	main
)

#exe file.
add_executable( bijvangst ${SRC})

#output path.
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

if( UNIX)
	target_link_libraries( bijvangst dbcapi)

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

