#ifndef COMPUTE_SHADER_HPP
#define COMPUTE_SHADER_HPP

#include <shader.hpp>
#include <string>

class ComputeShader : public Shader {
public:
  ComputeShader();
  virtual ~ComputeShader();

  void Load(std::string filepath);
};

#endif