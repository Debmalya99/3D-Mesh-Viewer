#include "Mesh.h"

Mesh::Mesh(std::vector<float> a_vertices,std::vector<float> a_texcoord,std::vector<float> a_normals,std::vector<GLuint> a_indices)
{
  this->vertices = a_vertices;
  this->normals = a_normals;
  this->texcoords = a_texcoord;
  this->indices = a_indices;

  SetupMesh();
}

void Mesh::SetupMesh()
{
  VAO = Opengl::getInstance()->createVAO();
  Opengl::getInstance()->BindVAO(VAO);
  Opengl::getInstance()->createVertexAttribute(sizeof(float)*vertices.size(),&vertices[0],0,3);
  Opengl::getInstance()->createVertexAttribute(sizeof(float)*texcoords.size(),&texcoords[0],1,2);
  Opengl::getInstance()->createVertexAttribute(sizeof(float)*normals.size(),&normals[0],2,3);
  EBO = Opengl::getInstance()->CreateEBO(sizeof(GLuint)*indices.size(),&indices[0]);
  Opengl::getInstance()->BindVAO(0);
  Opengl::getInstance()->BindEBO(0);
  Opengl::getInstance()->BindVBO(0);
}

void Mesh::Draw(GLuint shaderID)
{
  Opengl::getInstance()->UseShader(shaderID);
  Opengl::getInstance()->BindVAO(VAO);
  Opengl::getInstance()->DrawTriangles(indices.size()/3);
  Opengl::getInstance()->BindVAO(0);
}
