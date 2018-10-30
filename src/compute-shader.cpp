#include <compute-shader.hpp>

ComputeShader::ComputeShader() : Shader() {}

ComputeShader::~ComputeShader() {}

void ComputeShader::Load(std::string filepath) {
  const char* code = LoadShaderCode(filepath.c_str())->c_str();

  /// TODO: Memory leak up here!

  unsigned int compute = glCreateShader(GL_COMPUTE_SHADER);
  glShaderSource(compute, 1, &code, NULL);
  glCompileShader(compute);
  this->CheckCompileErrors(compute, "Compute");
  
  this->_id = glCreateProgram();
  glAttachShader(this->_id, compute);
  glLinkProgram(this->_id);
  this->CheckLinkErrors(this->_id);
  glDeleteShader(compute);
}