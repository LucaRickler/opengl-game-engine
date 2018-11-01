#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <dependencies.hpp>

template <class T>
class Buffer {
public:
  Buffer(T* data);
  virtual ~Buffer();

  virtual void Bind();
  virtual void UnBind();
  template <class K>
  void SetSubData(K* data, unsigned long offset);

  T* GetData();
protected:
  unsigned int _id;
  unsigned int _type;
  T* _data;
};

#include <buffer.tpp>

#endif