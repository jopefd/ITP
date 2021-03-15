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

  if (strlen(char_array) % 16 > 0) {
    text->capacity = 16 + text->length - text->length % 16;
  } else {
    text->capacity = text->length; 
  }

  text->array = malloc(text->capacity * sizeof(char));
  strcpy(text->array, char_array);
}

void read_str(string *text) {
  int counter = 0;

  do {
    counter++;
    text->capacity = 16 * counter;

    if (counter == 1) {
      text->array = malloc(text->capacity * sizeof(char));
    } else {
      text->array = realloc(text->array, text->capacity * sizeof(char));
    }

    fgets(text->array, text->capacity, stdin);
    text->length = strlen(text->array);
  } while (text->array[text->length - 1] != '\n');

  text->array[text->length - 1] = '\0';
}

void concat_str(string *text_1, string *text_2) {
  strcat(text_1->array, text_2->array);
  text_1->length = strlen(text_1->array);
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
  printf("%i %i\n", greeting.capacity, greeting.length);
  
  clear_str(&greeting);
  clear_str(&name);
  
  return 0;
}

