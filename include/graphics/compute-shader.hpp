#ifndef COMPUTE_SHADER_HPP
#define COMPUTE_SHADER_HPP

#include <graphics/shader.hpp>
#include <string>

namespace MoonBeam { namespace Graphics {
class ComputeShader : public Shader {
public:
  ComputeShader();
  virtual ~ComputeShader();

  void Load(std::string filepath);
};
}}
#endif
