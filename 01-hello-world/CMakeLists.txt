project(01-hello-world)
file(GLOB 01_SOURCES *.cpp)

add_executable(hello-world ${01_SOURCES})
target_link_libraries(hello-world PUBLIC
                      ${URSINE_LIBRARIES})
target_include_directories(hello-world PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS hello-world DESTINATION ${EXAMPLES_INSTALL_DIR}/01-hello-world)
