#ifndef __AMBIENT_LIGHT_H__
#define __AMBIENT_LIGHT_H__

#include "../interfaces/IGameObject.h"

class AmbientLight : public IGameObject
{
  float mStrength;
  glm::vec3 mColor;
public:
  AmbientLight(float strength,glm::vec3 color);
  void Init();
  void Process();
};


#endif /* end of include guard: __AMBIENT_LIGHT_H__ */
