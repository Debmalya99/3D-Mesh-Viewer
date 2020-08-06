#include "SimpleGame.h"

void SimpleGame::InitGame()
{
  Opengl::getInstance()->loadExtensions();
  Opengl::getInstance()->setShaderVersion("330");
  my_shader = Opengl::getInstance()->loadShader("shaders/basic.vert","shaders/basic_lit.frag");

  monkey_model = new Model("models/Elk-scene.obj");
  monkey_model->transform.scale(2.0f);
  //monkey_model->transform.setPosition(glm::vec3(0.0f,4.f,1.0f));
  /*monkey_model->transform.setRotation(glm::vec3(0,0,1),90.0f);
  monkey_model->transform.setRotation(glm::vec3(1,0,0),90.0f);*/
  monkey_model->SetShader(my_shader);
  monkey_model->Init();

  cam = new FPSCamera(my_shader);
  cam->Speed = -0.05f;
  cam->position = glm::vec3(4,2,3);
  cam->front = glm::vec3(-4,-2,-3);
  cam->Init();

  grid = new Grid();
  grid->Init();

  ambLight = new AmbientLight(0.1f,glm::vec3(1.0f,1.0f,1.0f));
  ambLight->SetShader(my_shader);
  ambLight->Init();

  pLight = new PointLight(glm::vec3(8,8,4));
  pLight->SetShader(my_shader);
  pLight->Init();

}

void SimpleGame::ProcessGame()
{
  Opengl::getInstance()->ClearScreen(0.05,0.05,0.05);


  cam->SetShader(my_shader);
  monkey_model->Process();
  cam->Process(inputSystem);

  cam->SetShader(grid->GetShader());
  grid->Process();
  cam->Process(inputSystem);

  ambLight->Process();
  cam->SetShader(pLight->GetShader());
  pLight->Process();
  cam->Process(inputSystem);
}

void SimpleGame::CleanUp()
{
  Opengl::getInstance()->CleanUp();
  delete(cam);
  delete(grid);
  delete(monkey_model);
}
