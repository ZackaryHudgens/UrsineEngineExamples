project(deck-of-illusions)
file(GLOB DECK_SOURCES *.cpp)

add_executable(deck-of-illusions ${DECK_SOURCES})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include the resource compiler.
include("cmake/CMakeRC.cmake")

# Create a library containing the shader resources.
cmrc_add_resource_library(ShaderLib_Deck resources/shaders/CardShader.frag
                                         resources/shaders/CardShader.vert
                                         resources/shaders/CardVanishingShader.frag
                                         resources/shaders/CardVanishingShader.vert)

target_link_libraries(deck-of-illusions PUBLIC
                      ${URSINE_LIBRARIES}
                      ShaderLib_Deck)
target_include_directories(deck-of-illusions PUBLIC
                           ${URSINE_INCLUDE_DIRS})

install(TARGETS deck-of-illusions DESTINATION ${PROJECTS_INSTALL_DIR}/deck-of-illusions)
install(DIRECTORY resources DESTINATION ${PROJECTS_INSTALL_DIR}/deck-of-illusions)
