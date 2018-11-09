#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <dependencies.hpp>

namespace Memory {
class Allocator {
public:
  Allocator(void* start, size_t size);
  virtual ~Allocator();

  template <class T>
  T* Allocate();

  template <class T>
  T* Allocate(const T& other);

  template <class T>
  void Dealocate(T& object);

  template <class T>
  T* AllocateArray(size_t length);

  template <class T>
  T* DeallocateArray(T* object);

protected:
  void* _start;
  size_t _size;
  size_t _used;
  size_t _number_allocated;

  virtual void* AllocateMemory(size_t size, u_int8_t allignment = 4) = 0;
  virtual void DeallocateMemory(void* pointer) = 0;
  void* GetStart() const;
  size_t GetSize() const;
  size_t GetUsedMemory() const;
  size_t GetNumberAllocations() const;

};
}

#endif
