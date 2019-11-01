#include <stdio.h>

struct aluno {

int id;
char nome[50];
char cpf[11];
char telefone[10];
char email[50];
};

void menuInicial();
/* void cadastroAluno(struct aluno *cadastro); */

int main () {
	char opcao;
 
	menuInicial();

	do {
		printf(">>> "); opcao = getchar();

	}while(opcao != 'x' && opcao != 'X');

	/* struct aluno aluno1; */

	/* cadastroAluno(&aluno1); */

	/* printf("O nome do aluno eh %s\n",aluno1.nome); */
	/* printf("O cpf do aluno eh %s\n",aluno1.cpf); */
	/* printf("O telefone do aluno eh %s\n",aluno1.telefone); */
	/* printf("O email do aluno eh %s\n",aluno1.email); */

  return 0;
}

void menuInicial () {
	printf("Bem Vindo!\n\n");
	printf("Escolha uma opção:\n");
	printf("1 - Cadastro de aluno\n");
	printf("\n\e[0;31;49mX - Sair\e[0m\n");
}

/* void cadastroAluno(struct aluno *cadastro){*/
/* 	printf("<------- CADASTRO DO ALUNO ------->\n");*/


/* 	printf("digite o nome do aluno:");*/
/* 	gets(cadastro->nome); // ponteiro*/

/* 	printf("digite o Cpf do aluno:");*/

/* 	gets(cadastro->cpf); // ponteiro*/

/* 	printf("digite o Telefone do aluno:");*/

/* 	gets(cadastro->telefone); // ponteiro*/

/* 	printf("digite o Email do aluno:");*/

/* 	gets(cadastro->email); // ponteiro*/

/* 	 talvez usar getchar(); a partir do segundo gets*/
/* }*/
