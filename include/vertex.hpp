#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <dependencies.hpp>

class Vertex {
public:
  Vertex();
  Vertex(glm::vec4* point);
  Vertex(glm::vec4* point, glm::vec2* uv);
  Vertex(glm::vec4* point, glm::vec2* uv, glm::vec3* normal);
  virtual ~Vertex();

  float* GetArray();
private:
  glm::vec4* _point;
  glm::vec2* _uv;
  glm::vec3* _normal;
};

static glm::vec2* const zero2 = new glm::vec2(0);
static glm::vec3* const zero3 = new glm::vec3(0);
static glm::vec4* const zero4 = new glm::vec4(0);

#endif