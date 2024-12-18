#version 460 core

flat in vec3 vertexColor;
flat in vec3 fragNormal;
in vec3 fragPos;
out vec3 color;

uniform vec3 lightPos;
uniform vec3 lightColor;

uniform float ambientStrength;
uniform float specularStrength;
uniform int scatterStrength;
uniform float boostColor;

uniform bool warnModel;
uniform float cutOff;
uniform float intensity;
uniform vec3 spotlightDir = normalize(vec3(0.0, -1.0, -1.0));

uniform bool useTexture;
uniform sampler2D usedTexture;

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
    if (!warnModel){
        if (useTexture) {
            vec4 textureColor = texture(usedTexture, vertexColor.xy);
            color = (ambientResult + diffResult + specular) * textureColor.rgb * boostColor;
        } else {
            color = (ambientResult + diffResult + specular) * boostColor * vertexColor;
        }
    } else { 
        vec3 lightDirection = normalize(fragPos - lightPos);
        float theta = dot(lightDirection, spotlightDir);
        float spotlightIntensity = pow(theta, intensity);
        if (useTexture) {
            vec4 textureColor = texture(usedTexture, vertexColor.xy);
            color = (ambientResult + diffResult + specular) * spotlightIntensity * boostColor * textureColor.rgb;
        } else {
            color = (ambientResult + diffResult + specular) * spotlightIntensity * boostColor * vertexColor;
        }
    }
}