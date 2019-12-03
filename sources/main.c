#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*Prototipos em lib*/
#include "../lib/aluno.h"
#include "../lib/aulasDisponiveis.h"
#include "../lib/inscricoes.h"
#include "../lib/menu.h"
#include "../lib/professor.h"
#include "../lib/turma.h"
#include "../lib/validadores.h"

int main() {
    /* criarData(); */

    char input;

    int id_atual_aula = ultimoId("aulas.csv") + 1;
    int id_atual_aluno = ultimoId("aluno.csv") + 1;
    int id_atual_professor = ultimoId("professor.csv") + 1;
    int id_aula;
    int id_aluno;
    int validarAula = 1;
    int validarAluno = 1;
    do {
        input = menuInicial();

        if (input == '1') {
            // cadastro aluno

            struct aluno alunoCadastrado;
            alunoCadastrado.cpf = malloc(sizeof(char) * 12);
            alunoCadastrado.nome = malloc(sizeof(char) * 100);
            alunoCadastrado.email = malloc(sizeof(char) * 100);

            cadastroAluno(alunoCadastrado, &id_atual_aluno);

            free(alunoCadastrado.cpf);
            free(alunoCadastrado.nome);
            free(alunoCadastrado.email);

        } else if (input == '2') {
            // cadastro professor

            struct professor profCadastrado;
            profCadastrado.cpf = malloc(sizeof(char) * 12);
            profCadastrado.nome = malloc(sizeof(char) * 100);
            profCadastrado.email = malloc(sizeof(char) * 100);

            cadastroProfessor(profCadastrado, &id_atual_professor);

            free(profCadastrado.cpf);
            free(profCadastrado.nome);
            free(profCadastrado.email);

        } else if (input == '3') {
            // cadastro aula

            struct aula aulaCadastro;

            aulaCadastro.faixa_etaria = malloc(sizeof(char) * 6);

            cadastroAula(aulaCadastro, &id_atual_aula);

            free(aulaCadastro.faixa_etaria);

        } else if (input == '4') {
            // inscrever aluno em aula

            inscreverAluno();
        } else if (input == '5') {
            // cancelar inscricao de aluno e gerar relatorio organizado

            do {
                system(clear);
                if (validarAluno != 1) {
                    corTexto("Erro no id do aluno. Tente novamente!!\n", 'r');
                }
                if (validarAula != 1) {
                    corTexto("Erro no id da aula. Tente novamente!!\n", 'r');
                }
                printf("digite o id do aluno: ");
                scanf("%d", &id_aluno);
                printf("digite o id da aula: ");
                scanf("%d", &id_aula);

                validarAluno = idValido("aluno.csv", id_aluno);
                validarAula = idValido("aulas.csv", id_aula);

            } while (validarAluno != 1 || validarAula != 1);

            cancelarInscricao(id_aluno, id_aula);

            ordenarRelatorioInscCanceladas();

        } else if (input == '6') {
            // gerar relatorio de aula cancelada e organizar de forma cronologica

            relAulaCancelada();
            ordenarRelatorioAulasCanceladas();
        } else if (input == '7') {
            // gerar relatorio de aula confirmada e organizar de forma cronologica

            relAulaConfirmada();

            ordenarRelatorioAulasConfirmadas();
        }

        else if (input == '0') {
            ordenarRelatorioInscCanceladas();

            ordenarRelatorioAulasConfirmadas();
            ordenarRelatorioAulasCanceladas();

            break;
        }

    } while (input != 'x' && input != 'X');

    return 0;
}
