#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <dependencies.hpp>
#include <gl-object.hpp>

template <class T>
class Buffer : public GLObject{
public:
  Buffer(T* data);
  virtual ~Buffer();

  virtual void Bind();
  virtual void UnBind();
  template <class K>
  void SetSubData(K* data, unsigned long offset);

  T* GetData();
protected:
  T* _data;
};

#include <buffer.tpp>

#endif