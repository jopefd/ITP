#include <stdio.h>
#include <stdlib.h>

int rand_int_range(int min, int max){
  int range = max - min + 1;
  return min + rand()%range;
}

int *criarVetorAleatorio(int tamanho, int minimo, int maximo) {
  int *vetor = malloc((tamanho + 3) * sizeof(int));
  
  vetor[0] = tamanho;
  vetor[1] = minimo;
  vetor[2] = maximo;

  for (int i = 3; i < tamanho; i++) {
    vetor[i] = rand_int_range(minimo, maximo);
  }

  return vetor;
}

int *criarHistograma(int *valores) {
  int tamanho_valores = valores[0];
  int tamanho_histograma = valores[2] - valores[1] + 2;

  int *histograma = calloc(sizeof(int), tamanho_histograma);

  histograma[0] = valores[1];
  histograma[1] = valores[2];

  int num = 0;
  for (int i = 2; i < tamanho_histograma; i++) {
    if (i == 2) {
      num = histograma[0];
    } else if (i == tamanho_histograma - 1) {
      num = histograma[1];
    } else {
      num = histograma[0] + i - 2;
    }

    for (int j = 3; j < tamanho_valores; j++) {
      if (valores[j] == num) {
        histograma[i]++;
      }
    }
  }

  return histograma;
}

float *criarPorcentagens(int *histograma) {
  int tamanho_porcentagens = histograma[1] - histograma[0];

  float *porcentagens = calloc(sizeof(int), tamanho_porcentagens);

  for (int i = 0; i < tamanho_porcentagens; i++) {
    porcentagens[i] = histograma[i + 2] * 100 / tamanho_porcentagens;
  }

  return porcentagens;
}

void imprimePorcentagens(float *porcentagens, int *histograma) {
  int minimo = histograma[0];
  int maximo = histograma[1];
  int tamanho = maximo - minimo;

  printf("Valor |Qtdade |Porcent\n");

  for (int i = 0; i <= tamanho; i++) {
    printf("%i |%i |%.2f%%\n", minimo + i, histograma[i + 2], porcentagens[i]);
  }
}

void liberar(int *vetor1, float *vetor2, int *vetor3) {
  free(vetor1);
  free(vetor2);
  free(vetor3);
}

int main(){
  int tamanho, maximo, minimo;

  scanf("%d", &tamanho);
  scanf("%d %d", &minimo, &maximo);

  int *valores = criarVetorAleatorio(tamanho, minimo, maximo);
  int *histograma = criarHistograma(valores);
  float *porcentagens = criarPorcentagens(histograma);

  imprimePorcentagens(porcentagens, histograma);
  liberar(valores, porcentagens, histograma);

  return 0;
}
