#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.h"
#include "ordenacao.h"

void print_help() {
  puts("-s selecion sort");
  puts("-i insertion sort");
  puts("-b bubble sort");
  puts("-m merge sort");
  puts("-q quick sort");
  puts("-h ajuda");
}

int main(int argc, char const *argv[]) {
  Bool sucesso = TRUE;
  int tipo, size, i;
  clock_t start, end;
  double elapsed;
  int* array;

  void (*sort[])(int*, int) = {selection_sort,
                               insertion_sort,
                               bubble_sort,
                               merge_sort,
                               quicksort};

  if(argc < 2) {
    puts("Uso: ordecao <opções>");
    return 1;
  }

  if(argv[1][0] == '-') {
    switch (argv[1][1]) {
      case 's': tipo = 0; break;
      case 'i': tipo = 1; break;
      case 'b': tipo = 2; break;
      case 'm': tipo = 3; break;
      case 'q': tipo = 4; break;
      case 'h':
      default:
        print_help();
        return 0;
    }
  }

  scanf("%i", &size);
  array = (int*) malloc(sizeof(int)*size);

  for(i = 0; i < size; i++)
    scanf("%i", &array[i]);

  start = clock();
  //selection_sort(array, size);
  (*sort[tipo])(array, size);
  end = clock();

  elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  for(i = 1; i < size; i++) {
//    printf("%i\n", array[i]);
    if(array[i-1] > array[i])
      sucesso = FALSE;
  }

  if(sucesso)
    printf("Arranjo com %i elementos ordenado com sucesso\n", size);
  else
    puts("Algo deu errado");

  printf("Tempo de processamento: %.2lf segundos.\n", elapsed);

  return 0;
}
