#ifndef DEFINITONS_HPP
#define DEFINITONS_HPP

class Exception;
class GLObject;
class Window;
class Texture;
class Texture2D;
class Shader;
class DrawShader;
class Material;
class ComputeShader;
class ComputeMaterial;
class Vertex;
class Mesh;
class Model;
class Camera;

struct TransfMatrices {
  glm::mat4 view;
  glm::mat4 projection;
};

#endif