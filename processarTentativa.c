//
// Created by biosh on 02/11/2024.
//

#include "processarTentativa.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

bool processarTentativa(const char *tentativa, const  char *resposta, int *N) {

    char pista[6] = {'_','_','_','_','_','\0'};
    bool pistaTentativa[5] = {false, false, false, false, false};

    if(strlen(tentativa) != 5) {
        printf("Digite uma palavra com 5 letras!\n");
    } else {
        (*N)++;
        if (strcmp(tentativa, resposta) == 0) {
            return true;
        }
        // Verifica se a letra esta na posicao correta
        for (int i = 0; i < 5; i++) {
            if (tentativa[i] == resposta[i]) {
                pista[i] = 'A';
                pistaTentativa[i] = true;
            }
        }

        // Verifica se a letra existe mas em outra posicao
        for (int i = 0; i < 5; i++) {
            if (pista[i] == '_') {
                for (int j = 0; j < 6; j++) {
                    if (tentativa[i] == resposta[j] && !pistaTentativa[j]) {
                        pista[i] = 'Q';
                        pistaTentativa[i] = true;
                        break; // Acaba o loop para evitar varias pistas
                    }

                }
            }

        }


        printf("%s\n", pista);


    }




    return false;

    }

