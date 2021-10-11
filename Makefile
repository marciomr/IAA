sort_objects = insertionsort.o selectionsort.o bubblesort.o quicksort.o mergesort.o

all: gerador ordenacao busca

busca: busca.c
	gcc -o busca busca.c

gerador: gerador.c utils.o
	gcc -o gerador gerador.c utils.o

ordenacao: ordenacao.c utils.o $(sort_objects)
	gcc -o ordenacao ordenacao.c utils.o $(sort_objects)

utils.o: utils.c utils.h
	gcc -o utils.o utils.c -c

selectionsort.o: utils.o
	gcc -o selectionsort.o selectionsort.c -c

bubblesort.o: utils.o
	gcc -o bubblesort.o bubblesort.c -c

insertionsort.o: utils.o
	gcc -o insertionsort.o insertionsort.c -c

mergesort.o: utils.o
	gcc -o mergesort.o mergesort.c -c

quicksort.o: utils.o
	gcc -o quicksort.o quicksort.c -c

clean:
	rm -rf *.o *~ gerador ordenacao busca
