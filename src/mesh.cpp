#include <mesh.hpp>
#include <iostream>

Mesh::Mesh() {

}

Mesh::~Mesh() {
  this->RemoveBuffers();
}

void Mesh::Draw() {
  //if (!this->TestBuffers())
  //  this->GenerateBuffers();
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, this->_indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::UnloadMemory() {
  glBindVertexArray(0);
}

void Mesh::AddTri(float* v1, float* v2, float* v3) {
  this->AddVertex(v1);
  this->_indices.push_back(this->_vertices.size()/8 -1);
  std::cout << this->_vertices.size()/8 -1 << std:: endl;
  this->AddVertex(v2);
  this->_indices.push_back(this->_vertices.size()/8 -1);
  std::cout << this->_vertices.size()/8 -1 << std:: endl;
  this->AddVertex(v3);
  this->_indices.push_back(this->_vertices.size()/8 -1);
  std::cout << this->_vertices.size()/8 -1 << std:: endl;

  std::cout << this->_vertices.size() << std:: endl; 
  std::cout << this->_indices.size() << std::endl;

  //this->RemoveBuffers();
  this->GenerateBuffers();
}

void Mesh::AddVertex(float* vertex) {
  for(int i = 0; i < 8; i++) {
    this->_vertices.push_back(vertex[i]);
  }
  delete[] vertex;
}

void Mesh::GenerateBuffers() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertices.size(), _vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * _indices.size(), _indices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float)));
  glEnableVertexAttribArray(2);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

bool Mesh::TestBuffers() {
  return glIsVertexArray(VAO) && glIsBuffer(VBO) && glIsBuffer(EBO);
}

void Mesh::RemoveBuffers() {
  if (glIsVertexArray(VAO))
    glDeleteVertexArrays(1, &VAO);
  if (glIsBuffer(VBO))
    glDeleteBuffers(1, &VBO);
  if (glIsBuffer(EBO))
    glDeleteBuffers(1, &EBO);
}