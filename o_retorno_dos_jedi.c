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

  texto_separado = realloc(texto_separado, contador * sizeof(char*));
  
  *quantidade_texto = contador;

  return texto_separado;
}

int todos_checados(int *checagem, int *tamanho_texto) {
  for (int i = 0; i < *tamanho_texto; i++) {
    if (checagem[i] == 0) {
      return 0;
    }
  }

  return 1;
}

char **texto_embaralhado(char **texto, int *tamanho_texto) {
  char **texto_embaralhado;
  int numero_sorteado;
  int contador;
  int checagem[*tamanho_texto];

  contador = 0;
  memset(checagem, 0, *tamanho_texto * sizeof(int));
  texto_embaralhado = malloc(*tamanho_texto * sizeof(char*));

  contador = 0;
  while (todos_checados(checagem, tamanho_texto) == 0) {
    numero_sorteado = rand();
    texto_embaralhado[contador] = texto[numero_sorteado % *tamanho_texto];
    checagem[numero_sorteado % *tamanho_texto]++;
    contador++;
    if (contador >= *tamanho_texto) {
      texto_embaralhado = realloc(texto_embaralhado, (contador + 1) * sizeof(char*));
    }
  }

  *tamanho_texto = contador;

  return texto_embaralhado;
}

char *texto_unido(char **vetor_strings, int *tamanho_vetor) {
  char *texto_unido;
  int tamanho_final;

  tamanho_final = 0;
  for (int i = 0; i < *tamanho_vetor; i++) {
    tamanho_final += strlen(vetor_strings[i]);
  }
  tamanho_final += *tamanho_vetor - 1;

  texto_unido = malloc(tamanho_final * sizeof(char));
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

  srand(5940);

  msg_separada = texto_separado(mensagem, &tamanho_msg);
  msg_embaralhada = texto_embaralhado(msg_separada, &tamanho_msg);
  msg_unida = texto_unido(msg_embaralhada, &tamanho_msg);

  printf("%s", msg_unida);
}

