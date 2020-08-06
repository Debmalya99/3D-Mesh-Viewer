layout(location = 0)in vec3 aPosition;
layout(location = 1)in vec2 aTexcoord;
layout(location = 2)in vec3 aNormal;

uniform mat4 modelMat,projViewMat;

void main()
{
  gl_Position = projViewMat*modelMat*vec4(aPosition,1.0f);
}
