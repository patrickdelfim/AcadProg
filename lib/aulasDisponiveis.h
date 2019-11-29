#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/utilidade.h"
#include "../lib/validadores.h"

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  // Caso seja unix like
#define clear "clear"                                                                                   // o clear sera o comando clear
#endif

struct aula {
    int id_aula;
    int id_prof;
    int minimo;
    int maximo;
    int dia;
    char tipo;
    char *horario;
    char *faixa_etaria;
};

void cadastroAula(struct aula cadastro, int *id_aula);

int salvarAula(struct aula aula);

char *charTipoAula(char tipo);

struct aula obterAulaPorId(int id);
