namespace MoonBeam { namespace Core { namespace Container {

template <class K, class V>
FixedUnorderedMap<K,V>::FixedUnorderedMap(Memory::Allocator* allocator, unsigned int size) {
  this->_allocator = allocator;
  this->_size = size;

  this->_map = _allocator->AllocateArray<pair_type*>(size);
  size_t poolSize = Memory::PoolAllocator<pair_type>::GetSizeForNumber(size);
  this->_pool = _allocator->AllocateAllocator<Memory::PoolAllocator<pair_type>>(poolSize);
}

template <class K, class V>
FixedUnorderedMap<K,V>::~FixedUnorderedMap() {}

template <class K, class V>
unsigned int FixedUnorderedMap<K,V>::MaxSize() {
  return this->_size;
}

template <class K, class V>
unsigned int FixedUnorderedMap<K,V>::Size() {
  return this->_pool->GetNumberAllocations();
}

template <class K, class V>
unsigned int FixedUnorderedMap<K,V>::Insert(K&& key, V&& value) {
  if (this->Size() == this->MaxSize())
    return -1;
  pair_type* p = this->_pool->Allocate();
  p->first = key;
  p->second = value;
  this->_map[this->Size() -1] = p;
  return this->Size() -1;
}

template <class K, class V>
void FixedUnorderedMap<K,V>::Erase(K&& key) {
  unsigned int index = this->Find(std::forward<K>(key));
  this->Erase(index);
}

template <class K, class V>
void FixedUnorderedMap<K,V>::Erase(unsigned int index) {
  if (index < 0 || index >= _size) return;
  this->_pool->Dealocate(std::forward<pair_type>(*this->_map[index]));
  this->_map[index] = nullptr;
  this->CompactSet();
}

template <class K, class V>
void FixedUnorderedMap<K,V>::Erase(unsigned int min, unsigned int max) {
  for (unsigned int i = min; i <= max; i++)
    this->Erase(i);
}

template <class K, class V>
void FixedUnorderedMap<K,V>::Empty() {
  this->Erase(0, this->Size()-1);
}

template <class K, class V>
unsigned int FixedUnorderedMap<K,V>::Find(K&& key) {
  for (unsigned int i = 0; i < _size; i++) {
    if (_map[i]->first == key)
      return i;
  }
  return -1;
}

template <class K, class V>
void FixedUnorderedMap<K,V>::CompactMap() {
  for (unsigned int i = 0; i < _size; i++) {
    if (_map[i] == nullptr) {
      for (unsigned int j = i+1; j < _size; j++) {
        _map[j-1] = _map[j];
      }
    }
  }
}


template <class K, class V>
V& FixedUnorderedMap<K,V>::operator[](K&& key) const {
  unsigned int index = this->Find(std::forward<K>(key));
  return *this->_map[index];
}

}}}