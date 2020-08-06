#ifndef __SIMPLE_GAME_H__
#define __SIMPLE_GAME_H__

#include "../interfaces/IGame.h"
#include "../interfaces/IGameObject.h"
#include "Opengl.h"
#include "FPSCamera.h"
#include "Transform.h"
#include "Model.h"
#include "Grid.h"
#include "AmbientLight.h"
#include "PointLight.h"

class SimpleGame : public IGame
{
  GLuint my_shader;

  FPSCamera* cam;
  Transform trig_trans;
  IGameObject *monkey_model, *grid, *ambLight,*pLight;
public:
  SimpleGame(IWindow* ptr_window)
  {
    mWindow = ptr_window;

  }
  void InitGame();
  void ProcessGame();
  void CleanUp();
};

#endif /* end of include guard: __SIMPLE_GAME_H__ */
