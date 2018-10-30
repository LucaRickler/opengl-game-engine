#ifndef SHADER_H
#define SHADER_H

#include  <dependencies.hpp>

#include <string>

class Shader {
public:
  Shader();
  virtual ~Shader();

  void Bind();
  void SetBool(const std::string &name, bool value) const;
  void SetInt(const std::string &name, int value) const;
  void SetFloat(const std::string &name, float value) const;
  void SetMat4(const std::string &name, glm::mat4 &value) const;
protected:
  unsigned int _id;
  void CheckCompileErrors(unsigned int shader, std::string type);
  void CheckLinkErrors(unsigned int program);
  std::string* LoadShaderCode(const char* path);
};
#endif
