#include <model.hpp>
#include <mesh.hpp>
#include <shader.hpp>
#include <material.hpp>

Model::Model() {
  this->_matrix = glm::mat4(1);
}

Model::~Model() {}

void Model::Draw(glm::mat4& transform) {
  this->_material->Bind();
  auto m = transform * this->_matrix;
  this->_material->GetShader()->SetMat4("transform", m);
  this->_mesh->Draw();
}

void Model::SetMaterial(Material* mat) {
  this->_material = mat;
}

void Model::SetMesh(Mesh* mesh) {
  this->_mesh = mesh;
}

Material* Model::GetMaterial() const {
  return this->_material;
}

Mesh* Model::GetMesh() const {
  return this->_mesh;
}

const glm::mat4& Model::GetMatrix() const {
  return this->_matrix;
}

void Model::SetMatrix(glm::mat4& matrix) {
  this->_matrix = matrix;
}