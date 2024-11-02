
#include "backupPalavras.h"

#include <locale.h>


void BackupPalavras(FILE *arquivo) {

    setlocale(LC_ALL, "Portuguese");


    arquivo = fopen("../palavras.txt", "a");
    char *backupPalavras[] = {
        "FESTA", "PAPEL", "GATOS", "MANGA", "AMIGO",
        "BOLAS", "CHEIO", "DENTE", "VENTO", "CERTA",
        "SAÚDE", "SORTE", "NOTAS", "PLENO", "FOLHA",
        "CINTO", "VINHA", "JOVEM", "ÁGUA", "BATER",
        "CURVA", "DOIDO", "ENFIM", "FARDO", "GARFO",
        "HOTEL", "JANTA", "LIGAR", "MOVER", "NOBRE",
        "OSSOS", "PADRE", "QUASE", "ROUPA", "SABOR",
        "TARDE", "URANO", "VIVER", "XEQUE", "ZONAL",
        "ADUBO", "BEBER", "CHUVA", "DENTE", "EXATO",
        "FOLGA", "ABRIU", "BRISA", "GRATO", "HORTA",
        "JUROS", "MARCHA", "PLANTA", "QUEDA", "REZAR",
        "SAMPA", "TIGRE", "VARAL", "ZUMBI",
        "ALOHA", "BAIXO", "CALMA", "DUCHA", "ENTAO",
        "FERVO", "GANHO", "HUMOR", "IDEIA", "JOVEM",
        "LETRA", "MANIA", "OBTER", "POSAR", "RITMO",
        "SALVO", "TURMA", "URINA", "VIRAR", "ZEALO",
        "BRASA", "TREVO", "VIOLA", "QUERO", "RENDA",
        "DITAR", "LIVRO", "ÓRGÃO", "CAFÉ", "VAZIO",
        "PECAR", "BOINA", "NAVIO", "CHEFE", "SIGLA",
        "RISCO", "MUDAR", "PUNIR", "TIROS", "CHÃOS",
        "SÉRIE", "CERTO", "DUROS", "LOIRO", "PODER",
        "BOLSO", "FALSA", "MOTEL", "HOTEL", "JUBAS"

    };

    for (int i = 0; i < sizeof(backupPalavras) / sizeof(char *); i++) {
        fprintf(arquivo, "%s \n", backupPalavras[i]);
    }

    fclose(arquivo);
};