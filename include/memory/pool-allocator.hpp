#ifndef POOL_ALLOCATOR_HPP
#define POOL_ALLOCATOR_HPP

#include <dependencies.hpp>
#include <memory/allocator.hpp>

namespace Memory {

template <class T>
class PoolAllocator : public Allocator {
public:
  PoolAllocator(void* start, size_t size);
  virtual ~PoolAllocator();
private:
  PoolAllocator(const PoolAllocator&);
  PoolAllocator& operator=(const PoolAllocator&);

  struct Block {
    bool occupied;
    T data;
  };

  size_t _block_size;
  uint8_t _alignment;
  void* _first_free;
  
  void* AllocateMemory(size_t size, u_int8_t allignment = 4) override;
  void DeallocateMemory(void* pointer) override;

  void* NextFree();
  void* GetCurrentPosition() override;
};
}

#include <memory/pool-allocator.tpp>

#endif