#version 330 core

// Vertex Attribute Array/Object
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aVertexColor;

// Output variables
out vec3 vertexColor;

void main()
{
  vertexColor = aVertexColor;

  gl_Position = vec4(aPosition, 1.0);
}
