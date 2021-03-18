#include <stdio.h>

typedef struct {
  int row;
  int column;
  int life;
  int atack;
} Jogador;

typedef struct {
  int row;
  int column;
  int life;
  int atack;
} Inimigo;

typedef enum {
  dinheiro,
  cura,
  escudo,
  espinhos,
  buraco,
  ladrao
} name_inputs;

typedef struct {
  name_inputs name;
  int row;
  int column;
} Tesouro;

typedef struct {
  name_inputs name;
  int row;
  int column;
} Armadilha;

int main(void) {
 Tesouro x;
 x.name = 0;
 printf("%i", x.name);
}
