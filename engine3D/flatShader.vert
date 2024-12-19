#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;
layout(location = 2) in vec4 color;

uniform mat4 projectionMatrix = mat4(1.0f);
uniform mat4 viewMatrix = mat4(1.0f);

flat out vec3 vertexColor;
flat out vec3 vertexNormal;
out vec3 vertexPos;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * position;
    vertexColor = color.xyz;
    vertexNormal = normal.xyz;
    vertexPos = position.xyz;
}