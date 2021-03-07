#include <stdio.h>
#include <string.h>

const char S[]= {'0','1','2','3','4','5','6','7','8','9',
                 'A','B','C','D','E','F','G','H','I','J',
                 'K','L','M','N','O','P','Q','R','S','T',
                 'U','V','W','X','Y','Z','.',',','?',' '};

int mod(int n, int m) {
  if (n >= 0 && m >= 0 ) {
    return n % m;
  } else if (n <= 0 && m <= 0) {
    return n % m;
  } else {
    return n % m + m;
  }
}

void Posicoes(char c[], int p[]) {
  for (int i = 0; i < strlen(c); i++) {
    for (int j = 0; j < sizeof(S); j++) {
      if (c[i] == S[j]) {
        p[i] = j;
        break;
      }
    }
  }
}

void Chave(char c[], int pc[], char kp[], int kpp[], int k[]) {
  int count = 0,
      i = 0,
      j = 0,
      num_1 = 0,
      num_2 = 0;

  while (count < 4 && i < strlen(kp) - 4) {
    int num_1 = mod((kpp[i] - pc[j]), 40),
        num_2 = mod((kpp[i+4] - pc[j+4]), 40);

    if (num_1 == num_2) {
      k[mod(i,4)] = num_1;
      count++;
      i++;
      j++;
    } else {
      i -= count;
      count = 0;
      j = 0;
      i++;
    }
  }

  if (count == 0) {
    printf("Mensagem nao e da Resistencia!\n");
    kp[0] = '\0';
  } else {
    for (int i = 0; i < 4; i++) {
      printf("%i", k[i]);
    }
    printf("\n");
  }
}

void Decifra(char c[], int k[]) {
  for (int i = 0; i < (int)strlen(c); i++) {
    for (int j = 0; j < 40; j++) {
      if (c[i] == S[j]) {
        c[i] = S[mod(j-k[mod(i, 4)], 40)];
        // printf("i : %i\n", i);
        // printf("si : %i\n", j-k[mod(i, 4)]);
        break;
      }
    }
  }
}

int main(void) {
  char frag[] = "QUE A FORCA ESTEJA COM VOCE";
  int frag_pos[27] = {0};
  Posicoes(frag, frag_pos);

  char msg_cifr[202];
  fgets(msg_cifr, 202, stdin);
  if (msg_cifr[strlen(msg_cifr)-1] != '\n') {
    return 0;
  } else {
    msg_cifr[strlen(msg_cifr)-1] = '\0';
  }
  int msg_cifr_pos[200] = {0};
  Posicoes(msg_cifr, msg_cifr_pos);

  int chave[4] = {0};
  Chave(frag, frag_pos, msg_cifr, msg_cifr_pos, chave);
  Decifra(msg_cifr, chave);

  printf("%s", msg_cifr);

  return 0;
}
