#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  // Caso seja unix like
#define clear "clear"                                                                                   // o clear sera o comando clear
#endif

struct aluno {
    int id_aluno;
    char *cpf;
    char *nome;
    char *email;
};

void cadastroAluno(struct aluno cadastro, int *id_aluno);
int salvarAluno(struct aluno aluno);
struct aluno obterAlunoPorId(int id);

