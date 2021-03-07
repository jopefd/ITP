#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
  char frase[61];
  gets(frase);
  for (int i = 0; i < strlen(frase); i++) {
    if (i == 0 || frase[i-1] == ' ') {
      frase[i] = toupper(frase[i]);
    } else if (isupper(frase[i])) {
      frase[i] = tolower(frase[i]);
    }
  }
  printf("%s\n", frase);
  return 0;
}
