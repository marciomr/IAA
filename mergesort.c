#include <stdlib.h>
#include "utils.h"

int* merge(int* array1, int* array2, int size1, int size2) {
  int k, i, j;
  i = j = 0;

  int* array3 = (int*) malloc(sizeof(int)*(size1 + size2));

  for(k = 0; k < size1 + size2; k++)
    array3[k] = ((array1[i] <= array2[j] && i < size1) || j >= size2) ? array1[i++] : array2[j++];

  return array3;
}

void merge_sort(int* array, int size) {
  int m = size/2;
  int* tmp;

  if (size > 1) {
    merge_sort(array, m);
    merge_sort(&array[m], size - m);
  }

  tmp = merge(array, &array[m], m, size - m);

  for(int i = 0; i < size; i++) array[i] = tmp[i];
}
