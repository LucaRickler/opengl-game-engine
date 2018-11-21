#include <graphics/material.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>

#include <algorithm>

Material::Material() {}

Material::~Material() {
  delete this->_shader;
}

Shader* const Material::GetShader() const {
  return (Shader* const)this->_shader;
}

void Material::Bind() {
  this->_shader->Bind();
  std::for_each(_textures.begin(), _textures.end(), [] (std::pair<const unsigned int, Texture*>& p){
    glActiveTexture(p.first);
    p.second->Bind();
  });
}

void Material::SetShader(Shader* shader) {
  this->_shader = shader;
}

void Material::SetTexture(unsigned int index, Texture* tex) {
  this->_textures[index] = tex;
}