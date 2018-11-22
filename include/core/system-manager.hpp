#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <dependencies.hpp>

#include <core/utils/utils.hpp>
#include <core/memory/allocator.hpp>

#include <unordered_map>
#include <vector>

class SystemManager {
public:
  SystemManager(Memory::Allocator* main, size_t systemMemory);
  ~SystemManager();

  void SetComponentManager(ComponentManager* compManager);
  ComponentManager* GetComponentManager() const;

  template <class T, typename ...Args>
  T* CreateSystem(Args... args) {
    SystemId tid = Utils::GetTypeId<T>();
    auto iter = _systems.find(tid);
    if (iter != _systems.end() && iter->second != nullptr)
      return (T*)iter->second;
    
    T* sys = _main_allocator->Allocate<T>(args...);

    assert(sys != nullptr);

    sys->_id = tid;
    sys->_sys_manager = this;
    sys->_comp_manager = this->_comp_manager;
    sys->_allocator = _main_allocator->AllocateAllocator<Memory::LinearAllocator>(this->_system_memory);
    _systems[tid] = sys;
    return sys;
  }

  template <class T>
  T* GetSystem() const {
    SystemId tid = Utils::GetTypeId<T>();
    auto iter = _systems.find(tid);
    if (iter != _systems.end() && iter->second != nullptr)
      return iter->second;
    return nullptr;
  }

  template <class ...T>
  void AddDependencies(System* target, T... dependencies) {
    auto iter = this->_dependecy_map.find(target);
    if (iter != this->_dependecy_map.end()) {
      this->_dependecy_map[target] = std::vector<System*>();
      this->_dependecy_map[target].push_back(std::forward<T>(dependencies)...);
    }

    this->SortSystems();
  }

  void Update();


  SystemManager(const SystemManager&) = delete;
	SystemManager& operator=(SystemManager&) = delete;

private:
  std::unordered_map<SystemId, System*> _systems;
  Memory::Allocator* _main_allocator;

  std::unordered_map<System*, std::vector<System*>> _dependecy_map;
  std::vector<System*> _execution_order;
  void SortSystems();

  ComponentManager* _comp_manager;

  size_t _system_memory;
  
};

#endif