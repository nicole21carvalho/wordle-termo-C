#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

#include "backupPalavras.h"
#include "processarTentativa.h"
#include "cores.h"

const int MAX_PALAVRAS = 301;





bool continuarJogo() {
    char c;

    fflush(stdin);
    printf("\n Pressione S para continuar... \n");
    scanf(" %c", &c);

    if (c == 's' || c == 'S') {
        system("cls");
        return true;

    } else {
        return false;
    }
}


typedef struct jogador {
    char name[50];
    int pontos;
} jogador_t;




    int main() {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        setlocale(LC_ALL, ".UTF8");

        char **listaPalavras = calloc(MAX_PALAVRAS, sizeof(char*));
        char *palavra = malloc(6 * sizeof(char));
        int contadorPalavra = 0;
        jogador_t novo_jogador;
        jogador_t *jogador = &novo_jogador;
        jogador->pontos = 0;

    int l = 0;



        FILE *arqPalavras = fopen("../palavras.txt", "r"); // Abrindo o arquivo de palavras

        if (arqPalavras == NULL) { // Se a palavras não forem carregadas
            printf("Erro abrindo lista de palavras\nO ARQUIVO SERÁ GERADO \n \n \n \n");
            fclose(arqPalavras);
            BackupPalavras(arqPalavras); // Função que cria o arquivo necessário
        }

        arqPalavras = fopen("../palavras.txt", "r");




        // Loops para ler o arquivo e colocar as palavras em uma lista
        while(fscanf(arqPalavras, "%s", palavra) != EOF) {
            listaPalavras[contadorPalavra] = palavra;
            contadorPalavra++;
            palavra = malloc(strlen(palavra) * sizeof(char));
            printf("\n CARREGANDO %d%%", contadorPalavra * 100 / MAX_PALAVRAS);
            Sleep(10);
            fflush(stdout);
            system("cls");
        }








        fclose(arqPalavras);

        srand(time(NULL));







    colorir(COR_ROXO);
    printf("   /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                 /::\\    \\        \n");
    printf("  /::\\    \\                /::\\    \\                /::\\    \\                /::\\____\\               /::::\\    \\       \n");
    printf("  \\:::\\    \\              /::::\\    \\              /::::\\    \\              /::::|   |              /::::::\\    \\      \n");
    printf("   \\:::\\    \\            /::::::\\    \\            /::::::\\    \\            /:::::|   |             /::::::::\\    \\     \n");
    printf("    \\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /::::::|   |            /:::/~~\\:::\\    \\    \n");
    printf("     \\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/|::|   |           /:::/    \\:::\\    \\   \n");
    printf("     /::::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /:::/ |::|   |          /:::/    / \\:::\\    \\  \n");
    printf("    /::::::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /:::/  |::|___|______   /:::/____/   \\:::\\____\\ \n");
    printf("   /:::/\\:::\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\  /:::/   |::::::::\\    \\ |:::|    |     |:::|    |\n");
    printf("  /:::/  \\:::\\____\\/:::/__\\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::|    |/:::/    |:::::::::\\____\\|:::|____|     |:::|    |\n");
    printf(" /:::/    \\::/    /\\:::\\   \\:::\\   \\::/    /\\::/   |::::\\  /:::|____|\\::/    / ~~~~~/:::/    / \\:::\\    \\   /:::/    / \n");
    printf("/:::/    / \\/____/  \\:::\\   \\:::\\   \\/____/  \\/____|:::::\\/:::/    /  \\/____/      /:::/    /   \\:::\\    \\/:::/    /  \n");
    printf("/:::/    /            \\:::\\   \\:::\\    \\            |:::::::::/    /               /:::/    /     \\:::\\    /:::/    /   \n");
    printf("/:::/    /              \\:::\\   \\:::\\____\\           |::|\\::::/    /               /:::/    /       \\:::\\__/:::/    /    \n");
    printf("\\::/    /                \\:::\\   \\::/    /           |::| \\::/____/               /:::/    /         \\::::::::/    /     \n");
    printf(" \\/____/                  \\:::\\   \\/____/            |::|  ~|                    /:::/    /           \\::::::/    /      \n");
    printf("                           \\:::\\    \\                |::|   |                   /:::/    /             \\::::/    /       \n");
    printf("                            \\:::\\____\\               \\::|   |                  /:::/    /               \\::/____/        \n");
    printf("                             \\::/    /                \\:|   |                  \\::/    /                 ~~              \n");
    printf("                              \\/____/                  \\|___|                   \\/____/                                 \n");
    colorir(COR_BRANCO);
    printf("\n\n\n\n\n");


        while(true) {
            printf("\n\n\n\n\n");
            // Selecionando uma palavra aleatória da lista
            char *resposta = listaPalavras[rand() % contadorPalavra];
            int *N;
            int NumeroTentativas = 0;
            N = &NumeroTentativas;
            bool acertou_palavras = false;
            char *tentativa = malloc(6 * sizeof(char));

            while(NumeroTentativas < 6 && !acertou_palavras) {
                fflush(stdin);

                printf("\n\n");
                printf("Digite uma palavra com 5 letras: \n");
                scanf("%s", tentativa);

                acertou_palavras = processarTentativa(tentativa, resposta, N);


                printf("Tentativas: %d\n", NumeroTentativas);
            }


            if (acertou_palavras) {
                colorir(COR_VERDE);
                printf("-----------------------------------------------------\n");
                printf("               A PALAVRA ESTÁ CORRETA!                \n");
                printf("-----------------------------------------------------\n");
                colorir(COR_BRANCO);

                novo_jogador.pontos += (6 - NumeroTentativas);
                colorir(4);
                printf("\nPontução da rodada: %d\n", 6 - NumeroTentativas);
                printf("Pontuação total do jogador: %d\n", novo_jogador.pontos);
                colorir(7);

            } else {
                colorir(COR_VERMELHO);
                printf("-----------------------------------------------------\n");
                printf("               FIM DE JOGO! SEM MAIS TENTATIVAS.       \n ");
                printf("-----------------------------------------------------\n");
                colorir(COR_VERDE);
                printf("-----------------------RESPOSTA: %s------------\n", resposta);
                colorir(COR_BRANCO);
            }

            printf("\n\n\n");


            if(!continuarJogo()) {
                free(tentativa);
                free(listaPalavras);
                free(palavra);
                break;

            }




        }






    return 0;

}

