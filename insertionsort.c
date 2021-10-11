#include "utils.h"

void insertion_sort(int* array, int size) {
  int i, j, chave;
  for(j = 1; j < size; j++) {
    chave = array[j];
    for(i = j-1; i >= 0 && array[i] > chave; i--)
      array[i+1] = array[i];
    array[i+1] = chave;
  }
}
