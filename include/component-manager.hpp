#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <dependencies.hpp>

class ComponentManager {
public:
  ComponentManager();
  ~ComponentManager();

  template <class T>
  T* CreateComponent();
};

#endif
