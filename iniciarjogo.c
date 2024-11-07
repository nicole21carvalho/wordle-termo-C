#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "backupPalavras.h" // Inclui a lista de palavras

#define MAX_TENTATIVAS 6 // Número máximo de tentativas para cada palavra
#define TAMANHO_PALAVRA 5 // Tamanho padrão da palavra

// Estrutura para armazenar o estado do jogo
typedef struct {
    char palavra_secreta[TAMANHO_PALAVRA + 1];
    int nivel;
    int tentativas_restantes;
} Jogo;

void selecionar_palavra(char *palavra_secreta, int nivel);
void iniciar_jogo(Jogo *jogo);
void jogar(Jogo *jogo);
void exibir_status(const char *tentativa, const char *palavra_secreta);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Jogo jogo;
    iniciar_jogo(&jogo);
    jogar(&jogo);

    return 0;
}

void iniciar_jogo(Jogo *jogo) {
    printf("Bem-vindo ao Jogo Wordle!\n");
    printf("Escolha o nível de dificuldade:\n");
    printf("1 - Fácil (Palavras mais comuns)\n");
    printf("2 - Médio (Palavras moderadas)\n");
    printf("3 - Difícil (Palavras complexas)\n");
    printf("Digite o nível desejado (1, 2 ou 3): ");
    scanf("%d", &jogo->nivel);

    jogo->tentativas_restantes = MAX_TENTATIVAS;
    selecionar_palavra(jogo->palavra_secreta, jogo->nivel);

    printf("Você escolheu o nível %d. Boa sorte!\n", jogo->nivel);
}

void selecionar_palavra(char *palavra_secreta, int nivel) {
    // Carregar palavras com base no nível de dificuldade
    char *facil[] = {"CASA", "DADO", "FACA", "GATO", "RISO"};
    char *medio[] = {"CORDA", "FOLGA", "MORDA", "SORTE", "BOLSA"};
    char *dificil[] = {"ACESSO", "DINASTIA", "REFLEXO", "ARISTOCRATA", "CONCISO"};

    int indice;

    srand(time(NULL));
    switch (nivel) {
        case 1: // Fácil
            indice = rand() % (sizeof(facil) / sizeof(facil[0]));
            strcpy(palavra_secreta, facil[indice]);
            break;
        case 2: // Médio
            indice = rand() % (sizeof(medio) / sizeof(medio[0]));
            strcpy(palavra_secreta, medio[indice]);
            break;
        case 3: // Difícil
            indice = rand() % (sizeof(dificil) / sizeof(dificil[0]));
            strcpy(palavra_secreta, dificil[indice]);
            break;
        default:
            printf("Nível inválido! Selecionando nível fácil como padrão.\n");
            indice = rand() % (sizeof(facil) / sizeof(facil[0]));
            strcpy(palavra_secreta, facil[indice]);
            break;
    }
}

void jogar(Jogo *jogo) {
    char tentativa[TAMANHO_PALAVRA + 1];
    while (jogo->tentativas_restantes > 0) {
        printf("\nDigite sua tentativa (%d tentativas restantes): ", jogo->tentativas_restantes);
        scanf("%s", tentativa);

        if (strcmp(tentativa, jogo->palavra_secreta) == 0) {
            printf("Parabéns! Você acertou a palavra '%s'.\n", jogo->palavra_secreta);
            return;
        } else {
            exibir_status(tentativa, jogo->palavra_secreta);
        }

        jogo->tentativas_restantes--;
    }

    printf("Você perdeu! A palavra era '%s'.\n", jogo->palavra_secreta);
}

void exibir_status(const char *tentativa, const char *palavra_secreta) {
    int i = 0;
    while (i < TAMANHO_PALAVRA) {
        if (tentativa[i] == palavra_secreta[i]) {
            printf(" %c ", tentativa[i]); // Letra correta na posição correta
        } else if (strchr(palavra_secreta, tentativa[i])) {
            printf("(%c) ", tentativa[i]); // Letra correta na posição incorreta
        } else {
            printf(" _ "); // Letra incorreta
        }
        i++;
    }
    printf("\n");
}
