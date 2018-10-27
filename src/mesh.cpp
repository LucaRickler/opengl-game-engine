#include <mesh.hpp>
#include <vertex.hpp>
#include <algorithm>

#include <iostream>

Mesh::Mesh() {}

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

void Mesh::AddTri(Vertex* v1, Vertex* v2, Vertex* v3) {
  int id;
  id = this->AddVertex(v1);
  this->_indices.push_back(id);
  std::cout << id << std:: endl;
  id = this->AddVertex(v2);
  this->_indices.push_back(id);
  std::cout << id << std:: endl;
  id = this->AddVertex(v3);
  this->_indices.push_back(id);
  std::cout << id << std:: endl;

  // std::cout << this->_v_pointers.size() << std:: endl;
  // std::cout << this->_indices.size() << std::endl;

  //this->RemoveBuffers();
  this->GenerateBuffers();
}

int Mesh::AddVertex(Vertex* vertex) {
  auto index = std::find(this->_v_pointers.begin(), this->_v_pointers.end(), vertex);
  if (index != this->_v_pointers.end())
    return index - this->_v_pointers.begin();
  
  this->_v_pointers.push_back(vertex);
  float* array = vertex->GetArray();
  
  for(int i = 0; i < 11; i++) {
    this->_vertices.push_back(array[i]);
  }
  delete[] array;

  return this->_v_pointers.size() -1;
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

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6* sizeof(float)));
  glEnableVertexAttribArray(2);

  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8* sizeof(float)));
  glEnableVertexAttribArray(3);

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