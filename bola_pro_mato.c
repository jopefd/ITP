#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int teams_quantity;
  scanf("%u", &teams_quantity);
  char team cartola[teams_quantity];
  for (int i = 0; i < teams_quantity; i++) {
    fgets(cartola[i].name, 202, stdin);
    scanf("%u", cartola[i].victories);
    scanf("%u", cartola[i].ties);
    scanf("%u", cartola[i].defeats);
    scanf("%u", cartola[i].home_goals);
    scanf("%u", cartola[i].away_goals);
  }
}
