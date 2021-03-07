#include <stdio.h>
#include <math.h>

ScoreFinal(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9);
Mediana(int num1,int num2,int num3);

int main(void) {
  int p1, p2, p3, p4,	p5, p6, p7, p8, p9, score_final_a, score_final_b;

  for (int i = 1; i <= 18; i += 9) {
		scanf("%i %i %i %i %i %i %i %i %i", &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9);
    if (i <= 9) {
			score_final_a = ScoreFinal(p1,p2,p3,p4,p5,p6,p7,p8,p9);
    } else {
			score_final_b = ScoreFinal(p1,p2,p3,p4,p5,p6,p7,p8,p9);
    }
  }
	if (score_final_a > score_final_b) {
		printf("A");
	} else if (score_final_a < score_final_b) {
		printf("B");
	} else {
		printf("empate");
	}

  return 0;
}

int ScoreFinal(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9) {
  return Mediana(Mediana(p1,p2,p3),Mediana(p4,p5,p6),	Mediana(p7,p8,p9));
}

int Mediana(int num1,int num2,int num3) {
  if (fmax(num1,num2) > num3) {
		if (fmin(num1,num2) > num3) {
			return fmin(num1,num2);
		} else if (fmin(num1,num2) < num3) {
			return num3;
		} else {
			return num3;
		}
	} else if (fmax(num1,num2) < num3) {
		if (num1 == num2) {
			return num1;
		} else {
			return fmax(num1,num2);
		}
	} else {
		return num3;
	}
}
