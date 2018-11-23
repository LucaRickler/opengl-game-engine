#include <core/system.hpp>

using namespace MoonBeam;
using namespace Core;

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