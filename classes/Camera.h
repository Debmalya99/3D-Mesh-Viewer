#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../interfaces/IGameObject.h"
#include "Transform.h"

class Camera : public IGameObject
{
public:
  Camera(GLuint shaderID){
    mShaderID = shaderID;
  }
  Transform transform;
  void Init();
  void Process();
};

#endif /* end of include guard: __CAMERA_H__ */
