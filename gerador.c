#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void print_help() {
  puts("-s ordenado");
  puts("-h ajuda");
}

int cmp(const void *a,const void *b) {
  int* x = (int*) a;
  int* y = (int*) b;

  return *x - *y;
}

int main(int argc, char const *argv[]) {
  Bool sorted = FALSE;
  int i, size;
  int* array;

  if(argc < 2) {
    puts("Uso: gerador <tamanho> <opções>");
    return 1;
  }

  if(argc == 3) {
    if(argv[2][0] == '-') {
      if(argv[2][1] == 's') sorted = TRUE;
      if(argv[2][1] == 'h') {
        print_help();
        return 0;
      }
    }
    else {
      print_help();
      return 0;
    }
  }

  size = atoi(argv[1]) * 10000;

  array = (int*) malloc(sizeof(int)*size);

  srand(time(NULL));

  for(i = 0; i < size; i++)
    array[i] = rand();

  if(sorted) qsort(array, size, sizeof(int), cmp);

  printf("%i\n", size);

  for(i = 0; i < size; i++)
    printf("%i\n", array[i]);


  return 0;
}
