#include <entity-manager.hpp>

EntityManager::EntityManager(Memory::Allocator* allocator, size_t map_size) {
  this->_main_allocator = allocator;
  this->_map_size = map_size;
  //this->_next_start = allocator->
}

EntityManager::~EntityManager() {
  _main_allocator->Clear();
  _next_start = nullptr;
  _map_size = 0;
}

Entity* EntityManager::GetEntity(const EntityId& id) {
  auto iter = _entities.find(id);
  if (iter == _entities.end())
    return nullptr;
  else
    return iter->second;
}

void EntityManager::DestroyEntity(const EntityId& id) {
  Entity* ent = GetEntity(id);
  if (ent != nullptr) {
    TypeId tid = Utils::GetTypeId(*ent);
    _type_allocators[tid]->Dealocate(ent);
    ///TODO: Free ID
  }
}
