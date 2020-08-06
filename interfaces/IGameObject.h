#ifndef __IGAMEOBJECT_H__
#define __IGAMEOBJECT_H__

#include "../classes/Opengl.h"
#include "../classes/Transform.h"

class IGameObject
{
protected:
public:
	Transform transform;
	GLuint mShaderID;
	virtual void Init() = 0;
	virtual void Process() = 0;
	GLuint GetShader(){return mShaderID;}
	void SetShader(GLuint shaderID){mShaderID = shaderID;}
};

#endif
