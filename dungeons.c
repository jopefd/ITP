#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum item {
    cura = 1,
    dinheiro,
    vigor
};

enum trap {
    buraco = 1,
    espinhos,
    ladrao
};

typedef struct person {
    int life, attack;
} Personagem;

typedef struct player {
    Personagem p;

    int x, y, escudo, loot;
} Jogador;

typedef struct room {
    Personagem p;
    int tesouro;
    int armadilha;
} Sala;

Sala **cria_mapa(int n, int m, Jogador *player) {
    Sala **mapa;
    mapa = calloc(n, sizeof(Sala*));
    for (int i = 0; i < n; i++) {
        mapa[i] = calloc(m, sizeof(Sala));
    }
    
    scanf("(%i %i) - %i %i\n", &player->x, &player->y, &player->p.life, &player->p.attack);
    player->escudo = 0;
    player->loot = 0;
    
    int enemies_quantity;
    int treasures_quantity;
    int traps_quantity;
    int x_sala;
    int y_sala;
    
    scanf("%i %i %i\n", &enemies_quantity, &treasures_quantity, &traps_quantity);
    
    for (int i = 0; i < enemies_quantity; i++) {
        scanf("(%i %i)", &x_sala, &y_sala);
        scanf(" - %i %i\n", &(mapa[x_sala - 1][y_sala - 1].p.life), &(mapa[x_sala - 1][y_sala - 1].p.attack));
    }
    
    char treasures_names[treasures_quantity][8];
    for (int i = 0; i < treasures_quantity; i++) {
        scanf("%s %i %i\n", treasures_names[i], &x_sala, &y_sala);
        if (strcmp(treasures_names[i], "cura") == 0) {
            mapa[x_sala - 1][y_sala - 1].tesouro = 1;
        } else if (strcmp(treasures_names[i], "dinheiro") == 0) {
            mapa[x_sala - 1][y_sala - 1].tesouro = 2;
        } else {
            mapa[x_sala - 1][y_sala - 1].tesouro = 3;
        }
    }

    char traps_names[traps_quantity][8];
    for (int i = 0; i < traps_quantity; i++) {
        scanf("%s %i %i\n", traps_names[i], &x_sala, &y_sala);
        if (strcmp(traps_names[i], "buraco") == 0) {
            mapa[x_sala - 1][y_sala - 1].armadilha = 1;
        } else if (strcmp(traps_names[i], "espinhos") == 0) {
            mapa[x_sala - 1][y_sala - 1].armadilha = 2;
        } else {
            mapa[x_sala - 1][y_sala - 1].armadilha = 3;
        }
    }
    
    printf("Mapa inicializado!\n");
    printf("Jogador na posicao %i,%i\n", player->x, player->y);
    
    return mapa;
}

int executa_passo(int n, int m, Sala **mapa, char passo, Jogador *player) {
    if (passo == 'W') {
        player->x--;
    } else if (passo == 'S') {
        player->x++;
    } else if (passo == 'A') {
        player->y--;
    } else if (passo == 'D') {
        player->y++;
    }
    
    printf("Avancando para %i, %i...\n", player->x, player->y);
    
    if (player->y > m) {
        printf("Movimento Ilegal!\n");
        player->y--;
        return 1;
    } else if (player->x > n) {
        printf("Movimento Ilegal!\n");
        player->x--;
        return 1;
    } else if (player->x == 0) {
        player->x++;
        printf("Movimento Ilegal!\n");
        return 1;
    } else if (player->y == 0) {
        player->y++;
        printf("Movimento Ilegal!\n");
        return 1;
    }
    
    if (mapa[player->x - 1][player->y - 1].p.life > 0 &&
        mapa[player->x - 1][player->y - 1].p.attack > 0) {
        printf("Um inimigo!!!\n");
        int counter = 0;
        while (mapa[player->x - 1][player->y - 1].p.life > 0 && player->p.life > 0) {
            if (counter % 2 == 0) {
                printf("Jogador ataca!\n");
                printf("Dano de %i\n", player->p.attack);
                mapa[player->x - 1][player->y - 1].p.life -= player->p.attack;
                printf("Vida do inimigo: %i\n", mapa[player->x - 1][player->y - 1].p.life);
                counter++;
            } else if (player->escudo > 0) {
                printf("Defendeu o golpe!\n");
                player->escudo--;
                counter++;
            } else {
                printf("Inimigo ataca!\n");
                printf("Dano de %i\n", mapa[player->x - 1][player->y - 1].p.attack);
                player->p.life -= mapa[player->x - 1][player->y - 1].p.attack;
                printf("Vida do jogador: %i\n", player->p.life);
                counter++;
            }
        }
        counter = 0;
    }
    
    if (mapa[player->x - 1][player->y - 1].tesouro > 0) {
        printf("Um tesouro!\n");
        if (mapa[player->x - 1][player->y - 1].tesouro == 1) {
            printf("Jogador coleta: pocao de cura!\n");
            player->p.life += 10;
        } else if (mapa[player->x - 1][player->y - 1].tesouro == 2) {
            printf("Jogador coleta: dinheiro!\n");
            player->loot += 10;
        } else {
            printf("Jogador coleta: um escudo!\n");
            player->escudo = 1;
        }
    }
    
    if (mapa[player->x - 1][player->y - 1].armadilha > 0) {
        if (mapa[player->x - 1][player->y - 1].armadilha == 1) {
            printf("Armadilha: buraco! Jogador se machuca!\n");
            player->p.life -= 10;
        } else if (mapa[player->x - 1][player->y - 1].armadilha == 2) {
            printf("Armadilha: espinhos! Jogador se machuca!\n");
            player->p.life -= 5;
        } else {
            printf("Armadilha: ladrao! Jogador perde dinheiro!\n");
            player->loot -= 10;
            if (player->loot < 0) {
                player->loot = 0;
            }
        }
    }
    
    if (player->p.life == 0) {
        return -1;
    }
    
    return 1;
}

void imprime_status_personagem(Jogador player) {
    printf("Terminou na posicao (%i, %i)\n", player.x, player.y);
    printf("Vida: %i\n", player.p.life);
    printf("Dinheiro: %i\n", player.loot);
}

int main() {
    int n, m, movimentos, res;
    char passo;
    Jogador player;
    Sala **mapa;

    scanf("%d %d\n", &n, &m);
    mapa = cria_mapa(n, m, &player);

    scanf("%d", &movimentos);
    for (int i = 0; i < movimentos; i++) {
        scanf(" %c", &passo);
        res = executa_passo(n, m, mapa, passo, &player);
        if (res == -1) break;
    }
    res < 0 ? printf("You died...\n") : printf("Vitoria!\n");

    imprime_status_personagem(player);

    return 0;
}

