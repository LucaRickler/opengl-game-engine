#include <memory/stack-allocator.hpp>

using namespace Memory;

StackAllocator::StackAllocator(void* start, size_t size) : Allocator(start, size) {
  assert(size > 0); 
  #if _DEBUG 
    _prev_position = nullptr; 
  #endif
  this->_position = start;
}

StackAllocator::~StackAllocator() {
  #if _DEBUG 
    _prev_position = nullptr;
  #endif 
    
  _position = nullptr; 
}

void StackAllocator::Clear() {
  this->_position = this->_start;
  this->_used = 0;
  this->_number_allocated = 0;
}

void* StackAllocator::AllocateMemory(size_t size, u_int8_t alignment) 
{
  assert(size != 0); 
  u_int8_t adjustment = this->AlignForwardAdjustmentWithHeader(_position, alignment, sizeof(AllocationHeader)); 
  
  if(_used + adjustment + size > _size) return nullptr; 
  
  void* aligned_address = this->Add(_position, adjustment); 
  // printf("aligned_address: %p\n", aligned_address);
  
  //Add Allocation Header
  AllocationHeader* header = (AllocationHeader*)(this->Subtract(aligned_address, sizeof(AllocationHeader)));
  // printf("header: %p\n", header);
  
  new (header) AllocationHeader();
  header->adjustment = adjustment;
  
  #if _DEBUG 
    header->prev_address = _prev_position;
    _prev_position = aligned_address; 
  #endif 
  
  _position = this->Add(aligned_address, size); 
  _used += size + adjustment; 
  _number_allocated++; 
  
  return aligned_address; 
}

void StackAllocator::DeallocateMemory(void* pointer) 
{
  #if _DEBUG 
    assert(pointer ==  _prev_position);
  #endif

  //Access the AllocationHeader in the bytes before p 
  AllocationHeader* header = (AllocationHeader*)(this->Subtract(pointer, sizeof(AllocationHeader))); 
  _used -= (uintptr_t)_position - (uintptr_t)pointer + header->adjustment; 
  _position = this->Subtract(pointer, header->adjustment); 
  
  #if _DEBUG 
    _prev_position = header->prev_address; 
  #endif 
  
  _number_allocated--; 
} 
