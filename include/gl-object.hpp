#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <dependencies.hpp>
#include <string>

class GLObject {
public:
  GLObject();
  virtual ~GLObject();

  unsigned int GetGLId() const;
  unsigned int GetGLType() const;

protected:
  unsigned int* RefGLId();
  void SetGLType(unsigned int type);

private:
  unsigned int _gl_id;
  unsigned int _gl_type;
};

#endif