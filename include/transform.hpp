#ifndef MOONBEAM_TRANFORM_HPP
#define MOONBEAM_TRANFORM_HPP

#include <dependencies.hpp>
#include <core/component.hpp>

class Transform : public Component {
public:
  Transform();
  ~Transform() override;

  glm::vec3 GetPosition() const;
  glm::vec3 GetRotation() const;
  glm::vec3 GetScale() const;

  void SetPosition(const glm::vec3& pos);
  void SetRotation(const glm::vec3& rot);
  void SetScale(const glm::vec3& scale);

  glm::mat4 GetTrasformMatrix() const;

private:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
};

#endif