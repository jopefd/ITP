#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer() {
  while (getchar() != '\n') {

  }
}

char **format(char *json_array, int *array_length) {
  char **pointer_string_numbers;
  char *numbers;

  pointer_string_numbers = malloc(strlen(json_array) * sizeof(char*));
  numbers = strtok(json_array + 1, ", ]");

  while (numbers != NULL) {
    pointer_string_numbers[*array_length] = numbers;
    (*array_length)++;
    numbers = strtok(NULL, ", ]");
  }

  return pointer_string_numbers;
}

int check_doubles(char *json_array) {
  for (int i = 0; i < strlen(json_array); i++) {
    if (json_array[i] == '.') {
      return 1;
    }
  }
  return 0;
}

double* convert_to_double_array(char **pointer_string_numbers, int *array_length) {
  double *double_array;
  double_array = malloc(*array_length * sizeof(double));
  
  for (int i = 0; i < *array_length; i++) {
    double_array[i] = atof(pointer_string_numbers[i]);
  }

  return double_array;
}

int* convert_to_int_array(char **pointer_string_numbers, int *array_length) {
  int *int_array;
  int_array = malloc(*array_length * sizeof(int));
  
  for (int i = 0; i < *array_length; i++) {
    int_array[i] = atoi(pointer_string_numbers[i]);
  }

  return int_array;
}


int main(void) {
  int inputs = 0;
  int array_length = 0;
  char json_array[202];
  char **pointer_string_numbers;

  scanf("%i", &inputs);
  clear_buffer();

  for (int i = 0; i < inputs; i++) {
    fgets(json_array, 202, stdin);
    json_array[strlen(json_array) - 1] = '\0';

    if (check_doubles(json_array) == 1) {
      pointer_string_numbers = format(json_array, &array_length);
      double *double_array;
      double_array = convert_to_double_array(pointer_string_numbers, &array_length);
      for (int j = 0; j < array_length; j++) {
        printf("%lf ", double_array[j]);
      }
      free(pointer_string_numbers);
      free(double_array);
    } else if (strlen(json_array) <= 2) {
      printf("vetor vazio\n");
      continue;
    } else {
      pointer_string_numbers = format(json_array, &array_length);
      int *int_array;
      int_array = convert_to_int_array(pointer_string_numbers, &array_length);
      for (int j = 0; j < array_length; j++) {
        printf("%i ", int_array[j]);
      }
      free(pointer_string_numbers);
      free(int_array);
    }

    printf("\n");
    array_length = 0;
  }

  return 0;
}
