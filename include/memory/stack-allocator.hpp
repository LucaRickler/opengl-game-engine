#ifndef STACK_ALLOCATOR_HPP
#define STACK_ALLOCATOR_HPP

#include <dependencies.hpp>
#include <memory/allocator.hpp>

//#define _DEBUG 1

namespace Memory {
class StackAllocator : public Allocator {
public:
  StackAllocator(void* start, size_t size);
  virtual ~StackAllocator();
  void Clear();
private:
  StackAllocator(const StackAllocator&);
  StackAllocator& operator=(const StackAllocator&);

  struct AllocationHeader {
    #if _DEBUG 
      void* prev_address; 
    #endif 
      
    u_int8_t adjustment;
  };
  
  #if _DEBUG 
    void* _prev_position; 
  #endif 
  
  
  void* _position;
  
  void* AllocateMemory(size_t size, u_int8_t alignment = 4) override;
  void DeallocateMemory(void* pointer) override;
};
}

#endif