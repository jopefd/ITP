#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[202];
  unsigned int points;
  unsigned int matches;
  unsigned int victories;
  unsigned int ties;
  unsigned int defeats;
  unsigned int home_goals;
  unsigned int away_goals;
  unsigned int goal_difference;
} team;

int main(void) {
  unsigned int teams_quantity;
  team cartola[teams_quantity];
  team ranking[teams_quantity];

  scanf("%u", &teams_quantity);
  for (int i = 0; i < teams_quantity; i++) {
    fgets(cartola[i].name, 202, stdin);
    scanf("%u", &cartola[i].victories);
    scanf("%u", &cartola[i].ties);
    scanf("%u", &cartola[i].defeats);
    scanf("%u", &cartola[i].home_goals);
    scanf("%u", &cartola[i].away_goals);
  }
 
  printf("Nome| Pontos| Jogos| ");
  printf("Vitorias| Empates| Derrotas| ");
  printf("Gols Pro| Gols Contra| Saldo de Gols");
  for (int i = 0; i < teams_quantity; i++) {
    printf("%s| %u| %u| ", ranking[i].name, ranking[i].points, ranking[i].matches);
    printf("%u| %u| %u| ", ranking[i].victories, ranking[i].ties, ranking[i].defeats);
    printf("%u| %u| %u|", ranking[i].home_goals, ranking[i].away_goals, ranking[i].goal_difference);
  }
}
