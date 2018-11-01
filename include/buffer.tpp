template <class T>
Buffer<T>::Buffer(T* data) {}

template <class T>
Buffer<T>::~Buffer() {}

template <class T>
void Buffer<T>::Bind() {
  glBindBuffer(this->_type, this->_id);
}

template <class T>
void Buffer<T>::UnBind() {
  glBindBuffer(this->_type, 0);
}

template <class T>
template <class K>
void Buffer<T>::SetSubData(K* data, unsigned long offset) {
  this->Bind();
  glBufferSubData(this->_type, offset, sizeof(*data), data);
}

template <class T>
T* Buffer<T>::GetData() {
  return this->_data;
}