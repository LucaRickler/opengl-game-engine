#ifndef SHADER_H
#define SHADER_H

#include  <dependencies.hpp>
#include <gl-object.hpp>
#include <string>

class Shader : public GLObject {
public:
  Shader();
  virtual ~Shader();

  void Bind();
  void SetBool(const std::string &name, bool value) const;
  void SetInt(const std::string &name, int value) const;
  void SetFloat(const std::string &name, float value) const;
  void SetVec2(const std::string &name, glm::vec2 &value) const;
  void SetVec3(const std::string &name, glm::vec3 &value) const;
  void SetVec4(const std::string &name, glm::vec4 &value) const;
  void SetMat4(const std::string &name, glm::mat4 &value) const;
  void BindUniformBlock(const std::string &name, int point);
protected:
  void CheckCompileErrors(unsigned int shader, std::string type);
  void CheckLinkErrors(unsigned int program);
  std::string* LoadShaderCode(const char* path);
};
#endif
