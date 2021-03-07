#include <stdio.h>

int main(void)
{
	int k;
	int kPrimo = 1;

	scanf("%i", &k);

	for (int i = 2; i < k; i++)
	{
		if (k % i == 0 && k != i)
		{
			kPrimo = 0;
			printf("%i nao primo", k);
			break;
		}
	}
	if (kPrimo)
	{
			printf("%i primo", k);
	}
	return 0;
}
