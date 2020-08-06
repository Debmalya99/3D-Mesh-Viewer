#ifndef __IRESOURCE_H__
#define __IRESOURCE_H__


// Resource types
#define RT_MESH 0
#define RT_TEXTURE 1
#define RT_SHADER 2

#include <string>

class IResource
{
public:
  void loadFromFile(std::string filename,unsigned int resourceType) = 0;

};

#endif /* end of include guard: __IRESOURCE_H__ */
