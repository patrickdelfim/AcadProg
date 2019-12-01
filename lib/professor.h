#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  // Caso seja unix like
#define clear "clear"                                                                                   // o clear sera o comando clear
#endif

struct professor {
    int id_professor;
    char *cpf;
    char *nome;
    char *email;
};

void cadastroProfessor(struct professor cadastro, int *id_professor);

int salvarProfessor(struct professor professor);

struct professor obterProfessorPorId(int id);

char *obterNomeProfessorPorId(int id);
char *obterEmailProfessorPorId(int id);
#endif
