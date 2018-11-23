#include <model.hpp>
#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <graphics/material.hpp>

using namespace MoonBeam;

Model::Model() {
  this->_matrix = glm::mat4(1);
}

Model::~Model() {}

void Model::Draw() {
  this->_material->Bind();
  //auto m = transform * this->_matrix;
  this->_material->GetShader()->SetMat4("model", this->_matrix);
  this->_mesh->Draw();
}

void Model::SetMaterial(Graphics::Material* mat) {
  this->_material = mat;
}

void Model::SetMesh(Graphics::Mesh* mesh) {
  this->_mesh = mesh;
}

Graphics::Material* Model::GetMaterial() const {
  return this->_material;
}

Graphics::Mesh* Model::GetMesh() const {
  return this->_mesh;
}

const glm::mat4& Model::GetMatrix() const {
  return this->_matrix;
}

void Model::SetMatrix(glm::mat4& matrix) {
  this->_matrix = matrix;
}