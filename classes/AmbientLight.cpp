#include "AmbientLight.h"

AmbientLight::AmbientLight(float strength,glm::vec3  color)
{
  mStrength = strength;
  mColor = color;
}
void AmbientLight::Init()
{
  // Nothing at present I can think of putting here.
}

void AmbientLight::Process()
{
  Opengl::getInstance()->UseShader(mShaderID);  // Set the shader prior to calling this
  GLuint loc_amb_strength,loc_amb_light_color;
  loc_amb_strength = glGetUniformLocation(mShaderID,"ambientLight.Strength");
  loc_amb_light_color = glGetUniformLocation(mShaderID,"ambientLight.Color");
  if(loc_amb_strength == -1)
    std::cout<<"[AmbientLight::Process()::ERROR] can't find ambientLight.Strength"<<std::endl;
  if(loc_amb_light_color == -1)
    std::cout<<"[AmbientLight::Process()::ERROR] can't find ambientLight.Color"<<std::endl;
  glUniform1f(loc_amb_strength,mStrength);
  glUniform3f(loc_amb_light_color,mColor.x,mColor.y,mColor.z);
}
