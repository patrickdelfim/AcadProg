#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*Prototipos em lib*/
#include "../lib/aluno.h"
#include "../lib/aulasDisponiveis.h"
#include "../lib/inscricoes.h"
#include "../lib/menu.h"
#include "../lib/professor.h"
#include "../lib/validadores.h"

int main() {
    /* criarData(); */

    char input;

    int id_atual_aluno = ultimoId("aluno.csv") + 1;
    int id_atual_professor = ultimoId("professor.csv") + 1;
    do {
        input = menuInicial();

        if (input == '1') {
            struct aluno alunoCadastrado;
            alunoCadastrado.cpf = malloc(sizeof(char) * 12);
            alunoCadastrado.nome = malloc(sizeof(char) * 100);
            alunoCadastrado.email = malloc(sizeof(char) * 100);

            cadastroAluno(alunoCadastrado, &id_atual_aluno);

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

            cadastroProfessor(profCadastrado, &id_atual_professor);

        } else if (input == '3') {
            struct aula aulaCadastro;

            aulaCadastro.horario = malloc(sizeof(char) * 6);
            aulaCadastro.faixa_etaria = malloc(sizeof(char) * 6);

            cadastroAula(aulaCadastro);

        } else if (input == '4') {
            inscreverAluno();

        }

        else if (input == '0') {
			getchar();
			int id1, id2;
			printf("Digite id do aluno e da aula: ");
			scanf("%d %d", &id1, &id2);

			cancelarInscricao(id1, id2);

            break;
        }

    } while (input != 'x' && input != 'X');

    return 0;
}
