#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

#include "backupPalavras.h"
#include "processarTentativa.h"


const int MAX_PALAVRAS = 150;


bool continuarJogo() {
    char c;
    fflush(stdin);
    printf("\n Pressione S para continuar... \n");
    scanf(" %c", &c);

    if (c == 's' || c == 'S') {
        return true;

    } else {
        return false;
    }
}



    int main() {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        setlocale(LC_ALL, ".UTF8");

        char **listaPalavras = calloc(MAX_PALAVRAS, sizeof(char*));
        char *palavra = malloc(6 * sizeof(char));
        int contadorPalavra = 0;



        FILE *arqPalavras = fopen("../palavras.txt", "r"); // Abrindo o arquivo de palavras

        if (arqPalavras == NULL) { // Se a palavras não forem carregadas
            printf("Erro abrindo lista de palavras\n");
            fclose(arqPalavras);
            BackupPalavras(arqPalavras); // Função que cria o arquivo necessário
        }



        // Loops para ler o arquivo e colocar as palavras em uma lista
        while(fscanf(arqPalavras, "%s", palavra) != EOF) {
            listaPalavras[contadorPalavra] = palavra;
            contadorPalavra++;
            palavra = malloc(strlen(palavra) * sizeof(char));
        }


        // Selecionando uma palavra aleatória da lista
        srand(time(NULL));

        bool estadoJogo = true;


        while(true) {
            char *resposta = listaPalavras[rand() % contadorPalavra];
            int *N;
            int NumeroTentativas = 0;
            N = &NumeroTentativas;
            bool acertou_palavras = false;
            char *tentativa = malloc(6 * sizeof(char));

            while(NumeroTentativas < 6 && !acertou_palavras) {
                fflush(stdin);
                printf("Digite uma palavra com 5 letras: \n");
                scanf("%s", tentativa);

                acertou_palavras = processarTentativa(tentativa, resposta, N);


                printf("Tentativas: %d\n", NumeroTentativas);
            }

            if (acertou_palavras) {
                printf("-----------------------------------------------------\n");
                printf("               A PALAVRA ESTÁ CORRETA!                \n");
                printf("-----------------------------------------------------\n");

            } else {
                printf("-----------------------------------------------------\n");
                printf("               FIM DE JOGO! SEM MAIS TENTATIVAS.       \n");
                printf("-----------------------------------------------------\n");
            }

            printf("\n\n\n");


            if(!continuarJogo()) {
                break;

            }




        }
    return 0;

}

