#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

namespace MoonBeam {
  namespace Core{
    namespace Memory {
      class Allocator;
      class LinearAllocator;
      class StackAllocator;
      class BlockListAllocator;
      template <class T> class PoolAllocator;
      class ProxyAllocator;
    }

    namespace Container {
      template <class T> class IdMap;
      template <class T> class FixedSet;
      template <class T, class K> class FixedUnorderedMap;
    }

    class Exception;

    typedef size_t TypeId;

    class SystemManager;
    typedef TypeId SystemId;
    class System;

    class EntityManager;
    typedef unsigned long EntityId;
    class Entity;

    class ComponentManager;
    typedef unsigned long ComponentId;
    class Component;
    typedef std::unordered_map<ComponentId, Component*>::iterator ComponentIterator;
  }

  class Transform;
  class Model;


  namespace Graphics {
    class GLObject;
    class Window;

    class Texture;
    class Texture2D;

    class Shader;
    class DrawShader;
    class ComputeShader;

    class Material;
    class ComputeMaterial;

    struct Vertex;
    class Mesh;

    class Camera;

    struct TransfMatrices {
      glm::mat4 view;
      glm::mat4 projection;
    };

    class GraphicSystem;
  }

  class MoonBeamEngine;
}
#endif
