#include <moonbeam.hpp>

class A : public Entity {
public:
  A() {}
};

class B: public Entity {
public:
  B() {}
};

void EntityTest() {
  A a;
  B b;

  printf("Type A: %X\n", Utils::GetTypeId<A>());
  printf("Type B: %X\n", Utils::GetTypeId<B>());
}

int main() {
  void* memory = malloc(1024*sizeof(char));

  Memory::PoolAllocator<int> lalloc(memory, 1024*sizeof(char));

  printf("memory: %p\n", memory);

  int* i = lalloc.Allocate<int>();
  printf("&i: %p\n", i);
  *i = 5;
  printf("i: %d\n", *i);
  int* j = lalloc.Allocate<int>(*i);
  printf("&j: %p\n", j);
  printf("i = 10\n");
  *i = 10;
  printf("i: %d\n", *i);
  printf("j: %d\n", *j);
  int* k = lalloc.Allocate<int>(*i);
  printf("&k: %p\n", k);

  printf("i: %d\n", *i);
  printf("j: %d\n", *j);
  printf("k: %d\n", *k);

  // int* array = lalloc.AllocateArray<int>(10);
  // printf("&array: %p\n", array);

  // lalloc.DeallocateArray(array);
  lalloc.Dealocate(k);


  //lalloc.Clear();
  free(memory);

  EntityTest();

  return 0;
}
