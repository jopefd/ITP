#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *array;
  unsigned int capacity;
  unsigned int length;
} string;

void set_str(string *text, char *char_array) {
  if (strlen(char_array) % 16 > 0) {
    text->capacity = 16 + strlen(char_array) - strlen(char_array) % 16;
  } else {
    text->capacity = strlen(char_array);
  }

  text->array = malloc(text->capacity * sizeof(char));
  strcpy(text->array, char_array);
}

void read_str(string *text) {
  text->capacity = malloc(16 * sizeof(char));
  printf("%u", text->capacity);
//  fgets(text->array, text->capacity, stdin);
//  text->array[strlen(text->array) - 1] = '\0';
}

void concat_str(string *text_1, string *text_2) {
  strcat(text_1->array, text_2->array);
}

void clear_str(string *string) {
  free(string->array);
  string->capacity = 0;
  string->length = 0;
}

int main(void) {
  string greeting;
  string name;

  set_str(&greeting, "Oisjsjsjsjsjsjsjsj ");
  read_str(&name);
//  concat_str(&greeting, &name);

//  printf("%s\n", greeting.array);
//  printf("%i %i\n", greeting.capacity, greeting.length);
  
//  clear_str(&greeting);
//  clear_str(&name);
  
  return 0;
}

