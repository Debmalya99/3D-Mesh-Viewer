#include <SFML/Window.hpp>
#include "classes/SimpleGame.h"
#include "SFML-backend/SFMLWindow.h"
#include "classes/InputManager.h"

int main(int argc,char* argv[])
{

  InputManager* simple_input = new InputManager();
  IWindow* sfml_window = new SFMLWindow("3D Mesh Viewer[Finished Project]",simple_input);

  IGame* my_game = new SimpleGame(sfml_window);
  my_game->inputSystem = simple_input;

  my_game->Run();

  my_game->CleanUp();
  return 0;
}
