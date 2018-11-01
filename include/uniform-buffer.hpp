#ifndef UNIFORM_BUFFER_HPP
#define UNIFORM_BUFFER_HPP

#include <buffer.hpp>

template<class T>
class UniformBuffer : public Buffer<T> {
public:
  UniformBuffer(T* data, int point);
  virtual ~UniformBuffer();
};

#include <uniform-buffer.tpp>

#endif