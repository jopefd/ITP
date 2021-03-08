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
    vetor_double[i] = atof(string + i);
  }

  *ptrtam = strlen(string);

  return vetor_double;
}

int main(void) {
  int n;

  scanf("%i\n", &n);

  for (int i = 0; i < n; i++) {
    char json_array[202];

    fgets(json_array, 202, stdin);
    printf("oi");
    json_array[strlen(json_array) - 1] = '\0';

    format(json_array);

    int *ptrtam;

    if (check_doubles(json_array) == 1) {
      double *ptrd = from_json_string_double(json_array, ptrtam);
      printf("%p", ptrd);
      free(ptrd);
    } else {
      int *ptri = from_json_string_int(json_array, ptrtam);
      printf("%i", *ptri);
      free(ptri);
    }
  }

  return 0;
}
