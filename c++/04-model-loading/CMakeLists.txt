project(04-model-loading)
file(GLOB 04_SOURCES *.cpp)
file(GLOB 04_RESOURCES resources/*)

add_executable(model-loading ${04_SOURCES})
target_link_libraries(model-loading PUBLIC
                      ${URSINE_LIBRARIES})
target_include_directories(model-loading PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS model-loading DESTINATION ${CPP_INSTALL_DIR}/04-model-loading)
install(FILES ${04_RESOURCES} DESTINATION ${CPP_INSTALL_DIR}/04-model-loading)
