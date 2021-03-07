#include <stdio.h>
#include <stdlib.h>

int SomaDosDivisoresProp(int num);
char SaoColegas(int num1, int num2);

int main(void) {
	int num1, num2;
	scanf("%i %i", &num1, &num2);
	char res = SaoColegas(num1, num2);
	printf("%c", res);
  return 0;
}

int SomaDivisoresProprios(int num) {
	int soma = 0;
	for(int i = 1; i < num; i++) {
		if (num % i == 0) {
			soma += i;
		}
	}
	return soma;
}

char SaoColegas(int num1, int num2) {
	if (abs(SomaDivisoresProprios(num1) - num2) <= 2 &&
			abs(SomaDivisoresProprios(num2) - num1) <= 2) {
				return 'S';
	} else {
		return 'N';
	}
}
