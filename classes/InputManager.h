#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include <iostream>
#include <map>
#include <cstdio>

class InputManager
{
public:
  std::map<std::string, bool> inputMap;
  bool isActionPressed(std::string command)
  {
      return inputMap[command];
  }
  void GetActionList()
  {
    std::cout<<"Defined Actions: "<<std::endl;
    for(std::pair<std::string,bool> iterator : inputMap)
    {
      std::cout<<iterator.first<<std::endl;
    }
    getchar();
  }
};

#endif /* end of include guard: IInput */
