#include <system-manager.hpp>

SystemManager::SystemManager(Memory::Allocator* main) {
  this->_main_allocator = main;
}

SystemManager::~SystemManager() {
  this->_main_allocator->Clear();
}

void SystemManager::SetComponentManager(ComponentManager* comManager) {
  this->_comp_manager = comManager;
}

ComponentManager* SystemManager::GetComponentManager() const {
  return this->_comp_manager;
}

void SystemManager::SortSystems() {
  
}