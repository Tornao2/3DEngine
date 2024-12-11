#version 460 core

in vec4 vertexColor;
in vec4 fragNormal;
out vec4 color;

uniform vec4 lightDir;

void main()
{
    float diff = max(dot(normalize(fragNormal), normalize(lightDir)), 0.0);
    color = vec4(vertexColor.rgb * diff, vertexColor.a);
}