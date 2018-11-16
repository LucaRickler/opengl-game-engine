#include <entity-manager.hpp>

EntityManager::EntityManager(Memory::Allocator* allocator, size_t map_size, unsigned int maxEntities) {
  this->_main_allocator = allocator;
  this->_map_size = map_size;

  this->_id_map = allocator->Allocate<IdMap<EntityId>>(maxEntities, allocator);
  EntityId id = this->_id_map->OccupyId();
  this->FreeId(id);
}

EntityManager::~EntityManager() {
  _main_allocator->Clear();
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
    this->_id_map->FreeId(id);
  }
}

EntityId EntityManager::GetNextId() {
  return this->_id_map->OccupyId();
}

void EntityManager::FreeId(const EntityId& id) {
  this->_id_map->FreeId(id);
}