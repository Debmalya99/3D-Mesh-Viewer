#include "SFMLWindow.h"

SFMLWindow::SFMLWindow(std::string wintitle,InputManager* inSystem)
{
  windowTitle = wintitle;
  inputSystem = inSystem;
}

void SFMLWindow::Init()
{
  mRunning = true;
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.majorVersion = 3;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;
  mWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),windowTitle,sf::Style::Default,settings);
  mWindow.setFramerateLimit(60);
}

void SFMLWindow::HandleEvents()
{
  while(mWindow.pollEvent(mEvent))
  {
    switch(mEvent.type)
    {
      case sf::Event::Closed:
      mRunning = false;
      break;

      /*case sf::Event::MouseWheelMoved:

      break;*/

      default:
      break;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  inputSystem->inputMap["Left"] = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  inputSystem->inputMap["Right"] = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  inputSystem->inputMap["Up"] = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  inputSystem->inputMap["Down"] = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))  inputSystem->inputMap["Enter"] = true;
  }
}

void SFMLWindow::PreProcess()
{
  for(std::pair<std::string,bool> it:inputSystem->inputMap)
  {
    inputSystem->inputMap[it.first]= false;
  }
}

void SFMLWindow::Render()
{
  // Nothing really
}
void SFMLWindow::Update()
{
  // Nothing here as well. Thses functions
  // are there for emergency purposes. We will usually leave them empty
}
void SFMLWindow::swapBuffers()
{
  mWindow.display();
}
