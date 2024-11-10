cmake_minimum_required(VERSION 3.29)
project(Wordle C)

set(CMAKE_C_STANDARD 23)

add_executable(Wordle main.c
        lib/backupPalavras.c
        lib/backupPalavras.h
        lib/processarTentativa.c
        lib/processarTentativa.h
        lib/cores.c
        lib/cores.h
        lib/backupPalavras.c
        lib/menu.c
        lib/menu.h
        lib/lib.h
)
