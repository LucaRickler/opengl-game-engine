#include <draw-shader.hpp>

DrawShader::DrawShader() : Shader() {}

DrawShader::~DrawShader() {}

void DrawShader::Load(const char* vertexPath, const char* fragmentPath) {
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