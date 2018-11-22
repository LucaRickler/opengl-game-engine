#ifndef MOONBEAM_ENGINE_HPP
#define MOONBEAM_ENGINE_HPP

#include <dependencies.hpp>

class MoonBeamEngine {
public:
  MoonBeamEngine();
  ~MoonBeamEngine();

  SystemManager* GetSystemManager() const;
  EntityManager* GetEntityManager() const;
  ComponentManager* GetComponentManager() const;

  Window* CreateWindow(unsigned int width, unsigned int height);
private:
  void* _memory;
  Memory::Allocator* _main_allocator;

  SystemManager* _sys_manager;
  Memory::ProxyAllocator* _sys_proxy;
  Memory::LinearAllocator* _sys_alloc;

  EntityManager* _ent_manager;
  Memory::ProxyAllocator* _ent_proxy;
  Memory::LinearAllocator* _ent_alloc;
  
  ComponentManager* _comp_manager;
  Memory::ProxyAllocator* _comp_proxy;
  Memory::LinearAllocator* _comp_alloc;

  Window* _window;

  size_t ComputeGlobalMemorySize();
};

#endif