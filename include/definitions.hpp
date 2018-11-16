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

template <class T> class IdMap;

typedef size_t TypeId;

class SystemManager;
class System;
class EntityManager;

typedef unsigned long EntityId;

class Entity;

class ComponentManager;

typedef unsigned long ComponentId;

class Component;

class MoonBeamEngine;

#endif
