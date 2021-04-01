#version 330 core

// Vertex Attribute Array/Object
layout (location = 0) in vec3 aPosition;

// Uniform variables
uniform mat4 modelMatrix;

void main()
{
  gl_Position = modelMatrix * vec4(aPosition, 1.0);
}
