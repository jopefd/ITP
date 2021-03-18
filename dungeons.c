#include <stdio.h>

typedef struct {
  int enimies_quantity;
  int treasures_quantity;
  int traps_quantity;
} Sala;

typedef struct {
  int row;
  int column;
  int life;
  int attack;
} Jogador;

typedef struct {
  int row;
  int column;
  int life;
  int attack;
} Inimigo;

typedef enum {
  dinheiro,
  cura,
  escudo
} Tesouro_name;

typedef enum {
  espinhos,
  buraco,
  ladrao
} Armadilha_name;

typedef struct {
  Tesouro_name name;
  int row;
  int column;
} Tesouro;

typedef struct {
  Armadilha_name name;
  int row;
  int column;
} Armadilha;

int main(void) {
  int n;
  int m;
  scanf("%i %i", &n, &m);
  Sala mapa[n * m];

  Jogador player;
  scanf("(%i %i) - %i %i"), player.row, player.column, player.life, player.attack);
}
