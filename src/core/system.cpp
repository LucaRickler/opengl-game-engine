#include <core/system.hpp>

System::System() {}

System::~System() {}

void System::SetActive(bool state) {
  this->_active = state;
}

bool System::IsActive() const {
  return this->_active;
}

Memory::LinearAllocator* System::GetAllocator() {
  return this->_allocator;
}