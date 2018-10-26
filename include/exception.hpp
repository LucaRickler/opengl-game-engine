#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

class Exception {
public:
  Exception();
  Exception(std::string message);
  virtual ~Exception();

  virtual std::string what() const throw();
private:
  std::string _message;
};

#endif
