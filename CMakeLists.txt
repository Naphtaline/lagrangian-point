cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_BUILD_TYPE Release)

# project name
set(PROJECT_NAME LagrangianPoint)
project(${PROJECT_NAME})

# setup version numbers
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# all source files
include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB SRC "${PROJECT_SOURCE_DIR}/include/*.hpp" "${PROJECT_SOURCE_DIR}/src/*.cpp")

#Generate the shared library from the sources
#add_library(${PROJECT_NAME} SHARED ${SRC})

# demo
set(ENABLE_DEMO YES)

if(ENABLE_DEMO)
  add_subdirectory(demo)
endif()
