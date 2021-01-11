project(02-gameobjects-and-components)
file(GLOB 02_SOURCES *.cpp)

add_executable(gameobjects-and-components ${02_SOURCES})
target_link_libraries(gameobjects-and-components PUBLIC
                      ${URSINE_LIBRARIES})
target_include_directories(gameobjects-and-components PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS gameobjects-and-components DESTINATION ${CPP_INSTALL_DIR}/02-gameobjects-and-components)
