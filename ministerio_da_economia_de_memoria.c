#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **texto_separado(char *string, int *quantidade_texto) {
  char **texto_separado;
  char *texto;
  int contador;

  texto_separado = malloc(strlen(string) * sizeof(char*));
  texto = strtok(string, " ");
  contador = 0;

  while (texto != NULL) {
    texto_separado[contador] = texto;
    contador++;
    texto = strtok(NULL," ");
  }
    printf("%lu\n", sizeof(char*));

  texto_separado = realloc(texto_separado, contador * sizeof(char*));
  
  *quantidade_texto = contador;

  return texto_separado;
}

int falta_checar(int *checagem, int *tamanho_texto) {
  for (int i = 0; i < *tamanho_texto; i++) {
    if (checagem[i] != 1) {
      return 1;
    }
  }

  return 0;
}

char **texto_embaralhado(char **texto, int *tamanho_texto) {
  char **texto_embaralhado;
  int numero_sorteado;
  int contador;
  int checagem[*tamanho_texto];

  while (falta_checar(checagem, tamanho_texto)) {
    numero_sorteado = rand();
    texto_embaralhado[contador] = texto[numero_sorteado % *tamanho_texto];
    checagem[numero_sorteado % *tamanho_texto]++;
    contador++;
  }

  return texto_embaralhado;
}

char *texto_unido(char **vetor_strings, int *tamanho_vetor) {
  char *texto_unido;

  *tamanho_vetor += *tamanho_vetor - 1;
  texto_unido = malloc(*tamanho_vetor * sizeof(char));
  texto_unido[0] = '\0';

  for (int i = 0; i < *tamanho_vetor; i++) {
    strcat(texto_unido, vetor_strings[i]);
    if (i < *tamanho_vetor - 1) {
      strcat(texto_unido, " ");
    }
  }

  return texto_unido;
}

int main(void) {
  char mensagem[502];
  char **msg_separada;
  char **msg_embaralhada;
  char *msg_unida;
  int tamanho_msg;

  fgets(mensagem, 502, stdin);
  mensagem[strlen(mensagem) - 1] = '\0';

  srand(5940);

  msg_separada = texto_separado(mensagem, &tamanho_msg);
  // msg_embaralhada = texto_embaralhado(msg_separada, &tamanho_msg);
  // msg_unida = texto_unido(msg_embaralhada, &tamanho_msg);

  // printf("%s", msg_unida);
}
