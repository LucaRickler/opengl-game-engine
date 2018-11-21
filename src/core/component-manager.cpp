#include <core/component-manager.hpp>

ComponentManager::ComponentManager(Memory::Allocator* main, size_t mapSize, unsigned int maxComponents) {
  this->_main_allocator = main;
  this->_map_size = mapSize;

  this->_id_map = main->Allocate<IdMap<ComponentId>>(maxComponents, main);
  assert(this->_id_map != nullptr);
}

ComponentManager::~ComponentManager() {
  _main_allocator->Clear();
  _map_size = 0;
}

Component* ComponentManager::GetComponent(const ComponentId& id) {
  auto iter = this->_components.begin();
  for (; iter != this->_components.end(); iter++) {
    auto iter2 = iter->second.begin();
    for (; iter2 != iter->second.end(); iter2++) {
      if (iter2->first == id)
        return iter2->second;
    }
  }
  return nullptr;
}

void ComponentManager::DestroyComponent(const ComponentId& id) {
  Component* comp = GetComponent(id);
  if(comp != nullptr) {
    TypeId tid = Utils::GetTypeId(*comp);
    EntityId eid = comp->GetEntityId();
    _type_allocators[tid]->Dealocate(*comp);
    this->_id_map->FreeId(id);
    this->_components[tid].erase(id);
    this->_components_by_entity[tid].erase(eid);
  }
}

ComponentId ComponentManager::GetNextId() {
  return this->_id_map->OccupyId();
}

void ComponentManager::FreeId(const ComponentId& id) {
  this->_id_map->FreeId(id);
}