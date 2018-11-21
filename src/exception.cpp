#include <exception.hpp>

Exception::Exception() {}

Exception::Exception(std::string message) : _message(message.c_str()) {}

Exception::~Exception() {}

std::string Exception::what() const {
  return this->_message;
}
