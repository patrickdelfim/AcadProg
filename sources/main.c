#include <stdio.h>
#include <string.h>

/*Prototipos em lib*/
#include "../lib/aluno.h"
#include "../lib/aulasDisponiveis.h"
#include "../lib/menu.h"
#include "../lib/professor.h"
#include "../lib/validadores.h"

int main() {
    char input;

    do {
        input = menuInicial();

        if (input == '1') {
            struct aluno alunoCadastrado;
            alunoCadastrado.cpf = malloc(sizeof(char) * 12);
            alunoCadastrado.nome = malloc(sizeof(char) * 100);
            alunoCadastrado.email = malloc(sizeof(char) * 100);

            cadastroAluno(alunoCadastrado);

            // eu acho que temos que dar um free e salvar o arquivo dentro da funcao cadastroAluno
            // free(alunoCadastrado.cpf);
            // free(alunoCadastrado.nome);
            // free(alunoCadastrado.email);

            // printf("%s\n", alunoCadastrado.cpf);
            // printf("%s\n", alunoCadastrado.nome);
            // printf("%d\n", strlen(alunoCadastrado.nome)); // Adicionar um realloc no nome do aluno
        } else if (input == '2') {
            struct professor profCadastrado;
            profCadastrado.cpf = malloc(sizeof(char) * 12);
            profCadastrado.nome = malloc(sizeof(char) * 100);
            profCadastrado.email = malloc(sizeof(char) * 100);

            cadastroProfessor(profCadastrado);

        } else if (input == '3') {
            struct aula aulaCadastro;

            aulaCadastro.horario = malloc(sizeof(char) * 6);
            aulaCadastro.faixa_etaria = malloc(sizeof(char) * 6);

            cadastroAula(aulaCadastro);
        } else if (input == '0') {
			getchar();
			printf("%d\n", ultimoId("aluno.csv"));

/* 			for(int i = 0; i < 8; i++) { */
/* 				if (str[i] == '\0') */
/* 					printf("contra-barra zero\n"); */
/* 				else */
/* 					printf("%c\n", str[i]); */
/* 			} */

			break;
		}

    } while (input != 'x' && input != 'X');

    return 0;
}
