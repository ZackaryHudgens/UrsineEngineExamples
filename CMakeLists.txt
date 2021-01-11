cmake_minimum_required(VERSION 3.10)
project(UrsineEngineExamples)

# Exports compile commands as a .json file; some text editors use
# this file for syntax highlighting.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPP_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/c++)

# Set example options.
# Optionally build the C++ examples.
option(BUILD_CPP_EXAMPLES "Build the C++ examples." ON)

if(BUILD_CPP_EXAMPLES)
    add_subdirectory(c++)
endif()
