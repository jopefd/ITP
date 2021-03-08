#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *from_json_string_int(char string[201], int *ptrtam) {
  int *vetor_int = malloc(strlen(string) * sizeof(int));

  for (int i = 0; i < strlen(string); i++) {
    vetor_int[i] = string[i] - '0';
  }

  *ptrtam = strlen(string);

  return vetor_int;
}

double *from_json_string_double(char string[201], int *ptrtam) {
  double *vetor_double = malloc(strlen(string) * sizeof(int));

  for (int i = 0; i < strlen(string); i++) {
    vetor_double[i] = atof(string[i]);
  }

  *ptrtam = strlen(string);

  return vetor_double;
}

int main(void) {
  

  return 0;
}
