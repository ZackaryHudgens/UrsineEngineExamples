#version 330 core

// Input variables
in vec3 vertexColor;
in vec2 texCoords;

// Output variables
out vec4 fragColor;

// Uniform variables
uniform sampler2D texSampler;

void main()
{
  fragColor = texture(texSampler, texCoords);
}
