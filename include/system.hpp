#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <dependencies.hpp>

class System {
public:
  System();
  ~System();

  virtual void PreUpdate() = 0;
  virtual void Update() = 0;
  virtual void PostUpdate() = 0;

  template <class ...T>
  void AddDependencies(T ...dependencies) {
    
  }
};

#endif
