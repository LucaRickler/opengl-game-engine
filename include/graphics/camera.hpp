#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <dependencies.hpp>
#include <graphics/uniform-buffer.hpp>
#include <core/component.hpp>

class Camera : public Component {
public:
  Camera();
  Camera(const glm::vec3& pos, const glm::vec3& target, const glm::vec3& up);
  virtual ~Camera();

  void SetPosition(glm::vec3& pos);
  void SetUp(glm::vec3& up);
  void SetTarget(glm::vec3& target);
  void SetFOW(float fow);
  void SetRatio(float ratio);
  void SetRatio(unsigned int width, unsigned int height);
  void SetNear(float near);
  void SetFar(float far);

  glm::vec3 GetPosition();
  glm::vec3 GetUp();
  glm::vec3 GetTarget();
  float GetFOW();
  float GetRatio();
  float GetNear();
  float GetFar();

  void SetActive();
  void Deactivate();

private:
  glm::vec3 _position;
  glm::vec3 _up;
  glm::vec3 _target;

  float _fow;
  float _ratio;
  float _near;
  float _far;

  UniformBuffer<TransfMatrices>* _matrices_buffer;
  TransfMatrices* _matrices;
  
  void UpdateUniforms();
  void UpdateView();
  void UpdateProjection();

};

#endif