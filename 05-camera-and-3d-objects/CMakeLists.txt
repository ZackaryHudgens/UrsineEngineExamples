project(05-camera-and-3d-objects)
file(GLOB 05_SOURCES *.cpp)

add_executable(camera-and-3d-objects ${05_SOURCES})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include the resource compiler.
include("cmake/CMakeRC.cmake")

# Create a library containing the shader resources.
cmrc_add_resource_library(ShaderLib_05 resources/shaders/SolidColor.frag
                                       resources/shaders/SolidColor.vert
                                       resources/shaders/PerVertexColor.frag
                                       resources/shaders/PerVertexColor.vert
                                       resources/shaders/Texture.frag
                                       resources/shaders/Texture.vert)

target_link_libraries(camera-and-3d-objects PUBLIC
                      ${URSINE_LIBRARIES}
                      ShaderLib_05)
target_include_directories(camera-and-3d-objects PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS camera-and-3d-objects DESTINATION ${EXAMPLES_INSTALL_DIR}/05-camera-and-3d-objects)
install(DIRECTORY resources DESTINATION ${EXAMPLES_INSTALL_DIR}/05-camera-and-3d-objects)
