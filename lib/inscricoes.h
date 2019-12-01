#ifndef INSCRICOES_H_
#define INSCRICOES_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  // Caso seja unix like
#define clear "clear"                                                                                   // o clear sera o comando clear
#endif

void inscreverAluno();
int salvarInscricao(int id_aluno, int id_aula);
int cancelarInscricao(int id_aluno, int id_aula);

struct relatorio {
	char tipo;
	int dia;
	char horario[5];
	char *aluno_nome;
	char *email_aluno;
	// telefone;
};

#endif

