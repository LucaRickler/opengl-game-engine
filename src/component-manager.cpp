#include <component-manager.hpp>

ComponentManager::ComponentManager(Memory::Allocator* main, size_t mapSize, unsigned int maxComponents) {
  this->_main_allocator = main;
  this->_map_size = mapSize;

  this->_id_map = main->Allocate<IdMap<ComponentId>>(maxComponents, main);
}

ComponentManager::~ComponentManager() {
  _main_allocator->Clear();
  _map_size = 0;
}

Component* ComponentManager::GetComponent(const ComponentId& id) {
  //TODO
  return nullptr;
}

void ComponentManager::DestroyComponent(const ComponentId& id) {
  Component* comp = GetComponent(id);
  if(comp != nullptr) {
    TypeId tid = Utils::GetTypeId(*comp);
    _type_allocators[tid]->Dealocate(comp);
    this->_id_map->FreeId(id);
    this->_components[tid].erase(id);
  }
}

ComponentId ComponentManager::GetNextId() {
  return this->_id_map->OccupyId();
}

void ComponentManager::FreeId(const ComponentId& id) {
  this->_id_map->FreeId(id);
}