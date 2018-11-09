#include <memory/allocator.hpp>

using namespace Memory;

Allocator::Allocator(void* start, size_t size) {
  this->_start = start;
  this->_size = size;
  this->_used = 0;
  this->_number_allocated = 0;
}

Allocator::~Allocator() {
  assert(_used == 0 && _number_allocated == 0);
  _start = nullptr;
  _size = 0;
}

template <class T>
T* Allocator::Allocate() {
  return new (this->AllocateMemory(sizeof(T), alignof(T))) T;
}

template <class T>
T* Allocator::Allocate(const T& other) {
  return new (this->AllocateMemory(sizeof(T), alignof(T))) T(other);
}

template <class T>
void Allocator::Dealocate(T& object) {
  object.~T();
  this->DeallocateMemory(&object);
}

void* Allocator::GetStart() const {
  return this->_start;
}

size_t Allocator::GetSize() const {
  return this->_size;
}
size_t Allocator::GetUsedMemory() const {
  return this->_used;
}

size_t Allocator::GetNumberAllocations() const {
  return this->_number_allocated;
}