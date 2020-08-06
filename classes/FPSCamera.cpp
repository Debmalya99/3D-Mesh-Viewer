#include "FPSCamera.h"

void FPSCamera::Init()
{

  proj = glm::perspective(glm::radians(mFoV),(float)SCREEN_WIDTH/SCREEN_HEIGHT,NEAR,FAR);
}

void FPSCamera::Process(InputManager* inputSystem)
{
  if(inputSystem->isActionPressed("Up"))
  {
    position = position - Speed * front;
  }
  if(inputSystem->isActionPressed("Down"))
  {
    position = position + Speed * front;
  }
  if(inputSystem->isActionPressed("Left"))
  {
    position = position + glm::normalize(glm::cross(front,up)) * Speed;
  }

  if(inputSystem->isActionPressed("Right"))
  {
    position = position - glm::normalize(glm::cross(front,up)) * Speed;
  }

  if(inputSystem->isActionPressed("Enter"))
  {
    inputSystem->GetActionList();
  }

  view = glm::lookAt(position,position + front,up);
  PV = proj * view;

  GLuint pviewmat_loc = glGetUniformLocation(mShaderID,"projViewMat");
  if(pviewmat_loc == -1)  std::cout<<"[FPSCamera::Error] Can't find projViewMat in Vertex Shader"<<std::endl;
  glUniformMatrix4fv(pviewmat_loc,1,GL_FALSE,glm::value_ptr(PV));

  GLuint posVector_loc = glGetUniformLocation(mShaderID,"viewPos");
  //if(posVector_loc == -1)  std::cout<<"[FPSCamera::Error] Can't find viewPos in Fragment Shader"<<std::endl;
  glUniform3f(posVector_loc,position.x,position.y,position.z);
}
