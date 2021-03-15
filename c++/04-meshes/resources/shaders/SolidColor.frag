#version 330 core

// Output variables
out vec4 fragColor;

// Uniform variables
uniform vec3 solidColor;

void main()
{
  fragColor = vec4(solidColor, 1.0);
}
