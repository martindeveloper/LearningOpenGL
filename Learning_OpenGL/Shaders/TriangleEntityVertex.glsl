#version 410 core

layout(location = 0) in vec3 vertexPositionModelSpace;

void main()
{
    gl_Position.xyz = vertexPositionModelSpace;
    gl_Position.w = 1.0;
}