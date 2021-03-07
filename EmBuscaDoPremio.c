#include <stdio.h>

int main(void) {
  int qnt_simb, num_amigs;
  int simb_por_amg, num_lido;
  
  scanf("%i %i", &qnt_simb, &num_amigs);

  int simbolos[qnt_simb];

  for (int k = 0; k < qnt_simb; k++) {
    simbolos[k] = k;
  }

  for (int i = 0; i < num_amigs; i++) {
    scanf("%i", &simb_por_amg);

    for (int j = 0; j < simb_por_amg; j++) {
      scanf("%i", &num_lido);

      for (int l = 0; l < qnt_simb; l++) {
        if (num_lido == simbolos[l]) {
          simbolos[l] = -1;
        }
      }
    }
  }

  printf("[");
  for (int m = 0; m < qnt_simb; m++) {
    if (simbolos[m] > -1) {
      printf(" %i", simbolos[m]);
      if (m < qnt_simb-1) {
      printf(",");
      }
    }
  }
  printf(" ]");

  return 0;
}
