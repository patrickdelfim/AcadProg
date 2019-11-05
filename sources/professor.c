#include "../lib/professor.h"  // structs e prototipos
#include "../lib/validadores.h"



void cadastroProfessor(struct professor cadastro) {



    while (1) {
        //system(clear);

        getchar();

        printf("Por favor insira as informacoes do aluno:\n\n");

        printf("CPF (apenas numeros): ");
        fgets(cadastro.cpf, 12, stdin);

        if (validarCPF(cadastro.cpf) == 1) {
             printf("Deu certo gatinho.");
            break;

        }else if(validarCPF(cadastro.cpf) == 2) {
            printf("O cpf deve conter 11 numeros.(Erro 2)");

        }else if(validarCPF(cadastro.cpf) == 3) {

            printf("O cpf nao pode ter letras.(Erro 3)");

        }else if(validarCPF(cadastro.cpf) == 4) {

            printf("O cpf nao pode ter numeros iguais.(Erro 4)");
            
        }
    }
}