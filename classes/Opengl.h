#ifndef __OPENGL_H__
#define __OPENGL_H__

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

class Opengl
{
  static Opengl* instance;
  std::string shaderVersion;

  Opengl(){}
public:
  static Opengl* getInstance()
  {
    if(!instance)
    {
      instance = new Opengl();
    }
    return instance;
  }
  void loadExtensions();
  void setShaderVersion(std::string v);
  GLuint createVAO(); // Automatically binds after creation

  void BindVAO(GLuint vaoid){glBindVertexArray(vaoid);} // just use 0 to unbind
  void BindVBO(GLuint vboid){glBindBuffer(GL_ARRAY_BUFFER,vboid);} // just use 0 to unbind
  GLuint createVertexAttribute(int size,void* pointer_to_data,int attrib_num,int epv);
  GLuint loadShader(std::string vShaderFileName,std::string fShaderFileName);
  GLuint CreateEBO(int size,void* pointer_to_data);
  void BindEBO(int eboid){glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboid);} // just use 0 to unbind
  void ClearScreen(float r,float g,float b);
  void DrawTriangles(GLsizei count);
  void UseShader(GLuint shaderID){glUseProgram(shaderID);}
  void CleanUp();
};

#endif /* end of include guard: __OPENGL_H__ */
