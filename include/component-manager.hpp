#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <dependencies.hpp>

#include <utils/utils.hpp>
#include <memory/pool-allocator.hpp>
#include <id-map.hpp>
#include <component.hpp>

#include <map>
#include <unordered_map>
#include <vector>

class ComponentManager {
  using ComponentMap=std::unordered_map<TypeId, std::unordered_map<ComponentId, Component*>>;
  using ComponentIterator=std::unordered_map<ComponentId, Component*>::iterator;
public:
  ComponentManager(Memory::Allocator* main, size_t mapSize, unsigned int maxComponents);
  ~ComponentManager();

  template <class T>
  T* CreateComponent() {
    TypeId tid = Utils::GetTypeId<T>();
    auto iter = _type_allocators.find(tid);
    Memory::Allocator* alloc;
    if (iter == _type_allocators.end()) {
      alloc = _main_allocator->AllocateAllocator<Memory::PoolAllocator<T>>(_map_size);
      assert(alloc != nullptr);

      _type_allocators[tid] = alloc;
      _components[tid] = std::unordered_map<ComponentId, Component*>();

    } else {
      alloc = iter->second;
    }

    T* comp = alloc->Allocate<T>();

    assert(comp != nullptr);
    
    comp->_id = this->GetNextId();
    _components[tid][comp->_id] = comp;
    return comp;
  }

  Component* GetComponent(const ComponentId& id);
  void DestroyComponent(const ComponentId& id);

  template <class T>
  ComponentIterator* GetComponentIterator() {
    TypeId tid = Utils::GetTypeId<T>();
    assert(this->_components.find(tid) != this->_components.end());
    return this->_components[tid].begin();
  }

  ComponentManager(const ComponentManager&) = delete;
	ComponentManager& operator=(ComponentManager&) = delete;

private:
  Memory::Allocator* _main_allocator;
  std::map<TypeId, Allocator*> _type_allocators;
  ComponentMap _components;

  IdMap<ComponentId>* _id_map;
  ComponentId GetNextId();
  void FreeId(const ComponentId& id);

  size_t _map_size;
};

#endif
