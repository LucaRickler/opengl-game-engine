#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <dependencies.hpp>

#include <utils/utils.hpp>
#include <memory/allocator.hpp>

#include <unordered_map>

class SystemManager {
public:
  SystemManager(Memory::Allocator* main);
  ~SystemManager();

  void SetComponentManager(ComponentManager* compManager);
  ComponentManager* GetComponentManager() const;

  template <class T, typename ...Args>
  T* CreateSystem(Args... args) {
    SystemId tid = Utils::GetTypeId<T>();
    auto iter = _systems.find(tid);
    if (iter != _systems.end() && iter->second != nullptr)
      return iter->second;
    
    T* sys = _main_allocator->Allocate<T>(args...);

    assert(sys != nullptr);

    sys->_id = tid;
    _systems[tid] = sys;
    return sys;
  }

  template <class T>
  System* GetSystem() const {
    SystemId tid = Utils::GetTypeId<T>();
    auto iter = _systems.find(tid);
    if (iter != _systems.end() && iter->second != nullptr)
      return iter->second;
    return nullptr;
  }

  template <class ...T>
  void AddDependencies(System* target, T... dependencies) {

  }


  SystemManager(const SystemManager&) = delete;
	SystemManager& operator=(SystemManager&) = delete;

private:
  std::unordered_map<SystemId, System*> _systems;
  Memory::Allocator* _main_allocator;

  void SortSystems();

  ComponentManager* _comp_manager;
  
};

#endif
