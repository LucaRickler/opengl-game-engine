#include <vertex.hpp>

Vertex::Vertex() : Vertex(zero4) {}

Vertex::Vertex(glm::vec4* point) : Vertex(point, zero3) {}

Vertex::Vertex(glm::vec4* point, glm::vec3* color) : Vertex(point, color, zero2) {}

Vertex::Vertex(glm::vec4* point, glm::vec3* color, glm::vec2* uv) : Vertex(point, color, uv, zero3) {}

Vertex::Vertex(glm::vec4* point, glm::vec3* color, glm::vec2* uv, glm::vec3* normal) {
  this->_point = point;
  this->_color = color;
  this->_uv = uv;
  this->_normal = normal;
}

Vertex::~Vertex() {
  delete this->_point;
  delete this->_color;
  delete this->_uv;
  delete this->_normal;
}

float* Vertex::GetArray() {
  float* output = new float[11];
  output[0] = this->_point->x;
  output[1] = this->_point->y;
  output[2] = this->_point->z;
  output[3] = this->_color->x;
  output[4] = this->_color->y;
  output[5] = this->_color->z;
  output[6] = this->_uv->x;
  output[7] = this->_uv->y;
  output[8] = this->_normal->x;
  output[9] = this->_normal->y;
  output[10] = this->_normal->z;
  return output;
}