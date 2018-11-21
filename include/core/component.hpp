#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <dependencies.hpp>

class Component {
public:
  Component();
  virtual ~Component();

  ComponentId GetComponentId() const;
  EntityId GetEntityId() const;

  bool operator==(const Component& other) const;
  bool operator!=(const Component& other) const;

  friend class ComponentManager;
protected:
private:
  ComponentId _id;
  EntityId _eid;
  
};

#endif