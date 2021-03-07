#include <stdio.h>
#include <string.h>

const char caracteres[]= {'0','1','2','3','4','5','6','7','8','9',
                          'A','B','C','D','E','F','G','H','I','J',
                          'K','L','M','N','O','P','Q','R','S','T',
                          'U','V','W','X','Y','Z','.',',','?',' '};

int Validade(char c[], int i) {
  if (c[strlen(c)-1] != '\n') {
    return 0;
  } else {
    c[strlen(c)-1] = '\0';
    int count = 0;

    for (int k = 0; k < i; k++) {
      for (int j = 0; j < (int)strlen(c); j++) {
        if (c[j] == caracteres[k]) {
          count++;
        }
      }
    }

    if (count == strlen(c)) {
      return 1;
    }

    return 0;
  }
}

void Cifra(char p[], char k[]) {
  // printf("%s", p);
  // printf("%lu", strlen(p));
  for (int i = 0; i < (int)strlen(p); i++) {
    for (int j = 0; j < sizeof(caracteres); j++) {
      if (p[i] == caracteres[j]) {
        // printf("%i : ", i);
        // printf("%c   ", p[i]);
        p[i] = caracteres[j+(int)(k[i]-'0')];
        // printf("%c\n", caracteres[j]);
        break;
      }
    }
  }
}

int main(void) {
  char chave[6];

  fgets(chave, 6, stdin);

  if (Validade(chave, 10) == 1) {
    
    char mensagem[202];
    fgets(mensagem, 202, stdin);
    mensagem[strlen(mensagem)-1] = '\0';

    if (Validade(mensagem, 40) == 1) {
      Cifra(mensagem, chave);
      printf("%s", mensagem);
    } else {
      printf("Caractere invalido na entrada!");
    }
  } else {
    printf("Chave invalida!");
  }

  return 0;
}
