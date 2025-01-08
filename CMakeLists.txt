cmake_minimum_required(VERSION 3.14)
project(cpp-project CXX)

# Collect all source files (including Catch2)
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
set(SRC_FILES ${SRC_FILES} "${CMAKE_SOURCE_DIR}/include/catch_amalgamated.cpp")

# Create a single executable
add_executable(cpp-project ${SRC_FILES})

# Include directories
target_include_directories(cpp-project PUBLIC "${CMAKE_SOURCE_DIR}/include")

# Set C++ standard
set_target_properties(cpp-project PROPERTIES CXX_STANDARD 23)
