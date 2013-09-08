#include <stdio.h>
#include <stdlib.h>
int main()
{
  void *heap_addr;
  int place_holder;
  int (*main_ptr)();
  main_ptr = main;

  heap_addr = malloc(256);

  printf("[+]Address of int on stack: %p\n", &place_holder);
  
  printf("[+]Address of first heap alloc %p\n", heap_addr);

  printf("[+]Address of main function : %p\n", main_ptr);

  return 0;
}
