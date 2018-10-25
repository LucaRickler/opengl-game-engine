#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class Exception : public std::exception {
public:
  Exception();
  Exception(const char* message);
  virtual ~Exception();

  virtual const char* what() const noexcept;
private:
  const char* _message;
};

#endif