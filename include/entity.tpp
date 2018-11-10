template <class T>
Entity<T>::Entity() {}

template <class T>
Entity<T>::~Entity() {}

template <class T>
EntityId Entity<T>::GetEntityId() const {
  return this->_id;
}

template <class T>
bool Entity<T>::IsActive() const {
  return this->_active;
}

template <class T>
void Entity<T>::SetActive(bool state) {
  if(this->_active != state) {
    this->_active = state;
    if(state) {
      this->OnEnable();
    } else {
      this->OnDisable();
    }
  }
}

template <class T>
bool Entity<T>::operator==(const Entity& other) const {
  return this->_id == other._id;
}

template <class T>
bool Entity<T>::operator!=(const Entity& other) const {
  return !(*this == other);
}