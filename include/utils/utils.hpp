#ifndef UTILS_HPP
#define UTILS_HPP

#include <dependencies.hpp>

namespace Utils {
  template <class T>
  TypeId GetTypeId() {
    return (TypeId)typeid(T).hash_code();
  }
}

#endif