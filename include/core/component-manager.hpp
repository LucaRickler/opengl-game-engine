#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include <dependencies.hpp>

#include <core/utils/utils.hpp>
#include <core/memory/pool-allocator.hpp>
#include <core/id-map.hpp>
#include <core/component.hpp>

#include <map>
#include <unordered_map>
#include <vector>

class ComponentManager {
  using ComponentMap=std::unordered_map<TypeId, std::unordered_map<ComponentId, Component*>>;
  using EntityComponentMap=std::unordered_map<TypeId, std::unordered_map<EntityId, Component*>>;
public:
  ComponentManager(Memory::Allocator* main, size_t mapSize, unsigned int maxComponents);
  ~ComponentManager();

  void SetEntityManager(EntityManager* entManager);
  EntityManager* GetEntityManager() const;

  template <class T>
  T* CreateComponent(const EntityId& eid) {
    TypeId tid = Utils::GetTypeId<T>();
    auto iter = _type_allocators.find(tid);
    Memory::Allocator* alloc;
    if (iter == _type_allocators.end()) {
      alloc = _main_allocator->AllocateAllocator<Memory::PoolAllocator<T>>(_map_size);
      assert(alloc != nullptr);

      _type_allocators[tid] = alloc;
      _components[tid] = std::unordered_map<ComponentId, Component*>();
      _components_by_entity[tid] = std::unordered_map<EntityId, Component*>();

    } else {
      alloc = iter->second;
    }

    T* comp = alloc->Allocate<T>();

    assert(comp != nullptr);
    
    comp->_id = this->GetNextId();
    comp->_eid = eid;
    comp->_comp_manager = this;
    comp->_ent_manager = this->_ent_manager;
    _components[tid][comp->_id] = comp;
    return comp;
  }

  template <class  T>
  Component* GetComponent(const EntityId& eid) {
    TypeId tid = Utils::GetTypeId<T>();
    auto iter = this->_components_by_entity[tid].find(eid);
    if (iter != this->_components_by_entity[tid].end())
      return iter->second;
    else
      return nullptr;
  }

  Component* GetComponent(const ComponentId& id);
  
  template <class T>
  void DestroyComponent(const EntityId& eid) {
    TypeId tid = Utils::GetTypeId<T>();
    auto iter = this->_components_by_entity[tid].find(eid);
    if (iter != this->_components_by_entity[tid].end())
      this->DestroyComponent(iter->second->GetComponentId());
  }

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
  EntityComponentMap _components_by_entity;

  IdMap<ComponentId>* _id_map;
  ComponentId GetNextId();
  void FreeId(const ComponentId& id);

  EntityManager* _ent_manager;

  size_t _map_size;
};

#endif
