#include <stdio.h>

void troca(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void print_array(int* array, int size) {
  int i;
  for(i = 0; i < size; i++)
    printf("%i ", array[i]);
  printf("\n");
}
