#include "utils.h"

int imaximo(int* array, int size) {
  int i;
  int imax = 0;

  for(i = 1; i < size; i++)
    if(array[i] > array[imax])
      imax = i;

  return imax;
}

void selection_sort(int* array, int size) {
  int j, imax;
  for(j = size; j > 0; j--) {
    imax = imaximo(array, j);
    troca(&array[j-1], &array[imax]);
  }
}
