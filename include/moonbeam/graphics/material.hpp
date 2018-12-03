#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <moonbeam/dependencies.hpp>
#include <map>

namespace MoonBeam { namespace Graphics {
class Material {
public:
  Material();
  virtual ~Material();

  void Bind();

  ShaderId GetShader() const;
  
  void SetShader(const ShaderId& shader);
  void SetTexture(unsigned int index, Texture* tex);

private:
  ShaderId _shader;
  std::map<unsigned int, Texture*> _textures;
};
}}

#endif
