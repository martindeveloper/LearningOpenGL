#version 410 core

layout(location = 0) in vec3 vertexPositionModelSpace;

void main ()
{
    gl_Position = vec4(vertexPositionModelSpace, 1.0f);
}