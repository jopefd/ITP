#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num_predios;
  scanf("%i", &num_predios);
  int num_andares[num_predios];
  for (int i = 0; i < num_predios; i++) {
    scanf("%i", &num_andares[i]);
  }
  int maior_distancia = 0, distancia = 0;
  for (int j = 0; j < num_predios; j++) {
    for (int k = 0; k < num_predios; k++) {
      distancia = num_andares[j] + abs(j - k) + num_andares[k];
      if (j != k && distancia >= maior_distancia) {
        maior_distancia = distancia;
      }
    }
  }
  printf("%i", maior_distancia);
  return 0;
}
