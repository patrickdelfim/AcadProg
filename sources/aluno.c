#include "../lib/aluno.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void cadastroAluno(struct aluno cadastro) {
    system(clear);

    printf("Por favor insira as informacoes do aluno:\n\n");

    printf("CPF (apenas numeros): ");
    getchar();
    fgets(cadastro.cpf, 12, stdin);

    if (validarCPF(cadastro.cpf) != 1) {
        while (1) {
            system(clear);
            if (validarCPF(cadastro.cpf) == 1) {
                break;
            } else if (validarCPF(cadastro.cpf) == 0) {
                corTexto("CPF Invalido porfavor digite novamente\n", 'r');
                getchar();
            } else if (validarCPF(cadastro.cpf) == 2) {
                corTexto("O CPF deve conter 11 numeros\n", 'r');
            } else if (validarCPF(cadastro.cpf) == 3) {
                corTexto("O CPF nao contem letras\n", 'r');
                getchar();
            } else if (validarCPF(cadastro.cpf) == 4) {
                corTexto("O CPF nao pode conter numeros iguais\n", 'r');
                getchar();
            }

            printf("Por favor insira as informacoes do aluno:\n\n");

            printf("CPF (apenas numeros): ");
            fgets(cadastro.cpf, 12, stdin);
        }
    }

    system(clear);

    printf("Por favor insira as informacoes do aluno:\n\n");

    printf("CPF (apenas numeros): ");
    corTexto(cadastro.cpf, 'g');
    printf("\n");
    getchar();
    printf("Nome: ");
    fgets(cadastro.nome, 100, stdin);
    while (strlen(cadastro.nome) < 3) {
        system(clear);
        corTexto("O nome deve conter pelo menos 3 letras\n", 'r');

        printf("Por favor insira as informacoes do aluno:\n\n");

        printf("CPF (apenas numeros): ");
        corTexto(cadastro.cpf, 'g');
        printf("\n");
        printf("Nome: ");
        getchar();
        fgets(cadastro.nome, 100, stdin);
    }
}