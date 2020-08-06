#ifndef __MODEL_H__
#define __MODEL_H__

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"
#include <iostream>
#include <vector>
#include "Transform.h"
#include "../interfaces/IGameObject.h"

class Model : public IGameObject
{
public:
  Model(std::string path);
  //void Draw(GLuint shaderID);
  void Process();
  void Init(){}
  //Transform transform;
private:
  std::vector<Mesh> meshes;
  void loadModel(std::string path);
  void processNode(aiNode* node,const aiScene* scene);
  Mesh processMesh(aiMesh *mesh,const aiScene *scene);
  // Later on we need to add a function for textures

};

#endif /* end of include guard: __MODEL_H__ */
