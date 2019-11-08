#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  // Caso seja unix like
#define clear "clear"                                                                                   // o clear sera o comando clear
#endif

struct aula {
    int id_aula;
    char tipo;
    int dia;
    char *horario;
    int id_prof;
    int minimo;
    int maximo;
    char *faixa_etaria;
};

void cadastroAula(struct aula cadastro);
int salvarAula(struct aula aula);
