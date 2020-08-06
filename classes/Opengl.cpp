#include "Opengl.h"

Opengl* Opengl::instance = nullptr;

void Opengl::loadExtensions()
{
  glewExperimental = GL_TRUE;
  if(glewInit()!=GLEW_OK)
  {
    std::cout<<"[Opengl::Error] Failed to load Opengl using GLEW"<<std::endl;
  }
}

void Opengl::setShaderVersion(std::string v)
{
  shaderVersion = "#version "+ v + "\n";
}

GLuint Opengl::createVAO()
{
  GLuint vao_id;
  glGenVertexArrays(1,&vao_id);
  glBindVertexArray(vao_id);
  return vao_id;
}

GLuint Opengl::createVertexAttribute(int size,void* pointer_to_data,int attrib_num,int epv)
{
  // usage mode : GL_ARRAY_BUFFER
  // size : Size of buffer in bytes
  // pointer to data is the pointer to data duh!
  // epv : element per vertex
  // attrib_num : location of attribute in shader
  GLenum vbo;
  glGenBuffers(1,&vbo);
  glBindBuffer(GL_ARRAY_BUFFER,vbo);
  glBufferData(GL_ARRAY_BUFFER,size,pointer_to_data,GL_STATIC_DRAW);
  glEnableVertexAttribArray(attrib_num);
  glVertexAttribPointer(attrib_num,epv,GL_FLOAT,GL_FALSE,0,0);
  return vbo;
}

GLuint  Opengl::loadShader(std::string vShaderFileName,std::string fShaderFileName)
{
  std::string vShaderCode, fShaderCode;
  std::ifstream vFile(vShaderFileName),fFile(fShaderFileName);
  if(!vFile)  std::cout<<"[loadShader::Error] "<<vShaderFileName<<" not found"<<std::endl;
  if(!fFile)  std::cout<<"[loadShader::Error] "<<fShaderFileName<<" not found"<<std::endl;
  std::ostringstream vShaderStream,fShaderStream;
  vShaderStream << vFile.rdbuf(); fShaderStream << fFile.rdbuf();
  vShaderCode = shaderVersion + vShaderStream.str();
  fShaderCode = shaderVersion + fShaderStream.str();

  char infoLog[512];

  GLuint vShader,fShader,shaderProgram;
  vShader = glCreateShader(GL_VERTEX_SHADER);
  fShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char* _vShaderCode = vShaderCode.c_str();
  const char* _fShaderCode = fShaderCode.c_str();

  glShaderSource(vShader,1,&_vShaderCode,NULL);
  glShaderSource(fShader,1,&_fShaderCode,NULL);

  glCompileShader(vShader); glCompileShader(fShader);

  int success;
  glGetShaderiv(vShader,GL_COMPILE_STATUS,&success);
  if(!success)
  {
    glGetShaderInfoLog(vShader,512,NULL,infoLog);
    std::cout<<"Vertex shader "<<vShaderFileName<<" compilation failed"<<std::endl;
    std::cout<<"Reason : "<<infoLog<<std::endl;
  }

  glGetShaderiv(fShader,GL_COMPILE_STATUS,&success);
  if(!success)
  {
    glGetShaderInfoLog(fShader,512,NULL,infoLog);
    std::cout<<"Fragment shader "<<fShaderFileName<<" compilation failed"<<std::endl;
    std::cout<<"Reason : "<<infoLog<<std::endl;
  }

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram,vShader);
  glAttachShader(shaderProgram,fShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
  if(!success)
  {
    glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
    std::cout<<"Program linking failed"<<std::endl;
    std::cout<<"Reason : "<<infoLog<<std::endl;
  }
  glDeleteShader(vShader); glDeleteShader(fShader);
  return shaderProgram;
}


GLuint Opengl::CreateEBO(int size,void* pointer_to_data)
{
  GLuint ebo_id;
  glGenBuffers(1,&ebo_id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo_id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,pointer_to_data,GL_STATIC_DRAW);
  return ebo_id;
}


void Opengl::ClearScreen(float r,float g,float b)
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glClearColor(r,g,b,1);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Opengl::DrawTriangles(GLsizei count)
{
  // count : number of traingles to draw
  glDrawElements(GL_TRIANGLES,3*count,GL_UNSIGNED_INT,0);
}


void Opengl::CleanUp()
{
  if(instance!=nullptr)
  {
    delete(instance);
  }
}
