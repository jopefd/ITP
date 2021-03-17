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
  int goal_difference;
} team;

void read_teams_results(team *some_team) {
  unsigned int input_capacity;
  char *input;
  char *token;

  input_capacity = 202; 
  input = malloc(input_capacity * sizeof(char));
  while (fgets(input, input_capacity, stdin) != NULL) {
    input_capacity++;
    input = realloc(input, input_capacity * sizeof(char));
  }

  strcpy(some_team, strtok(input, ";"));
  some_team->victories = (unsigned int)atoi(strtok(NULL, " "));
  some_team->ties = (unsigned int)atoi(strtok(NULL, " "));
  some_team->defeats = (unsigned int)atoi(strtok(NULL, " "));
  some_team->home_goals = (unsigned int)atoi(strtok(NULL, " "));
  some_team->away_goals = (unsigned int)atoi(strtok(NULL, " "));
}

int main(void) {
  unsigned int teams_quantity;
  team cartola[teams_quantity];
  team ranking[teams_quantity];

  scanf("%u", &teams_quantity);
  for (int i = 0; i < teams_quantity; i++) {
    read_teams_results(&cartola[i]);
  }

  for (int i = 0; i < teams_quantity; i++) {
    ranking[i] = cartola[i];
    for (int j = 0; j < teams_quantity; j++) {
      if (cartola[j].points > ranking[i].points) {
        ranking[i] = cartola[j];
        continue;
      }
    }
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
