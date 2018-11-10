#ifndef PROXY_ALLOCATOR_HPP
#define PROXY_ALLOCATOR_HPP

#include <dependencies.hpp>
#include <memory/allocator.hpp>

namespace Memory {
class ProxyAllocator : public Allocator {
public:
  ProxyAllocator(Allocator& allocator);
  virtual ~ProxyAllocator();
private:
  ProxyAllocator(const ProxyAllocator&);
  ProxyAllocator& operator=(const ProxyAllocator&);

  Allocator& _allocator;
  
  void* AllocateMemory(size_t size, u_int8_t alignment = 4) override;
  void DeallocateMemory(void* pointer) override;
};
}

#endif