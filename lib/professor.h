#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#ifdef linux           // Caso seja linux
#define clear "clear"  // o clear sera o comando clear
#endif

struct professor {
    char *cpf;
};

void cadastroProfessor(struct professor cadastro);