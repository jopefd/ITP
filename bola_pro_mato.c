#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[202];
  int points;
  int matches;
  int victories;
  int ties;
  int defeats;
  int home_goals;
  int away_goals;
  int goal_difference;
} team;

void clear_buffer() {
  while (getchar() != '\n') {

  }
}

void read_teams_results(team *some_team) {
  int input_capacity;
  char *input;
  char *token;
  
  input_capacity = 202; 
  input = realloc(input, input_capacity * sizeof(char));
  fgets(input, input_capacity, stdin);

  strcpy(some_team->name, strtok(input, ";"));
  some_team->victories = atoi(strtok(NULL, " "));
  some_team->ties = (unsigned int)atoi(strtok(NULL, " "));
  some_team->defeats = (unsigned int)atoi(strtok(NULL, " "));
  some_team->home_goals = (unsigned int)atoi(strtok(NULL, " "));
  some_team->away_goals = (unsigned int)atoi(strtok(NULL, " "));
}

int main(void) {
  int teams_quantity;
  team cartola[teams_quantity];
  team ranking[teams_quantity];
  
  scanf("%i\n", &teams_quantity);
  for (int i = 0; i < teams_quantity; i++) {
    read_teams_results(&cartola[i]);
  }

 
//   team changer;
//   for (int i = 0; i < teams_quantity; i++) {
//     for (int j = i; j < teams_quantity; j++) {
//       if (cartola[i].points < cartola[j].points) {
//         changer = cartola[i];
//         cartola[i] = cartola[j];
//         cartola[j] = changer;
//       }
//     }
//   }
 
//   printf("Nome| Pontos| Jogos| ");
//   printf("Vitorias| Empates| Derrotas| ");
//   printf("Gols Pro| Gols Contra| Saldo de Gols");
//   for (int i = 0; i < teams_quantity; i++) {
//     printf("%s| %u| %u| ", ranking[i].name, ranking[i].points, ranking[i].matches);
//     printf("%u| %u| %u| ", ranking[i].victories, ranking[i].ties, ranking[i].defeats);
//     printf("%u| %u| %u|\n", ranking[i].home_goals, ranking[i].away_goals, ranking[i].goal_difference);
//   }
}

