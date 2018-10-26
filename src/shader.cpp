#include <shader.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

#include <exception.hpp>

Shader::Shader() {}

Shader::~Shader() {
  glDeleteProgram(this->_id);
}

void Shader::Load(const char* vertexPath, const char* fragmentPath) {
  const char* vShaderCode = LoadShaderCode(vertexPath)->c_str();
  const char* fShaderCode = LoadShaderCode(fragmentPath)->c_str();

  /// TODO: Memory leak up here!

  // vertex shader
  unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  this->CheckCompileErrors(vertex, "Vertex");
  // fragment Shader
  unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  this->CheckCompileErrors(fragment, "Fragment");
  // shader Program
  this->_id = glCreateProgram();
  glAttachShader(this->_id, vertex);
  glAttachShader(this->_id, fragment);
  glLinkProgram(this->_id);
  this->CheckLinkErrors(this->_id);
  // delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}


void Shader::Use() {
  glUseProgram(this->_id);
}

void Shader::SetBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(this->_id, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(this->_id, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(this->_id, name.c_str()), value);
}

void Shader::CheckCompileErrors(unsigned int shader, std::string type) {
  int success;
  char infoLog[1024];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
    std::stringstream message;
    message << "Shader Compilation Error: \n" << type << "\n" << infoLog;
    throw Exception(message.str());
  }
}

void Shader::CheckLinkErrors(unsigned int program) {
  int success;
  char infoLog[1024];
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program, 1024, NULL, infoLog);
    std::stringstream message;
    message << "Shader Linking Error:\n" << infoLog;
    throw Exception(message.str());
  }
}

std::string* Shader::LoadShaderCode(const char* path) {
  std::string *code;
  try {
    std::ifstream file;
    file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    file.open(path);
    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    code = new std::string(stream.str());
  } catch (std::ifstream::failure e) {
    std::stringstream message;
    message << "Shader file not successfully read:\n" << path;
    throw Exception(message.str());
  }
  return code;
}
