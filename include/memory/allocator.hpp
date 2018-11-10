#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <dependencies.hpp>

namespace Memory {
class Allocator {
public:
  Allocator(void* start, size_t size);
  virtual ~Allocator();

  template <class T>
  T* Allocate() {
    return new (this->AllocateMemory(sizeof(T), alignof(T))) T;
  }

  template <class T>
  T* Allocate(const T& other){
    return new (this->AllocateMemory(sizeof(T), alignof(T))) T(other);
  }

  template <class T>
  void Dealocate(T& object) {
    object.~T();
    this->DeallocateMemory(&object);
  }

  template <class T>
  T* AllocateArray(size_t length) {
    assert(length != 0); 
    uint8_t headerSize = sizeof(size_t)/sizeof(T); 
    
    if(sizeof(size_t)%sizeof(T) > 0) headerSize += 1; 
    
    //Allocate extra space to store array length in the bytes before the array 
    T* p = ( (T*) this->AllocateMemory(sizeof(T)*(length + headerSize), __alignof(T)) ) + headerSize;
    *( ((size_t*)p) - 1 ) = length;
    
    for (size_t i = 0; i < length; i++) 
      new (&p) T; 
    
    return p;
  }

  template <class T>
  T* DeallocateArray(T* array) {
    assert(array != nullptr); 
    size_t length = *( ((size_t*)array) - 1 ); 
    
    for (size_t i = 0; i < length; i++) array.~T(); 
    
    //Calculate how much extra memory was allocated to store the length before the array 
    uint8_t headerSize = sizeof(size_t)/sizeof(T); 
    if(sizeof(size_t)%sizeof(T) > 0) 
      headerSize += 1; 
    this->DeallocateMemory(array - headerSize); 
  }

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

  bool IsAligned(void* address, u_int8_t alignment);
  void* AlignForward(void* address, u_int8_t alignment);
  u_int8_t AlignForwardAdjustment(const void* address, u_int8_t alignment);
  u_int8_t AlignForwardAdjustmentWithHeader(const void* address, u_int8_t alignment, u_int8_t headerSize);
  void* Add(void* pointer, size_t x);
  void* Subtract(void* pointer, size_t x);

};
}

#endif
