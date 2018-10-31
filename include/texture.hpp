#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <dependencies.hpp>

class Texture {
public:
  Texture();
  Texture(int width, int height);
  virtual ~Texture();

  int GetWidth() const;
  int GetHeight() const;

  virtual void Bind() = 0;

protected:
  unsigned int _id;
  int _width;
  int _height;
};

#endif
