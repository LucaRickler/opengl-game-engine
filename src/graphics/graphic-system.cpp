#include <graphics/graphic-system.hpp>
#include <graphics/camera.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace MoonBeam;
using namespace Graphics;

GraphicSystem::GraphicSystem() : _matrices_buffer(&this->_matrices, 0) {

}

GraphicSystem::~GraphicSystem() {}

void GraphicSystem::SetMainCamera(Camera* cam) {
  if (cam != nullptr)
    this->_main_camera = cam;
}

Camera* GraphicSystem::GetMainCamera() const {
  return this->_main_camera;
}

void GraphicSystem::PreUpdate() {

}

void GraphicSystem::Update() {
  this->UpdateUniforms();

}

void GraphicSystem::PostUpdate() {
  
}

void GraphicSystem::UpdateUniforms() {
  this->_matrices.view = glm::lookAt(_main_camera->GetPosition(), _main_camera->GetTarget(), _main_camera->GetUp());
  this->_matrices.projection = glm::perspective(glm::radians(_main_camera->GetFOW()), _main_camera->GetRatio(), _main_camera->GetNear(), _main_camera->GetFar());
  _matrices_buffer.SetSubData(&(_matrices.view), 0);
  _matrices_buffer.SetSubData(&(_matrices.projection), sizeof(glm::mat4));
}
