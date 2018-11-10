#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <dependencies.hpp>

template<class T>
class Entity {
public:
  Entity();
  virtual ~Entity();

  EntityId GetEntityId() const;

protected:

private:
  EntityId _id;

};

#include <entity.tpp>

#endif