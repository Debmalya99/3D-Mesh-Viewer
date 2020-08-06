#ifndef __GRID_H__
#define __GRID_H__

#include "Model.h"
#include "../interfaces/IGameObject.h"
#include "Transform.h"

class Grid : public IGameObject
{
public:
  Model* grid_mesh;
  Transform transform;
  void Init()
  {
    grid_mesh = new Model("models/grid.obj");
    mShaderID = Opengl::getInstance()->loadShader("shaders/basic.vert","shaders/grid.frag");
    grid_mesh->SetShader(mShaderID);
  }
  void Process()
  {
    //Opengl::getInstance()->UseShader(mShaderID);
    //transform.ApplyTransform(mShaderID,TRM_MODEL);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    grid_mesh->Process();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  }
};


#endif /* end of include guard: __GRID_H__ */
