cmake_minimum_required(VERSION 3.2)

project(cpploxInterpreter)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14") 
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (output_dir "${PROJECT_SOURCE_DIR}/bin/")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${output_dir})

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (cpploxInterpreter ${source_files})