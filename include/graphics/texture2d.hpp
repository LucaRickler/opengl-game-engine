#ifndef TEXTURE_2D_HPP
#define TEXTURE_2D_HPP

#include <graphics/texture.hpp>
#include <string>

namespace MoonBeam { namespace Graphics {
class Texture2D : public Texture {
public:
  Texture2D(int width, int height);
  Texture2D(std::string filepath);
  virtual ~Texture2D();

  virtual void Bind();
private:
  std::string _filepath;
};
}}

#endif
