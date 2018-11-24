#ifndef MOONBEAM_CORE_CONTAINER_FIXED_UNORDERED_MAP_HPP
#define MOONBEAM_CORE_CONTAINER_FIXED_UNORDERED_MAP_HPP

#include <dependencies.hpp>
#include <core/memory/pool-allocator.hpp>

namespace MoonBeam { namespace Core { namespace Container {
template <class K, class V>
class FixedUnorderedMap {
public:
  FixedUnorderedMap(Memory::Allocator* allocator, unsigned int size);
  ~FixedUnorderedMap();

  unsigned int MaxSize();
  unsigned int Size();

  unsigned int Insert(K&& key, V&& value);
  
  void Erase(K&& key);
  void Erase(unsigned int index);
  void Erase(unsigned int min, unsigned int max);

  void Empty();

  unsigned int Find(K&& key);

  V& operator[](K&& key) const;

protected:

private:
  typedef std::pair<K,V> pair_type;
  Memory::Allocator* _allocator;
  Memory::PoolAllocator<pair_type>* _pool;

  unsigned int _size;
  pair_type** _map;

  void CompactMap();
};
}}}

#include <core/container/fixed-unordered-map.tpp>

#endif
