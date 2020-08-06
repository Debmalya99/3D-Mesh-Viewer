#ifndef __FPSCAMERA_H__
#define __FPSCAMERA_H__

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Opengl.h"
#include <iostream>
#include "../config.h"
#include "InputManager.h"

class FPSCamera
{
  glm::mat4 view,proj,PV;
  GLuint mShaderID;
  float mFoV;
public:
  float Speed;
  glm::vec3 position;
  glm::vec3 front;
  glm::vec3 up;
  FPSCamera(GLuint shaderID,float FoV = 45.0f){
    mShaderID = shaderID;
    view = glm::mat4(1.0f);
    proj = glm::mat4(1.0f);
    mFoV = FoV;
    position = glm::vec3(0.0f,0.0f,3.0f);
    front = glm::vec3(0,0,-1.0f);
    up = glm::vec3(0.0f,1.0f,0.0f);
    Speed = 0.05f;
  }
  void SetShader(GLuint shaderID){mShaderID = shaderID;}
  void Init();
  void Process(InputManager* inputSystem);
};

#endif /* end of include guard: __FPSCAMERA_H__ */
