#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

namespace Memory {
  class Allocator;
  class LinearAllocator;
  class StackAllocator;
  class BlockListAllocator;
  template <class T> class PoolAllocator;
  class ProxyAllocator;
}

template <class T> class IdMap;
class Exception;

typedef size_t TypeId;

typedef TypeId SystemId;

class SystemManager;
class System;
class EntityManager;

typedef unsigned long EntityId;

class Entity;

class ComponentManager;

typedef unsigned long ComponentId;

class Component;

typedef std::unordered_map<ComponentId, Component*>::iterator ComponentIterator;

class Transform;

class GLObject;
class Window;
class Texture;
class Texture2D;
class Shader;
class DrawShader;
class Material;
class ComputeShader;
class ComputeMaterial;
struct Vertex;
class Mesh;
class Model;
class Camera;

class GraphicSystem;

struct TransfMatrices {
  glm::mat4 view;
  glm::mat4 projection;
};

class MoonBeamEngine;

#endif
