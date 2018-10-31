#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <dependencies.hpp>
#include <map>


class Material {
public:
  Material();
  virtual ~Material();

  void Bind();

  Shader* const GetShader() const;
  
  void SetShader(Shader* shader);
  void SetTexture(unsigned int index, Texture* tex);

private:
  Shader* _shader;
  std::map<unsigned int, Texture*> _textures;
};

#endif