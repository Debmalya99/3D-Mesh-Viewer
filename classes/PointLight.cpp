#include "PointLight.h"


PointLight::PointLight(glm::vec3 position,glm::vec3 color,float strength)
{
  mPosition = position;mColor = color;mStrength = strength;
  
}

void PointLight::Init()
{
  mModel = new Model("models/light_cube.obj");
  renderShader = Opengl::getInstance()->loadShader("shaders/lightRender.vert","shaders/lightRender.frag");
  mModel->SetShader(renderShader);
  mModel->transform.setPosition(mPosition);
  mModel->Init();
}

void PointLight::Process()
{
  Opengl::getInstance()->UseShader(mShaderID);
  GLuint loc_strength,loc_color,loc_position;
  loc_strength = glGetUniformLocation(mShaderID,"pointLight.Strength");
  loc_color = glGetUniformLocation(mShaderID,"pointLight.Color");
  loc_position = glGetUniformLocation(mShaderID,"pointLight.Position");
  if(loc_strength == -1)
    std::cout<<"[PointLight::Process()::ERROR] pointLight.Strength not found"<<std::endl;
  if(loc_color == -1)
    std::cout<<"[PointLight::Process()::ERROR] pointLight.Color not found"<<std::endl;
  if(loc_position == -1)
    std::cout<<"[PointLight::Process()::ERROR] pointLight.Position not found"<<std::endl;

  glUniform1f(loc_strength,mStrength);
  glUniform3f(loc_position,mPosition.x,mPosition.y,mPosition.z);
  glUniform3f(loc_color,mColor.x,mColor.y,mColor.z);

  Opengl::getInstance()->UseShader(renderShader);
  GLuint loc_rs_color = glGetUniformLocation(renderShader,"lightColor");
  if(loc_rs_color == -1) std::cout<<"[PointLight::Process()::ERROR in rendering light] Uniform lightColor not found"<<std::endl;
  glUniform3f(loc_rs_color,mColor.x,mColor.y,mColor.z);
  mModel->Process();

}
