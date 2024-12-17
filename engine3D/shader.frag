#version 460 core

in vec3 vertexColor;
in vec3 fragNormal;
in vec3 fragPos;
out vec3 color;

uniform vec3 lightPos;
uniform vec3 lightColor;

uniform float ambientStrength;
uniform float specularStrength;
uniform int scatterStrength;
uniform float boostColor;

void main()
{
    vec3 ambientResult = ambientStrength * lightColor;
    vec3 norm = normalize(fragNormal);
    vec3 diffDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, diffDir), 0.0);
    vec3 diffResult = diff * lightColor;
    vec3 viewDir = normalize(-fragPos);
    vec3 reflectDir = reflect(-diffDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), scatterStrength);
    vec3 specular = specularStrength * spec * lightColor;  
    color = (ambientResult + diffResult + specular) * boostColor * vertexColor;
}