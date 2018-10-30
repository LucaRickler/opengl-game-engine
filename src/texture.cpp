#include <texture.hpp>

Texture::Texture() {
  glGenTextures(1, &this->_id);
}

Texture::Texture(int width, int height) : Texture() {
  this->_width = width;
  this->_height = height;
}

Texture::~Texture() {
  // glDeleteTextures(1, &this->_id);
}

int Texture::GetHeight() {
  return this->_height;
}

int Texture::GetWidth() {
  return this->_width;
}
