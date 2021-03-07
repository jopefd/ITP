#include <stdio.h>

void CreateHistogram(int c, int h[c]) {
  int num_notas, nota_lida;

  scanf("%i", &num_notas);

  for (int i = 0; i < num_notas; i++) {
    scanf("%i", &nota_lida);

    int inter = (int)(10 / c);
    int inicio_inter_c = (int)(10 * (c - 1) / c);

    if (nota_lida < inter) {
      h[0]++;
    } else if (nota_lida >= inicio_inter_c) {
      h[c - 1]++;
    } else {
      for (int j = inter; j < inicio_inter_c; j += inter) {
        if (nota_lida >= j && nota_lida < j + 10 / c) {
          h[j - 1]++;
        }
      }
    }
  }

  for (int i = 0; i < c; i++) {
    printf("%i", h[i]);
  }
}

void JoinHistograms(int c, int h1[c], int h2[c], int joint[c]) {
  for (int i = 0; i < c; i++) {
    joint[i] = h1[i] + h2[i];
  }
}

void PrintHistogram(int c, int h[c]) {
  int maior = 0;
  int inter = (int)(10 / c);

  for (int i = 0; i < c; i++) {
    if (h[i] >= maior) {
      maior = h[i];
    }
  }

  for (int j = maior; j > 0; j--) {
    for (int k = 0; k < c; k++) {
      printf("_");
      if (h[k] == h[j]) {
        printf("##");
      }
      printf("_");
    }
  }
}

int main(void) {
  int num_cat;

  scanf("%i", &num_cat);

  int hist_a[num_cat] = {0};
  int hist_b[num_cat];
  int hist_all[num_cat];  

  hist_a[0] = 1;
  hist_b[0] = 2;

  CreateHistogram(num_cat, hist_a);
  CreateHistogram(num_cat, hist_b);

  JoinHistograms(num_cat, hist_a, hist_b, hist_all);
  
  PrintHistogram(num_cat, hist_a);
  PrintHistogram(num_cat, hist_b);
  PrintHistogram(num_cat, hist_all);
  return 0;
}
