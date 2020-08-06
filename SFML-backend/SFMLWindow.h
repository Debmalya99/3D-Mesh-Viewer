#ifndef  __SFML_WINDOW__
#define __SFML_WINDOW__

#include <SFML/Window.hpp>
#include "../interfaces/IWindow.h"
#include <iostream>

class SFMLWindow : public IWindow
{
  std::string windowTitle;
  sf::Window mWindow;
  sf::Event mEvent;

public:
  SFMLWindow(std::string wintitle,InputManager* inSystem);
  void Init();
	void HandleEvents();
	void Render();
	void Update();
	void swapBuffers();
  void CleanUp(){}
  void PreProcess();

};

#endif /* end of include guard: __SFML_WINDOW__ */
