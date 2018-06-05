cmake_minimum_required (VERSION 3.10)
# Project Name
project (SudokuSolver)
subdirs(src)

# Version number
set (SudokuSolver_VERSION_MAJOR 2)
set (SudokuSolver_VERSION_MINOR 0)
set (SudokuSolver_VERSION_PATCH 0)

# Enable c++11 standard
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3")

# Set output folder
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
