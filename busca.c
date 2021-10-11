#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// devolve a posição de n no arranjo ou -1 se não encontrar
int busca_sequencial(int* array, int n, int size) {
  int i;

  for(i = 0; i < size; i++)
    if(array[i] == n) return i;

  return -1; // n não foi encontrado
}

// devolve a posição de n no arranjo ou -1 se não encontrar
int busca_binaria(int* array, int n, int size) {
  int i, j, m;

  i = 0;
  j = size - 1;

  while(i <= j) {
    m = (j + i)/2;

    if(n < array[m]) j = m - 1;
    else if(n > array[m]) i = m + 1;
    else return m;
  }

  return -1;
}

void print_help() {
  puts("-s busca sequencial");
  puts("-b busca binaria");
  puts("-h ajuda");
}

int main(int argc, char const *argv[]) {
  int size, i, nfound, n;
  clock_t start, end;
  double elapsed;
  int* array;
  int p, tipo = 0;

  int (*busca[])(int*, int, int) = {busca_sequencial, busca_binaria};

  nfound = 0;

  if(argc < 2) {
    puts("Uso: busca <repetições> <opções>");
    return 1;
  }

  if(argc == 3) {
    if(argv[2][0] == '-') {
      if(argv[2][1] == 's') tipo = 0;
      if(argv[2][1] == 'b') tipo = 1;
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

  n = atoi(argv[1]);

  scanf("%i", &size);
  array = (int*) malloc(sizeof(int)*size);

  for(i = 0; i < size; i++)
    scanf("%i", &array[i]);

  start = clock();
  for(int i = 0; i < n; i++) {
    if((*busca[tipo])(array, -1, size) != -1)
      nfound++;
  }
  end = clock();

  elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Encontrados %i de %i elementos em %.2lf segundos.\n", nfound, n, elapsed);
  return 0;
}
