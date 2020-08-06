#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Opengl.h"
#include <iostream>
#include "../config.h"

// Transform modes//
#define TRM_MODEL 0
#define TRM_CAMERA 1

class Transform
{
  glm::mat4 modelMat; // We will use the same name in the shader
  glm::mat4 TranslationMatrix,RotationMatrix,ScaleMatrix;
  glm::mat4 PVMat;
  glm::vec3 mPosition;
  float mFoV;
public:
  Transform();
  //methods:
  void setPosition(glm::vec3 position);
  void move(glm::vec3 offset);
  void setRotation(glm::vec3 axis,float angle_in_radians); // We'll do this later
  void rotate(glm::vec3 axis,float angle_in_radians);
  void setScale(glm::vec3 scale_amount);
  void scale(glm::vec3 offset);
  void scale(float amt){ScaleMatrix = glm::scale(ScaleMatrix,glm::vec3(amt,amt,amt));}  // Uniform scaling
  void ResetTransform();
  void ApplyTransform(GLuint shaderID,unsigned int mode);
  void LookAt(glm::vec3 target,glm::vec3 up = glm::vec3(0,1,0));
  void setFoV(float fov){mFoV = fov;}
  glm::vec3 getPosition(){return mPosition;}
};

#endif /* end of include guard: __TRANSFORM_H__ */
