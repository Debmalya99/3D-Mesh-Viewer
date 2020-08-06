#include "Transform.h"

Transform::Transform()
{
  modelMat = glm::mat4(1.0f);
  TranslationMatrix = glm::mat4(1.0f);
  RotationMatrix = glm::mat4(1.0f);
  ScaleMatrix = glm::mat4(1.0f);
  PVMat = glm::mat4(1.0f);
}

void Transform::setPosition(glm::vec3 position)
{
  TranslationMatrix = glm::translate(glm::mat4(1.0f),position);
  mPosition = position;
}

void Transform::move(glm::vec3 offset)
{
  TranslationMatrix = glm::translate(TranslationMatrix,offset);
  mPosition = mPosition + offset;
}

void Transform::setScale(glm::vec3 scale_amount)
{
  ScaleMatrix = glm::scale(glm::mat4(1.0f),scale_amount);
}

void Transform::scale(glm::vec3 offset)
{
  ScaleMatrix = glm::scale(ScaleMatrix,offset);
}

void Transform::ResetTransform()
{
  modelMat = glm::mat4(1.0f);
  TranslationMatrix = glm::mat4(1.0f);
  RotationMatrix = glm::mat4(1.0f);
  ScaleMatrix = glm::mat4(1.0f);
}

void Transform::ApplyTransform(GLuint shaderID,unsigned int mode)
{
  if(shaderID < 0)  std::cout <<"[Transform::Error] Shader not compiled and linked"<<std::endl;
  if(mode == TRM_MODEL)
  {
    modelMat = TranslationMatrix*RotationMatrix*ScaleMatrix;
    GLuint modelMat_loc = glGetUniformLocation(shaderID,"modelMat");
    if(modelMat_loc == -1)  std::cout<<"[Transform::Error] Can't find modelMat in Vertex Shader"<<std::endl;
    glUniformMatrix4fv(modelMat_loc,1,GL_FALSE,glm::value_ptr(modelMat));
  }
  else if(mode == TRM_CAMERA)
  {
    GLuint pviewmat_loc = glGetUniformLocation(shaderID,"projViewMat");
    if(pviewmat_loc == -1)  std::cout<<"[Transform::Error] Can't find projViewMat in Vertex Shader"<<std::endl;
    glUniformMatrix4fv(pviewmat_loc,1,GL_FALSE,glm::value_ptr(PVMat));
  }
}

void Transform::LookAt(glm::vec3 target,glm::vec3 up)
{
  PVMat = glm::lookAt(mPosition,target,up);
  PVMat = glm::perspective(glm::radians(mFoV),(float)SCREEN_WIDTH/SCREEN_HEIGHT,NEAR,FAR) * PVMat;
  PVMat = RotationMatrix*PVMat; // if any rotations are applied
}


void Transform::setRotation(glm::vec3 axis,float angle_in_radians)
{
  RotationMatrix = glm::rotate(glm::mat4(1.0f),glm::radians(angle_in_radians),axis);
}

void Transform::rotate(glm::vec3 axis,float angle_in_radians)
{
  RotationMatrix = glm::rotate(RotationMatrix,glm::radians(angle_in_radians),axis);
}
