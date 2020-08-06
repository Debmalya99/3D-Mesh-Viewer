#ifndef __IGAME_H__
#define __IGAME_H__

#include "IWindow.h"
#include "../classes/InputManager.h"

class IGame
{
protected:
  IWindow* mWindow;
public:
  // Derived classes will have a constructor of the form Constructor(pointer to IWindow)
  virtual void InitGame() = 0;
  virtual void ProcessGame() = 0;
  InputManager* inputSystem;
  void Run()
  {
    mWindow->Init();
    InitGame();
    while(mWindow->isRunning())
    {
      mWindow->PreProcess();
      mWindow->HandleEvents();

      mWindow->Update();mWindow->Render();
      ProcessGame();
      mWindow->swapBuffers();
    }
    mWindow->CleanUp();
  }
  virtual void CleanUp() = 0;
};

#endif /* end of include guard: __IGAME_H__ */
