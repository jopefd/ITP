#include <stdio.h>
#include <string.h>

int main(void) {
  char A[41];
  char B[41];
  char C[81];

  fgets(A, 40, stdin);
  A[strlen(A) - 1] = '\0';
  fgets(B, 40, stdin);
  B[strlen(B) - 1] = '\0';

  int i = 0, j = 0, k = 0;
  while (A[i] != '\0' || B[j] != '\0') {
    if (A[i] != '\0') {
      C[k] = A[i];
      i++;
      k++;
    }
    if (B[j] != '\0') {
      C[k] = B[j];
      j++;
      k++;
    }
  }
  C[k] = '\0';

  printf("%s\n", C);
  
  return 0;
}
