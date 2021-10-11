#include "utils.h"

int partition(int* array, int size) {
  int pivot = array[size-1];
  int i = -1;
  int j;

  for(j = 0; j < size-1; j++)
    if(array[j] <= pivot)
      troca(&array[++i], &array[j]);
  troca(&array[i+1], &array[j]);

  return i + 1;
}

void quicksort(int* array, int size) {
  int q;
  if (size > 0) {
    q = partition(array, size);

    quicksort(array, q);
    quicksort(&array[q+1], size - (q + 1));
  }
}
