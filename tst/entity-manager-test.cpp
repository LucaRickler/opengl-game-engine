#include <catch2/catch.hpp>

#include <moonbeam.hpp>

class E2 : public Entity {
public:
  E2() {}
  virtual ~E2() {}
};

TEST_CASE("EntityManager", "[EntityManager]") {
  unsigned int memorySize = 100000;
  void* memory = malloc(memorySize * sizeof(u_int8_t));
  LinearAllocator a(memory, memorySize * sizeof(u_int8_t));
  EntityManager em(&a, 1024*sizeof(u_int8_t),10);
  SECTION("Entity Creation") {
    Entity* e1 = em.CreateEntity<Entity>();
    REQUIRE(e1 != nullptr);
    REQUIRE(e1->GetEntityId() == 0);

    Entity* e2 = em.GetEntity(e1->GetEntityId());
    REQUIRE(e2 == e1);

    Entity* e3 = em.CreateEntity<Entity>();
    REQUIRE(e3->GetEntityId() == 1);

    em.DestroyEntity(e1->GetEntityId());
    a.Clear();
  }

  SECTION("Multiple Entity Types") {
    Entity* e1 = em.CreateEntity<Entity>();
    REQUIRE(e1 != nullptr);
    REQUIRE(e1->GetEntityId() == 0);

    Entity* e2 = em.CreateEntity<E2>();
    REQUIRE(e2 != nullptr);
    REQUIRE(e2 != e1);
    REQUIRE(e2->GetEntityId() == 1);

    a.Clear();
  }
}