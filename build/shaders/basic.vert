layout(location = 0)in vec3 aPosition;
layout(location = 1)in vec2 aTexcoord;
layout(location = 2)in vec3 aNormal;

uniform mat4 modelMat,projViewMat;

out vec3 Normal,FragPos;

void main()
{
  gl_Position = projViewMat*modelMat*vec4(aPosition,1.0f);
  Normal = mat3(transpose(inverse(modelMat))) * aNormal;
  FragPos = vec3(modelMat*vec4(aPosition,1.0f));
}
