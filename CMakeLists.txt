cmake_minimum_required(VERSION 3.29)
project(Wordle C)

set(CMAKE_C_STANDARD 23)

add_executable(Wordle main.c
        backupPalavras.c
        backupPalavras.h
        processarTentativa.c
        processarTentativa.h)
