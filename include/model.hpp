#ifndef MODEL_HPP
#define MODEL_HPP

#include <dependencies.hpp>

namespace MoonBeam {
class Model {
public:
  Model();
  virtual ~Model();

  void Draw();

  void SetMaterial(Graphics::Material* mat);
  void SetMesh(Graphics::Mesh* mesh);
  
  Graphics::Material* GetMaterial() const;
  Graphics::Mesh* GetMesh() const;

  const glm::mat4& GetMatrix() const;
  void SetMatrix(glm::mat4& matrix);

private:
  Graphics::Mesh* _mesh;
  Graphics::Material* _material;
  glm::mat4 _matrix;
};
}
#endif