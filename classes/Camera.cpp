#include "Camera.h"

void Camera::Init()
{

}

void Camera::Process()
{
  transform.ApplyTransform(mShaderID,TRM_CAMERA);
}
