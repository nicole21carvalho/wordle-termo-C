
#ifndef MENU_H
#define MENU_H

#include "lib.h"


typedef struct Jogador {
    char name[50];
    int pontos;
    short lvlAtual;
} jogador_t;




void displayMenu(jogador_t *jogador, bool *estado);




#endif //MENU_H
