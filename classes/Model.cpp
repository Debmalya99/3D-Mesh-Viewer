#include "Model.h"


Model :: Model(std::string path)
{
  loadModel(path);
}

void Model::Process()
{
  Opengl::getInstance()->UseShader(mShaderID);
  transform.ApplyTransform(mShaderID,TRM_MODEL);
  for(GLuint i = 0; i < meshes.size();i++)
  {
    meshes[i].Draw(mShaderID);
  }
}

void Model::loadModel(std::string path)
{
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile(path.c_str(),aiProcess_Triangulate|aiProcess_FlipUVs);
  if(!scene)
  {
    std::cout<<"[Model::loadModel::ERROR] Failed to load "<<path<<std::endl;
  }
  processNode(scene->mRootNode,scene);
}

void Model::processNode(aiNode* node,const aiScene* scene)
{
  for(unsigned int i = 0; i<node->mNumMeshes;i++)
  {
    aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
    meshes.push_back(processMesh(mesh,scene));
  }
  for(unsigned int i = 0;i< node->mNumChildren;i++)
  {
    processNode(node->mChildren[i],scene);
  }
}

Mesh Model::processMesh(aiMesh *mesh,const aiScene *scene)
{
  std::vector<float> vertices,normals,texcoords;
  std::vector<GLuint> indices;

  for(GLuint v = 0;v<mesh->mNumVertices;v++)
  {
    vertices.push_back(mesh->mVertices[v].x);
    vertices.push_back(mesh->mVertices[v].y);
    vertices.push_back(mesh->mVertices[v].z);

    normals.push_back(mesh->mNormals[v].x);
    normals.push_back(mesh->mNormals[v].y);
    normals.push_back(mesh->mNormals[v].z);

    if(mesh->HasTextureCoords(0))
    {
      texcoords.push_back(mesh->mTextureCoords[0][v].x);
      texcoords.push_back(mesh->mTextureCoords[0][v].y);
    }
  }

  for(unsigned int f = 0;f < mesh->mNumFaces;f++)
  {
    aiFace *face = &mesh->mFaces[f];
    indices.push_back(face->mIndices[0]);
    indices.push_back(face->mIndices[1]);
    indices.push_back(face->mIndices[2]);
  }

  return Mesh(vertices,texcoords,normals,indices);
}
