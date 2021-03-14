#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adicionar_linhas(int n, char *linhas[n], char *str) {
  for (int i = 0; i < n; i++) {
    if (linhas[i] == NULL) {
      linhas[i] = malloc(strlen(str) * sizeof(char));
      strcpy(linhas[i], str);
      return 1;
    } else if (linhas[i][strlen(linhas[i]) - 1] != '\n') {
      linhas[i] = realloc(linhas[i], (strlen(linhas[i]) + 10) * sizeof(char));
      strcat(linhas[i], str);
      return 1;
    }
  }
  return 0;
}

void imprimir_linhas(int n, char *linhas[n]) {
  for (int i = 0; i < n; i++) {
    printf("%s", linhas[i]);
  }  
}

void liberar_linhas(int n, char *linhas[n]) {
  for (int i = n - 1; i >= 0; i--) {
    free(linhas[i]);
  }
}

int main() {
  int n;
  scanf("%d\n", &n);
  char str[10];
  char *linhas[n];
  
  for (int i = 0; i < n; i++) {
    linhas[i] = NULL;   
  }
  
  do {
    fgets(str, 10, stdin);
  } while (adicionar_linhas(n, linhas, str));

  printf("Texto liberado pelo Ministro\n");

  imprimir_linhas(n, linhas);
  
  liberar_linhas(n, linhas);

  return 0;
}
