#include "lib/lib.h"

const int MAX_PALAVRAS = 301;






    int main() {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        setlocale(LC_ALL, ".UTF8");

        bool estadoJogo = true;
        bool *state = &estadoJogo;
        jogador_t *jogador = malloc(sizeof(jogador_t));
        jogador->pontos = 0;

        displayMenu(jogador, state);


        while(estadoJogo) {


            char **listaPalavras = calloc(MAX_PALAVRAS, sizeof(char*));
            char *palavra = malloc(6 * sizeof(char));
            int contadorPalavra = 0;



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
                palavra = malloc(6 * sizeof(char));
                printf("\n CARREGANDO %d%%", contadorPalavra * 100 / MAX_PALAVRAS);
                Sleep(10);
                fflush(stdout);

            }
            system("cls");



            fclose(arqPalavras);

            srand(time(NULL));


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

                jogador->pontos += (6 - NumeroTentativas);
                colorir(4);
                printf("\nPontução da rodada: %d\n", 6 - NumeroTentativas);
                printf("Pontuação total do jogador: %d\n", jogador->pontos);
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

