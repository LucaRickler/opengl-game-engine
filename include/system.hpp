#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <dependencies.hpp>
#include <system-manager.hpp>

class System {
public:
  System();
  virtual ~System();

  virtual void PreUpdate() = 0;
  virtual void Update() = 0;
  virtual void PostUpdate() = 0;

  void SetActive(bool state);
  bool IsActive() const;

  template <class ...T>
  void AddDependencies(T ...dependencies) {
    this->_sys_manager->AddDependencies(this, dependencies...);
  }
  
  friend class SystemManager;

private:
  SystemId _id;

  bool operator==(const System& other) const;
  bool operator!=(const System& other) const;
  System(const System& other);

  bool _active;

  ComponentManager* _comp_manager;
  SystemManager* _sys_manager;
};

#endif
