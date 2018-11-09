#include <moonbeam.hpp>


int main() {
  void* memory = malloc(1024*sizeof(char));

  Memory::LinearAllocator lalloc(memory, 1024*sizeof(char));

  int* i = lalloc.Allocate<int>();
  int* j = lalloc.Allocate<int>(*i);
  *i = 10;
  int* k = lalloc.Allocate<int>(*i);

  printf("i: %d\n", *i);
  printf("j: %d\n", *j);
  printf("k: %d\n", *k);

  lalloc.Clear();

  return 0;
}
