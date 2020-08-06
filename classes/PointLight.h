#ifndef __POINT_LIGHT_H__
#define __POINT_LIGHT_H__

#include "../interfaces/IGameObject.h"
#include "Transform.h"
#include "Model.h"  // To render a small model of the light itself

class PointLight : public IGameObject
{
  glm::vec3 mColor;
  glm::vec3 mPosition;  // I chose not to use the Transform class here
  float mStrength;
  GLuint renderShader;  // For rendering the model of the Light itself;
  Model* mModel;
public:
  PointLight(glm::vec3 position,glm::vec3 color = glm::vec3(1.0f,1.0f,1.0f),float strength = 1.0f);
  void Init();
  void Process();
  GLuint GetShader(){return renderShader;}
};

#endif /* end of include guard: __POINT_LIGHT_H__ */
