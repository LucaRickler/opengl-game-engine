#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <dependencies.hpp>

class EntityManager {
public:
  EntityManager();
  ~EntityManager();

  template <class T>
  T* CreateEntity();
};

#endif
