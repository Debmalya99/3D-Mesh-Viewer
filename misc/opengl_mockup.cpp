int main(int argc, char const *argv[]) {
  IWindow* mWin = new SFMLWindow("Our game");
  mWin->Init();
  mWin->MainLoop();
  mWin->CleanUp();
  delete(mWin);
  return 0;
}


// -------------CREATING GAMEOBJECTS ------------------------//
IGameObject* player = new Player(); // This class itself will have all the definitions;
IGameObject* prop = new TreasureChest();
IGameObject* camera = new Camera();

//  ---------------------MANAGING OPENGL  -------------------------//
// This will be a singleton
Opengl::getInstance()->loadExtensions(); // Use glew or glad whatever you need
Opengl::getInstance()->setShaderVersion("#version 330");
GLuint vao = Opengl::getInstance()->createVAO();
Opengl::getInstance()->BindVAO(vao);
GLuint vbo_vert = Opengl::getInstance()->createVBO(GL_ARRAY_BUFFER,vertices);
GLuint vbo_vert = Opengl::getInstance()->createVBO(GL_ELEMENT_ARRAY_BUFFER);

// -----------------------  MANAGING THE GAME AND WINDOW  -------------------//
IWindow* sfml_window = new SFMLWindow("Our Awesome Game");
IGame* my_game = new OurGame(sfml_window);

// -------------------- CAMERA -----------------//
Camera* cam = new Camera(45.0f);
Camera->transform->setPosition(glm::vec3(4,3,3));
Camera->transform->LookAt(glm::vec3(0,0,0),glm::vec3(0,1,0));
Camera->Init();
Camera->Process();
// ----------------------------------------------------///


////////// ------------------INPUT ------------------//////////////
IInput* in1 = new SFMLInput();


///////////////// ---------------- MODEL -----------------//////////////
IGameObject* monkey;
//later on
monkey = new Model("path/to/model/filename.ext");
monkey->Init();
// In the loop
cam->SetShader(monkey->GetShader());
monkey->Process();
cam->Process(inputSystem);

//------------------------LIGHTING-------------------//
IGameObject *alight,*plight = new AmbientLight(0.01f),new PointLight(2.0f,glm::vec3(2,5,2));
// Constructor specifies the strength and location (for PointLight)
alight->Init();
plight->Init();

// In the game loop
cam->SetShader(alight->GetShader());
alight->Process(inputSystem);

cam->SetShader(plight->GetShader());
plight->Process(inputSystem);
