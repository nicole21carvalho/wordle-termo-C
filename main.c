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


        while(estadoJogo) {



            char *resposta = listaPalavras[rand() % contadorPalavra];
            int NumeroTentativas = 0;
            int *N = &NumeroTentativas;
            bool acertou_palavras = false;
            char *tentativa = malloc(6 * sizeof(char));

            colorir(COR_ROXO);
            printf(" _____ ___ ___ __ __ ___ \n");
            printf(" |_ _| __ | _  \\ \\/ |/ _ \\ \n");
            printf("  | | | _|| /  |\\/| | (_) |\n");
            printf("  |_| |___|_|_ \\_| |_|\\___/ \n");
            colorir(COR_BRANCO);
            printf("\n\n\n\n\n");
            while(NumeroTentativas < 6 && !acertou_palavras) {
                fflush(stdin);
                printf("\n\n");
                printf("Digite uma palavra com 5 letras: \n");
                fgets(tentativa, 6, stdin);
                tentativa[strcspn(tentativa, "\n")] = 0;

                acertou_palavras = processarTentativa(tentativa, resposta, N);


                printf("Tentativas: %d\n", NumeroTentativas);
            }


            if (acertou_palavras) {
                colorir(COR_VERDE);
                printf("-----------------------------------------------------\n");
                printf("               A PALAVRA ESTÁ CORRETA!                \n");
                printf("-----------------------------------------------------\n");
                colorir(COR_BRANCO);

                jogador->pontos += (7 - NumeroTentativas);
                colorir(COR_BRANCO);
                printf("\nPontução da rodada: ");
                colorir(COR_VERDE);
                printf("%d\n", 7 - NumeroTentativas);
                colorir(COR_BRANCO);
                printf("Pontuação total do jogador:");
                colorir(COR_VERDE);
                printf("%d\n", jogador->pontos);
                colorir(COR_BRANCO);




            } else {
                colorir(COR_VERMELHO);
                printf("-----------------------------------------------------\n");
                printf("               FIM DE JOGO! SEM MAIS TENTATIVAS.       \n ");
                printf("-----------------------------------------------------\n");
                colorir(COR_VERDE);
                printf("-----------------------RESPOSTA: %s------------\n", resposta);
                colorir(COR_BRANCO);

                jogador->pontos += 0;
                colorir(COR_BRANCO);
                printf("\nPontução da rodada: ");
                colorir(COR_VERDE);
                printf("%d\n", 6 - NumeroTentativas);
                colorir(COR_BRANCO);
                printf("Pontuação total do jogador:");
                colorir(COR_VERDE);
                printf("%d\n", jogador->pontos);
                colorir(COR_BRANCO);


            }

            printf("\n\n\n");



            if(!continuarJogo(&estadoJogo)) {
                free(tentativa);
                free(listaPalavras);
                free(palavra);
                free(jogador);
                break;

            }




        }






    return 0;

}

