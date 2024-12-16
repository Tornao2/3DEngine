#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;
layout(location = 2) in vec4 color;

uniform mat4 projectionMatrix = mat4(1.0f);
uniform mat4 viewMatrix = mat4(1.0f);

out vec4 vertexColor;
out vec4 fragNormal;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * position;
    vertexColor = color;
    fragNormal = normal;
}