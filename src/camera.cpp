#include <camera.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
  this->_matrices = new TransfMatrices();
  // this->_matrices->view = glm::mat4(1);
  // this->_matrices->projection = glm::mat4(1);
  this->_matrices_buffer = new UniformBuffer<TransfMatrices>(this->_matrices, 0);
  this->_far = 0.1f;
  this->_fow = 45.0f;
  this->_near = 100.0f;
  this->_ratio = 800.0f/600.0f;
}

Camera::Camera(const glm::vec3& pos, const glm::vec3& target, const glm::vec3& up) : Camera() {
  this->_position = pos;
  this->_up = up;
  this->_target = target;

  UpdateUniforms();
}

Camera::~Camera() {
  delete this->_matrices;
  delete this->_matrices_buffer;
}

void Camera::SetPosition(glm::vec3& pos) {
  this->_position = pos;
  UpdateView();
}

void Camera::SetUp(glm::vec3& up) {
  this->_up = up;
  UpdateView();
}

void Camera::SetTarget(glm::vec3& target) {
  this->_target = target;
  UpdateView();
}

void Camera::SetFOW(float fow) {
  this->_fow = fow;
  UpdateProjection();
}

void Camera::SetRatio(float ratio) {
  this->_ratio = ratio;
  UpdateProjection();
}

void Camera::SetRatio(unsigned int width, unsigned int height) {
  this->SetRatio((float)width/(float)height);
}

void Camera::SetNear(float near) {
  this->_near = near;
  UpdateProjection();
}

void Camera::SetFar(float far) {
  this->_far = far;
  UpdateProjection();
}

glm::vec3 Camera::GetPosition() {
  return this->_position;
}

glm::vec3 Camera::GetUp() {
  return this->_up;
}

glm::vec3 Camera::GetTarget() {
  return this->_target;
}

float Camera::GetFOW() {
  return this->_fow;
}

float Camera::GetRatio() {
  return this->_ratio;
}
float Camera::GetNear() {
  return this->_near;
}

float Camera::GetFar() {
  return this->_far;
}

void Camera::SetActive() {
  ///TODO
}

void Camera::Deactivate() {
  ///TODO
}

void Camera::UpdateUniforms() {
  UpdateProjection();
  UpdateView();
}
void Camera::UpdateView() {
  this->_matrices->view = glm::lookAt(_position, _target, _up);
  _matrices_buffer->SetSubData(&_matrices->view, 0);
}

void Camera::UpdateProjection() {
  this->_matrices->projection = glm::perspective(glm::radians(_fow), _ratio, _near, _far);
  _matrices_buffer->SetSubData(&_matrices->projection, sizeof(glm::mat4));
}