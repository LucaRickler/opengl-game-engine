#ifndef TEXTURE_2D_HPP
#define TEXTURE_2D_HPP

#include <texture.hpp>
#include <string>

class Texture2D : public Texture {
public:
  Texture2D(int width, int height);
  Texture2D(std::string filepath);
  virtual ~Texture2D();

  virtual void Bind();
private:
  std::string _filepath;
};

#endif
