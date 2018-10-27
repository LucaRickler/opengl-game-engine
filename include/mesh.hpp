#ifndef MESH_HPP
#define MESH_HPP

#include <dependencies.hpp>
#include <vector>

class Mesh {
public:
  Mesh();
  virtual ~Mesh();

  void Draw();
  static void UnloadMemory();

  void AddVertex(float* vertex);
  void AddTri(float* v1, float* v2, float* v3);
private:
  unsigned int VAO, VBO, EBO;

  std::vector<float> _vertices;
  std::vector<int> _indices;

  bool TestBuffers();
  void GenerateBuffers();
  void RemoveBuffers();
};

#endif