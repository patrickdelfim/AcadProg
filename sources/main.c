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

            cadastroAluno(alunoCadastrado);

            alunoCadastrado.nome = realloc(alunoCadastrado.nome, strlen(alunoCadastrado.nome));

            // printf("%s\n", alunoCadastrado.cpf);
            // printf("%s\n", alunoCadastrado.nome);
            // printf("%d\n", strlen(alunoCadastrado.nome)); // Adicionar um realloc no nome do aluno
        }
        if (input == '2') {
            struct professor profCadastrado;

            profCadastrado.cpf = malloc(sizeof(char) * 11);

            cadastroProfessor(profCadastrado);
        }

    } while (input != 'x' && input != 'X');

    return 0;
}