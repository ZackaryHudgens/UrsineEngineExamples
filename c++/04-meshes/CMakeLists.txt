project(04-meshes)
file(GLOB 04_SOURCES *.cpp)

add_executable(meshes ${04_SOURCES})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include the resource compiler.
include("cmake/CMakeRC.cmake")

# Create a library containing the shader resources.
cmrc_add_resource_library(ShaderLib resources/shaders/SolidColor.frag
                                    resources/shaders/SolidColor.vert
                                    resources/shaders/PerVertexColor.frag
                                    resources/shaders/PerVertexColor.vert
                                    resources/shaders/Texture.vert
                                    resources/shaders/Texture.frag)

target_link_libraries(meshes PUBLIC
                      ${URSINE_LIBRARIES}
                      ShaderLib)
target_include_directories(meshes PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS meshes DESTINATION ${CPP_INSTALL_DIR}/04-meshes)
install(DIRECTORY resources DESTINATION ${CPP_INSTALL_DIR}/04-meshes)
