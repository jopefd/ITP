#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *array;
  unsigned int string_capacity;
  unsigned int string_lenght;
} string;

void set_str(string *text, char *char_array) {
  if (strlen(char_array) % 16 > 0) {
    text->string_capacity = 16 - (strlen(char_array) % 16);
  } else {
    text->string_capacity = strlen(char_array);
  }

  text->array = malloc(text->string_capacity * sizeof(char));
}

void read_str(string *text) {
  fgets(text->array, text->string_capacity, stdin);
  text->array[strlen(text->array) - 1] = '\0';
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

