#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;
layout(location = 2) in vec4 color;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

out vec4 vertexColor;
out vec4 fragNormal;

void main()
{
    gl_Position = projectionMatrix * modelViewMatrix * position;
    vertexColor = color;
    fragNormal = normal;
}