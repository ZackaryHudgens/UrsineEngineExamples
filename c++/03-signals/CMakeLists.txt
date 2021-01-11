project(03-signals)
file(GLOB 03_SOURCES *.cpp)

add_executable(signals ${03_SOURCES})
target_link_libraries(signals PUBLIC
                      ${URSINE_LIBRARIES})
target_include_directories(signals PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS signals DESTINATION ${CPP_INSTALL_DIR}/03-signals)
