#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include <dependencies.hpp>

#include <unordered_map>

class SystemManager {
public:
  SystemManager(Memory::Allocator* main);
  ~SystemManager();

  template <class T>
  void CreateSystem() {

  }
  
  System* GetSystem(const std::string& token) const;

  template <class ...T>
  void AddDependencies(System* target, T... dependencies) {

  }

private:
  std::unordered_map<SystemId, System*> _systems;
  Memory::Allocator* _main_allocator;

  void SortSystems();
  
};

#endif
