#include <exception.hpp>

Exception::Exception() : exception() {}

Exception::Exception(const char* message) : exception() {
  this->_message = message;
}

Exception::~Exception() {
  delete this->_message;
}

const char* Exception::what() const noexcept {
  return this->_message;
}