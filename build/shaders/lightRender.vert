layout(location = 0)in vec3 aPosition;

uniform mat4 modelMat,projViewMat;

void main()
{
  gl_Position = projViewMat*modelMat*vec4(aPosition,1.0f);
}
