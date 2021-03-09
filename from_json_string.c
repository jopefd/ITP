#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_doubles(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == '.')
      return 1;
  }

  return 0;
}

char** format(char *array_json) {
  char** string_only_numbers;
  char *number = strtok(array_json + 1, ", ]");
  int i = 0;

  string_only_numbers = malloc(strlen(array_json) * sizeof(char*));

  while (number != NULL) {
    string_only_numbers[i] = number;
    number = strtok(NULL, ", ]");
    i++;
  }

  string_only_numbers = realloc(string_only_numbers, (i - 1) * sizeof(char*));
  
  return string_only_numbers;
}

double *from_json_string_double(char string[201], int *ptrtam) {
  double *vetor_double = malloc(strlen(string) * sizeof(int));

  for (int i = 0; i < strlen(string); i++) {
    vetor_double[i] = atof(string + i);
  }

  *ptrtam = strlen(string);

  return vetor_double;
}

int *from_json_string_int(char string[201], int *ptrtam) {
  int *vetor_int = malloc(strlen(string) * sizeof(int));

  for (int i = 0; i < strlen(string); i++) {
    vetor_int[i] = string[i] - '0';
  }

  *ptrtam = strlen(string);

  return vetor_int;
}

int main(void) {
  // Ler um número N
  int n, tam;
  scanf("%i\n", &n);

  // Laço de N repetições
  for (int i = 0; i < n; i++) {
    // Ler array JSON
    char json_array[202];
    fgets(json_array, 202, stdin);
    json_array[strlen(json_array) - 1] = '\0';
    json_array = format()

    // Converter array JSON
    // Verificar se tem doubles
    if (check_doubles(json_array) == 1) {
      double *ptrd = from_json_string_double(json_array, &tam);
    } else {
      int *ptri = from_json_string_int(json_array, &tam);
      printf("%i", *ptri);
      free(ptri);
    }
        // Se sim tem, criar vetor de doubles

        // Se não tem, criar vetor de inteiros

    int *ptrtam;

  }
    // Imprimir array convertido


  return 0;
}
