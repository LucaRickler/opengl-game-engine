#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <dependencies.hpp>

class Entity {
public:
  Entity();
  virtual ~Entity();

  EntityId GetEntityId() const;
  bool IsActive() const;

  void SetActive(bool state);

  virtual void OnEnable();
  virtual void OnDisable();

  bool operator==(const Entity& other) const;
  bool operator!=(const Entity& other) const;

  EntityTypeId GetTypeId() const;

protected:

private:
  EntityId _id;
  bool _active;

};

#endif