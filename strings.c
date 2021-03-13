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
    text->string_capacity = 16 + strlen(char_array) - strlen(char_array) % 16;
  } else {
    text->string_capacity = strlen(char_array);
  }

  printf("%u", text->string_capacity);

  text->array = malloc(text->string_capacity * sizeof(char));
}

void read_str(string *text) {
  fgets(text->array, text->string_capacity, stdin);
  text->array[strlen(text->array) - 1] = '\0';
}

void concat_str(string *string_1, string *string_2) {
  strcat(string_1->array, string_2->array);
}

void clear_str(string *string) {
  free(string->array);
  string->string_capacity = 0;
  string->string_lenght = 0;
}

int main(void) {
  string greeting;
  string name;

  set_str(&greeting, "Oisjsjsjsjsjsjsjsj ");
  printf("oif");
  printf("%s", greeting.array);
  //read_str(&name);
//  concat_str(&greeting, &name);

//  printf("%s\n", greeting.array);
//  printf("%i %i\n", greeting.string_capacity, greeting.string_lenght);
  
//  clear_str(&greeting);
//  clear_str(&name);
  
  return 0;
}

