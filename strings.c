#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *array;
  unsigned int string_capacity;
  unsigned int string_lenght;
} string;

void set_str(string str.array, char *char_array) {
  char *string;
  unsigned int string_lenght;
  
  if (strlen(array) % 16 > 0) {
    string_lenght = 16 - (strlen(array) % 16);
  } else {
    string_lenght = strlen(array);
  }

  string = malloc(string_lenght * sizeof(char));
}

void read_str(char *string) {
  fgets(string, strlen(string) + 1, stdin);
  string[strlen(string) - 1] = '\0';
}

void concat_str(char *string_1, char *string_2) {
  strcat(string_1, string_2);
}

void clear_str(char *string) {
  free(string);
}

int main(void) {
  string greeting;
  string name;

  set_str(&greeting, "Oi ");
  read_str(&name);
  concat_str(&greeting, &name);

  printf("%s\n", greeting.str);
  printf("%i %i\n", greeting.capacity, greeting.length);
  
  clear_str(&greeting);
  clear_str(&name);
  
  return 0;
}

