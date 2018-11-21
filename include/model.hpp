#ifndef MODEL_HPP
#define MODEL_HPP

#include <dependencies.hpp>

class Model {
public:
  Model();
  virtual ~Model();

  void Draw();

  void SetMaterial(Material* mat);
  void SetMesh(Mesh* mesh);
  
  Material* GetMaterial() const;
  Mesh* GetMesh() const;

  const glm::mat4& GetMatrix() const;
  void SetMatrix(glm::mat4& matrix);

private:
  Mesh* _mesh;
  Material* _material;
  glm::mat4 _matrix;
};

#endif