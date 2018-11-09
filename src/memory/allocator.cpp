#include <memory/allocator.hpp>

namespace Memory {

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

// void* Allocator::alignForward(void* address, u_int8_t alignment) {
//   return (void*)( ( reinterpret_cast<u_int8_t*>(address) + static_cast<u_int8_t>(alignment-1) ) & static_cast<u_int8_t>(~(alignment-1)) );
// } 

// u_int8_t Allocator::alignForwardAdjustment(const void* address, u_int8_t alignment) { 
//   u_int8_t adjustment = alignment - ( reinterpret_cast<u_int8_t*>(address) & static_cast<u_int8_t*>(alignment-1) ); 
  
//   if(adjustment == alignment) return 0; 
  
//   //already aligned 
//   return adjustment; 
// } 
}
