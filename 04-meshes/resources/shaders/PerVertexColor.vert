#version 330 core

// Vertex Attribute Array/Object
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aVertexColor;

// Output variables
out vec3 vertexColor;

// Uniform variables
uniform mat4 modelMatrix;

void main()
{
  vertexColor = aVertexColor;

  gl_Position = modelMatrix * vec4(aPosition, 1.0);
}
