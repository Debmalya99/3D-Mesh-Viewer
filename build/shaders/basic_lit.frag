
in vec3 Normal,FragPos;

struct AmbientLight
{
  float Strength;
  vec3 Color;

};

struct PointLight
{
  float Strength;
  vec3 Color;
  vec3 Position;
};

uniform AmbientLight ambientLight;
uniform PointLight pointLight;

uniform vec3 viewPos;

//int levels = 15;

out vec4 color;
void main()
{
  // Diffuse
  vec3 norm = normalize(Normal);
  vec3 lightDir = normalize(pointLight.Position - FragPos);
  float diff = max(dot(norm,lightDir),0.0);
  vec3  diff_result = diff * pointLight.Color;

  //Specular
  float specularStrength = 0.2f;
  float shininess = 100;
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-lightDir,norm);
  float spec = pow(max(dot(viewDir,reflectDir),0.0),shininess);
  vec3 spec_result = specularStrength * spec * pointLight.Color;

  // Ambient
  vec3 ambient_result = ambientLight.Strength * ambientLight.Color;

  //Output

  vec3 result = (diff_result + ambient_result + spec_result)*vec3(0.8, 0.1, 0.6);
  /*vec3 level = floor(levels*result);
  result = level/levels;*/
  color = vec4(result,1);
}
