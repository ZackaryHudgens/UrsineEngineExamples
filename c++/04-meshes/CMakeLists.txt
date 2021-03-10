project(04-meshes)
file(GLOB 04_SOURCES *.cpp)

add_executable(meshes ${04_SOURCES})
target_link_libraries(meshes PUBLIC
                      ${URSINE_LIBRARIES})
target_include_directories(meshes PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS meshes DESTINATION ${CPP_INSTALL_DIR}/04-meshes)
