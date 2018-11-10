#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <dependencies.hpp>
#include <unordered_map>

class EntityManager {
public:
  EntityManager();
  ~EntityManager();

  template <class T>
  T* CreateEntity();

  template <class T>
  T* GetEntity(const EntityId& id);

  template <class T>
  void DestroyEntity(const EntityId& id);

private:
  Allocator* _memory;
  std::unordered_map<TypeId, Allocator*> _type_allocators;
  std::unordered_map<EntityId, Entity*> _entities;

  EntityId GetNewId();
};

#endif
