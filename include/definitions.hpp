#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

namespace Memory {
  class Allocator;
  class LinearAllocator;
  class StackAllocator;
  class BlockListAllocator;
  template <class T> class PoolAllocator;
  class ProxyAllocator;
}

class SystemManager;
class System;
class EntityManager;

typedef unsigned long EntityId;
typedef size_t EntityTypeId;

class Entity;

class ComponentManager;

class MoonBeamEngine;

#endif
