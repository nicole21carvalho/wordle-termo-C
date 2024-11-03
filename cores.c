//
// Created by biosh on 03/11/2024.
//

#include "cores.h"


#define COR_PRETO 0
#define COR_AZUL 1
#define COR_VERDE 2
#define COR_AGUA 3
#define COR_VERMELHO 4
#define COR_ROXO 5
#define COR_AMARELO 6
#define COR_BRANCO 7
#define COR_CINZA 8
#define COR_AZUL_CLARO 9
#define COR_VERDE_CLARO 10
#define COR_AGUA_CLARO 11
#define COR_VERMELHO_CLARO 12
#define COR_ROSA 13
#define COR_AMARELO_CLARO 14


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backupPalavras.h"
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>

int colorir(char cor)
{
    HANDLE stdoutput;
    stdoutput = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(stdoutput, cor);
}