cmake_minimum_required(VERSION 3.10)
project(UrsineEngineExamples)

# Exports compile commands as a .json file; some text editors use
# this file for syntax highlighting.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(UrsineEngine REQUIRED)

set(EXAMPLES_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install)
set(PROJECTS_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/projects)

add_subdirectory(01-hello-world)
add_subdirectory(02-gameobjects-and-components)
add_subdirectory(03-signals)
add_subdirectory(04-meshes)
add_subdirectory(05-camera-and-3d-objects)

add_subdirectory(projects/deck-of-illusions)
