#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, V, A;
	char C;
	
	scanf("%i %i", &N, &V);
	// Lê jogadas
	for (int i = 1; i <= N; i++)
	{
		
		scanf("%c %i", &C, &A);
    printf("%i", A);
		// Confere se a jogada é válida
		if (A >= 14)
		{
		    
			// Confere se o dragão morreu
			if (V <= 0)
			{
				// Confere qual jogador matou o dragão
				if (C == 'A')
				{
					printf("Alyson derrotou o dragão!");
				}
				else if (C == 'I')
				{
					printf("Isaac derrotou o dragão!");
				}
				else if (C == 'R')
				{
					printf("Rafaela derrotou o dragão!");
				}
				else if (C == 'W')
				{
					printf("Wellington derrotou o dragão!");
				}
				else if (C == 'S')
				{
					printf("Salgado derrotou o dragão!");
				}
				else if (C == 'C')
				{
					printf("Careca derrotou o dragão!");
				}
			}
		}
	}

	// Confere se a casa caiu
	if (V > 0)
	{
		printf("Casa caiu!");
	}

	return 0;
}
