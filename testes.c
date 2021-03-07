#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rand_int_range(signed int min, signed int max){
  int range = max - min + 1;
  return min + rand()%range;
}

int *criarVetorAleatorio(int tamanho, int minimo, signed int maximo) {
  int *vetor = malloc((tamanho + 3) * sizeof(int));
  
  vetor[0] = tamanho;
  vetor[1] = minimo;
  vetor[2] = maximo;

  for (int i = 3; i < tamanho + 3; i++) {
    vetor[i] = rand_int_range(minimo, maximo);
  }

  return vetor;
}

int main (){ 
	// int *x = criarVetorAleatorio(5, -1, 3);
  // for (int i = 0; i < 5; i++) {
  //   printf("%i\n", x[i]);
  // }
  int x = -15;
  printf("%i\n", 0-x);
}
