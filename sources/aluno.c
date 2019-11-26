#include "../lib/aluno.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void cadastroAluno(struct aluno cadastro, int *id_aluno) {
    char salvarOpcao;

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
            } else if (validarCPF(cadastro.cpf) == 2) {
                corTexto("O CPF deve conter 11 numeros\n", 'r');
            } else if (validarCPF(cadastro.cpf) == 3) {
                corTexto("O CPF nao contem letras\n", 'r');
            } else if (validarCPF(cadastro.cpf) == 4) {
                corTexto("O CPF nao pode conter numeros iguais\n", 'r');
            }

            printf("Por favor insira as informacoes do aluno:\n\n");

            printf("CPF (apenas numeros): ");
            fgets(cadastro.cpf, 12, stdin);
            cleanBuffer(cadastro.cpf);
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

    system(clear);

    printf("Por favor insira as informacoes do aluno:\n\n");

    printf("CPF (apenas numeros): ");
    corTexto(cadastro.cpf, 'g');
    printf("\n");

    printf("Nome: ");
    corTexto(cadastro.nome, 'g');

    printf("Email (exemplo@exemplo.com): ");
    fgets(cadastro.email, 100, stdin);

    while (!validarEMAIL(cadastro.email)) {
        system(clear);

        corTexto("O email digitado e invalido\n", 'r');
        printf("Por favor insira as informacoes do aluno:\n\n");

        printf("CPF (apenas numeros): ");
        corTexto(cadastro.cpf, 'g');
        printf("\n");

        printf("Nome: ");
        corTexto(cadastro.nome, 'g');

        printf("Email (exemplo@exemplo.com): ");
        fgets(cadastro.email, 100, stdin);
    }

    cadastro.id_aluno = *id_aluno;
    cadastro.cpf = stringNewLine(cadastro.cpf);
    cadastro.nome = stringNewLine(cadastro.nome);
    cadastro.email = stringNewLine(cadastro.email);

    system(clear);

    printf("Por favor insira as informacoes do aluno:\n\n");

    printf("CPF (apenas numeros): ");
    corTexto(cadastro.cpf, 'g');
    printf("\n");

    printf("Nome: ");
    corTexto(cadastro.nome, 'g');
    printf("\n");

    printf("Email: ");
    corTexto(cadastro.email, 'g');
    printf("\n\n");

    printf("Deseja salvar esse aluno cadastrado?\n");
    corTexto("S - Sim\t", 'g');
    corTexto("N - Nao\n", 'r');
    printf(">>> ");
    scanf(" %c", &salvarOpcao);

    int retorno;  // Verificar se o arquivo foi salvo ou nao

    if (salvarOpcao == 's' || salvarOpcao == 'S') {
        retorno = salvarAluno(cadastro);

        while (!retorno) {
            // Tenta salvar o arquivo quando ocorrer algum erro

            system(clear);

            corTexto("Erro ao abrir o arquivo\n", 'r');

            printf("Por favor insira as informacoes do aluno:\n\n");

            printf("CPF (apenas numeros): ");
            corTexto(cadastro.cpf, 'g');
            printf("\n");

            printf("Nome: ");
            corTexto(cadastro.nome, 'g');
            printf("\n");

            printf("Email (exemplo@exemplo.com): ");
            corTexto(cadastro.email, 'g');
            printf("\n\n");

            printf("Deseja salvar esse aluno cadastrado?\n");
            corTexto("S - Sim\t", 'g');
            corTexto("N - Nao\n", 'r');
            printf(">>> ");
            scanf(" %c", &salvarOpcao);

            if (salvarOpcao == 's' || salvarOpcao == 'S') {
                retorno = salvarAluno(cadastro);
            } else if (salvarOpcao == 'n' || salvarOpcao == 'N') {
                break;
            }
        }
    }

    if (retorno) {
        *id_aluno += 1;
    }
}

int salvarAluno(struct aluno aluno) {
    // Funcao para salvar o cadastro de alunos em formato CSV

    FILE *fptr = fopen("./data/aluno.csv", "a");

    if (fptr == NULL) {
        return 0;
    }

    fprintf(fptr, "%d,%s,%s,%s\n", aluno.id_aluno, aluno.cpf, aluno.nome, aluno.email);

    fclose(fptr);

    return 1;
}

struct aluno obterAlunoPorId(int id) {
	int ehValido = idValido("aluno.csv", id);
	if (ehValido == 1) {
		FILE *aluno_arq = fopen("data/aluno.csv", "r");

		struct aluno aluno;
		aluno.cpf = malloc(12);
		aluno.nome = malloc(100);
		aluno.email = malloc(100);

		do {
			fscanf(aluno_arq, "%d,%[^,],%[^,],%[^\n]\n", &aluno.id_aluno, aluno.cpf, aluno.nome, aluno.email);

			if (aluno.id_aluno == id)
				break;
			else
				if (feof(aluno_arq)) {
					aluno.id_aluno = -1;
					aluno.cpf = NULL;
					aluno.nome = NULL;
					aluno.email = NULL;

					return aluno;
				}

		} while(!feof(aluno_arq));


		fclose(aluno_arq);

		return aluno;
	} else {
		struct aluno aluno;

		aluno.cpf = malloc(12);
		aluno.nome = malloc(100);
		aluno.email = malloc(100);

		aluno.id_aluno = -1;
		aluno.cpf = NULL;
		aluno.nome = NULL;
		aluno.email = NULL;

		return aluno;
	}
}
