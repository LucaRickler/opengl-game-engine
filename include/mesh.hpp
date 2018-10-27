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

  int AddVertex(Vertex* vertex);
  void AddTri(Vertex* v1, Vertex* v2, Vertex* v3);
private:
  unsigned int VAO, VBO, EBO;

  std::vector<Vertex*> _v_pointers;
  std::vector<float> _vertices;
  std::vector<int> _indices;

  bool TestBuffers();
  void GenerateBuffers();
  void RemoveBuffers();
};

#endif