#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <dependencies.hpp>

class ComponentManager {
public:
  ComponentManager();
  ~ComponentManager();

  template <class T>
  T* AddComponent();

  template <class T>
  T* GetComponent();

  ComponentManager(const ComponentManager&) = delete;
	ComponentManager& operator=(ComponentManager&) = delete;
};

#endif
