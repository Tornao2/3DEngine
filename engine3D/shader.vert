#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
out vec4 vertexColor;

void main()
{
    gl_Position = projectionMatrix * modelViewMatrix * vec4(position);
    vertexColor = color;
}