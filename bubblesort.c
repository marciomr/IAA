#include "utils.h"

void bubble_sort(int* array, int size) {
  int i, j;
  for(i = 0; i < size; i++)
    for (j = size; j > i+1; j--)
      if (array[j-1] < array[j-2])
        troca(&array[j-1], &array[j-2]);
}
