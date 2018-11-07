#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <dependencies.hpp>
#include <gl-object.hpp>

class Texture : public GLObject {
public:
  Texture();
  Texture(int width, int height);
  virtual ~Texture();

  int GetWidth() const;
  int GetHeight() const;

  virtual void Bind() = 0;

protected:
  int _width;
  int _height;
};

#endif
