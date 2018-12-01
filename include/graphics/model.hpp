#ifndef MODEL_HPP
#define MODEL_HPP

#include <dependencies.hpp>
#include <core/component.hpp>

namespace MoonBeam { namespace Graphics {
class Model : public Core::Component{
public:
  Model();
  virtual ~Model();

  void SetMaterial(const MaterialId& mat);
  void SetMesh(Mesh* mesh);
  
  MaterialId GetMaterial() const;
  Mesh* GetMesh() const;

private:
  Mesh* _mesh;
  MaterialId _material;
};
}}
#endif