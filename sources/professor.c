#include "../lib/professor.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"



void cadastroProfessor(struct professor cadastro) {

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
								corTexto("O CPF esta invalido", 'r');
						} else if(validarCPF(cadastro.cpf) == 2) {
								corTexto("O cpf deve conter 11 numeros.\n", 'r');

						}else if(validarCPF(cadastro.cpf) == 3) {

								corTexto("O cpf nao pode ter letras.\n", 'r');
								getchar();

						}else if(validarCPF(cadastro.cpf) == 4) {

								corTexto("O cpf nao pode ter numeros iguais.\n", 'r');
								getchar();
								
						}

						printf("Por favor insira as informacoes do professor:\n\n");

						printf("CPF (apenas numeros): ");
						fgets(cadastro.cpf, 12, stdin);

				}
		}
}
