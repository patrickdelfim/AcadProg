#include "../lib/aluno.h"  // structs e prototipos

void cadastroAluno(struct aluno cadastro) {
    while (1) {
        system(clear);
        getchar();

        printf("Por favor insira as informacoes do aluno:\n\n");

        printf("CPF (apenas numeros): ");
        fgets(cadastro.cpf, 12, stdin);

        if (validarCPF(cadastro.cpf)) {
            break;
        }
    }
}