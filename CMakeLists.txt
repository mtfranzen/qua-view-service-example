CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# CMAKE
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Project
project(quaview-distance-service)
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_PATCH 0)
set (VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# Requirements
find_package(Threads REQUIRED)
find_package (Luciconnect REQUIRED)

# Headers
include_directories (${PROJECT_SOURCE_DIR}/include)
include_directories (${LUCICONNECT_INCLUDE_DIR})

# Linker
link_directories (${PROJECT_SOURCE_DIR}/lib)
link_directories (${LUCICONNECT_ROOT}/lib)

# Compiler
SET(CMAKE_EXE_LINKER_FLAGS "-static")
if (WIN32)
    add_definitions (-D_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
else (WIN32)
    add_definitions (-std=c++14)
    add_definitions ("-Wall")
    add_definitions(-DASIO_STANDALONE)
    add_definitions(-static-libgcc -static-libstdc++)
endif (WIN32)

add_executable(quaview-distance-service "${CMAKE_SOURCE_DIR}/src/service.cc")
add_dependencies(quaview-distance-service luciconnect)
target_link_libraries (quaview-distance-service luciconnect ${CMAKE_THREAD_LIBS_INIT})
