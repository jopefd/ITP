#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *array;
  unsigned int capacity;
  unsigned int length;
} string;

void set_str(string *text, char *char_array) {
  text->length = strlen(char_array);

  if (text->length % 16 > 0) {
    text->capacity = 16 + text->length - text->length % 16 + 1;
  } else {
    text->capacity = text->length + 1; 
  }

  text->array = malloc(text->capacity * sizeof(char));
  strcpy(text->array, char_array);
}

void read_str(string *text) {
  int counter = 0;
  char input[17];

  while (fgets(input, 17, stdin) != NULL) {
    counter++;
    text->capacity = 16 * counter + 1;
    text->array = realloc(text->array, text->capacity * sizeof(char));
    strcat(text->array, input);
    text->length = strlen(text->array);
  }
}

void concat_str(string *text_1, string *text_2) {
  strcat(text_1->array, text_2->array);
  text_1->length = strlen(text_1->array);
  
  if (text_1->length % 16 > 0) {
    text_1->capacity = 16 + text_1->length - text_1->length % 16 + 1;
  } else {
    text_1->capacity = text_1->length + 1; 
  }
}

void clear_str(string *string) {
  free(string->array);
  string->capacity = 0;
  string->length = 0;
}

int main(void) {
  string greeting;
  string name;

  set_str(&greeting, "Oi ");
  read_str(&name);
  concat_str(&greeting, &name);

  printf("%s\n", greeting.array);
  printf("%i %i\n", greeting.capacity - 1, greeting.length);
  
  clear_str(&greeting);
  clear_str(&name);
  
  return 0;
}
