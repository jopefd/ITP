#include <stdio.h>

void ImprimeProximaRonda(int n_ronda, int horas, int minutos, int segundos);

int main(void) {
  int kHoras, kMinutos, kSegundos, horas, minutos, segundos;
  scanf("%i %i %i", &kHoras, &kMinutos, &kSegundos);
  for (int n_ronda = 1; n_ronda <= 4; n_ronda++) {
    horas = kHoras;
    minutos = kMinutos;
    segundos = kSegundos;
    ImprimeProximaRonda(n_ronda, horas, minutos, segundos);
  }
  return 0;
}

void ImprimeProximaRonda(int n_ronda, int horas, int minutos, int segundos) {
  switch (n_ronda) {
    case 1: {
      horas += 1;
      break;
    }
    case 2: {
      horas += 2;
      minutos += 10;
      segundos += 30;
      break;
    }
    case 3: {
      horas += 4;
      minutos += 40;
      segundos += 50;
      break;
    }
    case 4: {
      horas += 12;
      minutos += 5;
      segundos += 5;
      break;
    }
  }
  if (segundos >= 60) {
    minutos += segundos / 60;
    segundos %= 60;
  }
  if (minutos >= 60) {
    horas += minutos / 60;
    minutos %= 60;
  }
  if (horas >= 24) {
    horas %= 24;
  }
  printf("%02i:%02i:%02i\n", horas, minutos, segundos);
}
