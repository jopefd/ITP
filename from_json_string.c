#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format(char *string) {
  char *num = strtok(string + 1, ", ]");
  
  int i = 0;

  while (num != NULL) {
    if (strlen(num) >= 3) {
      for (int j = 0; j < strlen(num); j++) {
        string[i + j] = num[j];
      }      
      i = i + strlen(num) - 1;
    } else {
      string[i] = *num;
    }    
    num = strtok(NULL, ", ]");    
    i++;
  }

  string[i] = '\0';
}

int check_doubles(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == '.')
      return 1;
  }

  return 0;
}

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
  int n;

  scanf("%i", &n);

  char *json_arrays = malloc(n * sizeof(char));
  for (int i = 0; i < n; i++) {
    fgets(json_arrays[i], 202, );
     
  }

  return 0;
}
