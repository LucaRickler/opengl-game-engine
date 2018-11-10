#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

typedef unsigned long EntityId;

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
class ComponentManager;


#endif
