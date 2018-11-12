#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <dependencies.hpp>

#include <utils/utils.hpp>
#include <memory/pool-allocator.hpp>
#include <entity.hpp>

#include <unordered_map>

class EntityManager {
public:
  EntityManager(Memory::Allocator* main, size_t mapSize);
  ~EntityManager();

  template <class T>
  T* CreateEntity() {
    TypeId tid = Utils::GetTypeId<T>();
    auto iter = _type_allocators.find(tid);
    Memory::Allocator* alloc;
    if (iter == _type_allocators.end()) {
      alloc = _main_allocator->AllocateAllocator<Memory::PoolAllocator<T>>(_map_size);
      assert(alloc != nullptr);

      _type_allocators[tid] = alloc;

    } else {
      alloc = iter->second;
    }

    T* ent = alloc->Allocate<T>();

    assert(ent != nullptr);
    
    ent->_id = GetNewId();
    _entities[ent->_id] = ent;
    return ent;
  }

  Entity* GetEntity(const EntityId& id);
  void DestroyEntity(const EntityId& id);

private:
  Memory::Allocator* _main_allocator;
  std::unordered_map<TypeId, Allocator*> _type_allocators;
  std::unordered_map<EntityId, Entity*> _entities;

  EntityId GetNewId();

  size_t _map_size;
  void* _next_start;
};

#endif
