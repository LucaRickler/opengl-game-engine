#include <system.hpp>

System::System() {}

System::~System() {}

void System::SetActive(bool state) {
  this->_active = state;
}

bool System::IsActive() const {
  return this->_active;
}