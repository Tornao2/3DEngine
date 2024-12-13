#version 460 core

in vec4 vertexColor;
in vec4 fragNormal;
out vec4 color;

uniform vec4 lightDir;
uniform vec4 ambientDir;

void main()
{
    vec4 norm = normalize(fragNormal);
    vec4 light = normalize(lightDir);
    float diff = max(dot(norm, light), 0.0);
    vec4 ambient = ambientDir * (1.0 - diff);
    color = vec4(vertexColor.rgb * diff, vertexColor.a) + ambient;
}