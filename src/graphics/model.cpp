#include <graphics/model.hpp>
#include <graphics/mesh.hpp>
#include <graphics/shader.hpp>
#include <graphics/material.hpp>

using namespace MoonBeam;
using namespace Graphics;

Model::Model() {}

Model::~Model() {}

void Model::SetMaterial(const MaterialId& mat) {
  this->_material = mat;
}

void Model::SetMesh(Mesh* mesh) {
  this->_mesh = mesh;
}

MaterialId Model::GetMaterial() const {
  return this->_material;
}

Mesh* Model::GetMesh() const {
  return this->_mesh;
}
