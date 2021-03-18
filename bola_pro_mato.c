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
  
  input_capacity = 202; 
  input = malloc(input_capacity * sizeof(char));
  fgets(input, input_capacity, stdin);

  strcpy(some_team->name, strtok(input, ";"));
  some_team->victories = atoi(strtok(NULL, " "));
  some_team->ties = atoi(strtok(NULL, " "));
  some_team->defeats = atoi(strtok(NULL, " "));
  some_team->home_goals = atoi(strtok(NULL, " "));
  some_team->away_goals = atoi(strtok(NULL, " "));
  some_team->points = 3 * some_team->victories + some_team->ties;
  some_team->goal_difference = some_team->home_goals - some_team->away_goals;
  some_team->matches = some_team->victories + some_team->ties + some_team->defeats;
  
  free(input);
}

int main(void) {
  int teams_quantity;
  scanf("%i\n", &teams_quantity);
  team cartola[teams_quantity];
  team ranking[teams_quantity];
  
  for (int i = 0; i < teams_quantity; i++) {
    read_teams_results(&cartola[i]);
  }

  team changer;
  for (int i = 0; i < teams_quantity; i++) {
    for (int j = i; j < teams_quantity; j++) {
      if (cartola[i].points < cartola[j].points) {
        changer = cartola[i];
        cartola[i] = cartola[j];
        cartola[j] = changer;
      } else if (cartola[i].points == cartola[j].points) {
        if (cartola[i].victories < cartola[j].victories) {
           changer = cartola[i];
           cartola[i] = cartola[j];
           cartola[j] = changer;
        } else if (cartola[i].victories > cartola[j].victories) {
        //   changer = cartola[i];
        //   cartola[i] = cartola[j];
        //   cartola[j] = changer;
        } else if (cartola[i].goal_difference < cartola[j].goal_difference) {
          changer = cartola[i];
          cartola[i] = cartola[j];
          cartola[j] = changer;
        // } else if (cartola[i].goal_difference > cartola[j].goal_difference) {
        //   changer = cartola[j];
        //   cartola[j] = cartola[i];
        //   cartola[i] = changer;
        }
      }
    }
  }
 
  printf("Tabela do campeonato:\n");
  printf("Nome| Pontos| Jogos| ");
  printf("Vitorias| Empates| Derrotas| ");
  printf("Gols Pro| Gols Contra| Saldo de Gols\n");
  for (int i = 0; i < teams_quantity; i++) {
    printf("%s| %i| %i| ", cartola[i].name, cartola[i].points, cartola[i].matches);
    printf("%i| %i| %i| ", cartola[i].victories, cartola[i].ties, cartola[i].defeats);
    printf("%i| %i| %i\n", cartola[i].home_goals, cartola[i].away_goals, cartola[i].goal_difference);
  }
  
  printf("\nTimes na zona da libertadores:\n");
  for (int i = 0; i < 6; i++) {
      printf("%s\n", cartola[i].name);
  }
  
    printf("\nTimes rebaixados:\n");
  for (int i = teams_quantity - 1; i >= teams_quantity - 4; i--) {
      printf("%s\n", cartola[i].name);
  }
}

