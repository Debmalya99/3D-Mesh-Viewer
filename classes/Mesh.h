#ifndef __MESH_H__
#define __MESH_H__

#include "Opengl.h"
#include <vector>

struct Mesh
{
  Mesh(std::vector<float> a_vertices,std::vector<float> a_texcoord,std::vector<float> a_normals,std::vector<GLuint> a_indices);
  std::vector<float> vertices,texcoords,normals;
  std::vector<GLuint> indices;
  GLuint VAO,EBO;
  void SetupMesh();
  void Draw(GLuint shaderID);
};

#endif /* end of include guard: __MESH_H__ */
