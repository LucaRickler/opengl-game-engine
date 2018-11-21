#ifndef DRAW_SHADER_HPP
#define DRAW_SHADER_HPP

#include <graphics/shader.hpp>
#include <string>

class DrawShader : public Shader {
public:
  DrawShader();
  virtual ~DrawShader();

  void Load(const char* vertexPath, const char* fragmentPath);
};

#endif