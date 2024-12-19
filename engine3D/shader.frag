#version 460 core

in vec3 vertexColor;
in vec3 vertexNormal;
in vec3 vertexPos;
out vec3 color;

uniform vec3 lightPos;
uniform vec3 lightColor;

uniform float ambientStrength;
uniform float specularStrength;
uniform int scatterStrength;
uniform float boostColor;

uniform bool ifWarnModel;
uniform float cutOff;
uniform float intensity;
uniform vec3 spotlightDir = normalize(vec3(0.0, -1.0, -1.0));

uniform bool useTexture;
uniform sampler2D usedTexture;

void main()
{  
    vec3 ambientResult = ambientStrength * lightColor;
    vec3 normalizedNormals = normalize(vertexNormal);
    vec3 diffuseRealDirection = normalize(lightPos - vertexPos);
    float preColorDiffuse = max(dot(normalizedNormals, diffuseRealDirection), 0.0);
    vec3 diffResult = preColorDiffuse * lightColor;
    vec3 viewDir = normalize(-vertexPos);
    vec3 reflectDir = reflect(-diffuseRealDirection, normalizedNormals);
    float preCalcSpecular = pow(max(dot(viewDir, reflectDir), 0.0), scatterStrength);
    vec3 specular = specularStrength * preCalcSpecular * lightColor;
    if (!ifWarnModel){
        if (useTexture) {
            vec4 textureColor = texture(usedTexture, vertexColor.xy);
            color = (ambientResult + diffResult + specular) * textureColor.rgb * boostColor;
        } else {
            color = (ambientResult + diffResult + specular) * boostColor * vertexColor;
        }
    } else { 
        vec3 lightDirection = normalize(vertexPos - lightPos);
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