#ifndef LINEAR_ALLOCATOR_HPP
#define LINEAR_ALLOCATOR_HPP

#include <dependencies.hpp>
#include <memory/allocator.hpp>

namespace Memory {
class LinearAllocator : public Allocator {
public:
  LinearAllocator(void* start, size_t size);
  virtual ~LinearAllocator();
  void Clear();
private:
  LinearAllocator(const LinearAllocator&);
  LinearAllocator& operator=(const LinearAllocator&);

  void* _position;
  
  void* AllocateMemory(size_t size, u_int8_t alignment = 4) override;
  void DeallocateMemory(void* pointer) override;
};
}

#endif