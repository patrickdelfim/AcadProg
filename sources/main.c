#include <stdio.h>
#include <string.h>

/*Prototipos em lib*/
#include "../lib/aluno.h"
#include "../lib/menu.h"
#include "../lib/professor.h"
#include "../lib/validadores.h"

int main() {
    char input;

    do {
        input = menuInicial();

        if (input == '1') {
            struct aluno alunoCadastrado;
            alunoCadastrado.cpf = malloc(sizeof(char) * 11);
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
            profCadastrado.cpf = malloc(sizeof(char) * 11);
            profCadastrado.nome = malloc(sizeof(char) * 100);
            profCadastrado.email = malloc(sizeof(char) * 100);

            cadastroProfessor(profCadastrado);
        }

    } while (input != 'x' && input != 'X');

    return 0;
}