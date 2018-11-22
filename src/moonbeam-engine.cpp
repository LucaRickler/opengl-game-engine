#include <moonbeam-engine.hpp>

#include <core/exception.hpp>

#include <core/memory/linear-allocator.hpp>
#include <core/memory/proxy-allocator.hpp>

#include <core/system-manager.hpp>
#include <core/entity-manager.hpp>
#include <core/component-manager.hpp>

#include <graphics/window.hpp>

MoonBeamEngine::MoonBeamEngine() {
  size_t size = this->ComputeGlobalMemorySize();
  this->_memory = malloc(size + 128*1024);
  this->_main_allocator = new Memory::LinearAllocator(this->_memory, size + 128*1024);

  this->_sys_alloc = _main_allocator->AllocateAllocator<Memory::LinearAllocator>(size/3);
  this->_sys_proxy = _main_allocator->Allocate<Memory::ProxyAllocator>(*this->_sys_alloc);
  this->_sys_manager = new SystemManager(this->_sys_proxy, size/30);
  
  this->_ent_alloc = _main_allocator->AllocateAllocator<Memory::LinearAllocator>(size/3);
  this->_ent_proxy = _main_allocator->Allocate<Memory::ProxyAllocator>(*this->_ent_alloc);
  this->_ent_manager = new EntityManager(this->_ent_proxy, 4096, 10000);

  this->_comp_alloc = _main_allocator->AllocateAllocator<Memory::LinearAllocator>(size/3);
  this->_comp_proxy = _main_allocator->Allocate<Memory::ProxyAllocator>(*this->_comp_alloc);
  this->_comp_manager = new ComponentManager(this->_comp_proxy, 64*1024, 10000);

  this->_sys_manager->SetComponentManager(this->_comp_manager);
  this->_ent_manager->SetComponentManager(this->_comp_manager);
}

MoonBeamEngine::~MoonBeamEngine() {
  this->_main_allocator->Clear();
  delete this->_main_allocator;
  free(this->_memory);
}

SystemManager* MoonBeamEngine::GetSystemManager() const {
  return this->_sys_manager;
}

EntityManager* MoonBeamEngine::GetEntityManager() const {
  return this->_ent_manager;
}

ComponentManager* MoonBeamEngine::GetComponentManager() const {
  return this->_comp_manager;
}

Window* MoonBeamEngine::CreateWindow(unsigned int width, unsigned int height) {
  this->_window = _main_allocator->Allocate<Window>(width, height);
  try {
    this->_window->Open();
  } catch (Exception& e) {
    std::cout << e.what() << std::endl;
    exit(-1);
  }
  return this->_window;
}

size_t MoonBeamEngine::ComputeGlobalMemorySize() {
  //TODO
  return 3*1024*1024*sizeof(u_int8_t);
}
