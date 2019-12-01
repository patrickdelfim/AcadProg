#include "../lib/professor.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void cadastroProfessor(struct professor cadastro, int *id_professor) {
    char salvarOpcao;

    system(clear);

    printf("Por favor insira as informacoes do professor:\n\n");

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

            printf("Por favor insira as informacoes do professor:\n\n");

            printf("CPF (apenas numeros): ");
            fgets(cadastro.cpf, 12, stdin);
        }
    }

    system(clear);

    printf("Por favor insira as informacoes do professor:\n\n");

    printf("CPF (apenas numeros): ");
    corTexto(cadastro.cpf, 'g');
    printf("\n");
    getchar();
    printf("Nome: ");
    fgets(cadastro.nome, 100, stdin);
    while (strlen(cadastro.nome) < 3) {
        system(clear);
        corTexto("O nome deve conter pelo menos 3 letras\n", 'r');

        printf("Por favor insira as informacoes do professor:\n\n");

        printf("CPF (apenas numeros): ");
        corTexto(cadastro.cpf, 'g');
        printf("\n");
        printf("Nome: ");
        getchar();
        fgets(cadastro.nome, 100, stdin);
    }

    system(clear);

    printf("Por favor insira as informacoes do professor:\n\n");

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
        printf("Por favor insira as informacoes do professor:\n\n");

        printf("CPF (apenas numeros): ");
        corTexto(cadastro.cpf, 'g');
        printf("\n");

        printf("Nome: ");
        corTexto(cadastro.nome, 'g');

        printf("Email: ");
        fgets(cadastro.email, 100, stdin);
    }

    cadastro.id_professor = *id_professor;
    cadastro.cpf = stringNewLine(cadastro.cpf);
    cadastro.nome = stringNewLine(cadastro.nome);
    cadastro.email = stringNewLine(cadastro.email);

    system(clear);

    printf("Por favor insira as informacoes do professor:\n\n");

    printf("CPF (apenas numeros): ");
    corTexto(cadastro.cpf, 'g');
    printf("\n");

    printf("Nome: ");
    corTexto(cadastro.nome, 'g');
    printf("\n");

    printf("Email (exemplo@exemplo.com): ");
    corTexto(cadastro.email, 'g');
    printf("\n\n");

    printf("Deseja salvar esse professor cadastrado?\n");
    corTexto("S - Sim\t", 'g');
    corTexto("N - Nao\n", 'r');
    printf(">>> ");
    scanf(" %c", &salvarOpcao);

    int retorno;  // Verificar se o arquivo foi salvo ou nao

    if (salvarOpcao == 's' || salvarOpcao == 'S') {
        retorno = salvarProfessor(cadastro);

        while (!retorno) {
            // Tenta salvar o arquivo quando ocorrer algum erro

            system(clear);

            corTexto("Erro ao abrir o arquivo\n", 'r');

            printf("Por favor insira as informacoes do professor:\n\n");

            printf("CPF (apenas numeros): ");
            corTexto(cadastro.cpf, 'g');
            printf("\n");

            printf("Nome: ");
            corTexto(cadastro.nome, 'g');
            printf("\n");

            printf("Email (exemplo@exemplo.com): ");
            corTexto(cadastro.email, 'g');
            printf("\n\n");

            printf("Deseja salvar esse professor cadastrado?\n");
            corTexto("S - Sim\t", 'g');
            corTexto("N - Nao\n", 'r');
            printf(">>> ");
            scanf(" %c", &salvarOpcao);

            if (salvarOpcao == 's' || salvarOpcao == 'S') {
                retorno = salvarProfessor(cadastro);
            } else if (salvarOpcao == 'n' || salvarOpcao == 'N') {
                break;
            }
        }
    }
    if (retorno) {
        *id_professor += 1;
    }
}

int salvarProfessor(struct professor professor) {
    // Funcao para salvar o cadastro de professores em formato CSV

    FILE *fptr = fopen("./data/professor.csv", "a");

    if (fptr == NULL) {
        return 0;
    }

    fprintf(fptr, "%d,%s,%s,%s\n", professor.id_professor, professor.cpf, professor.nome, professor.email);

    fclose(fptr);

    return 1;
}

struct professor obterProfessorPorId(int id) {
    int ehValido = idValido("professor.csv", id);
    if (ehValido == 1) {
        FILE *professor_arq = fopen("data/professor.csv", "r");

        struct professor professor;
        professor.cpf = malloc(12);
        professor.nome = malloc(100);
        professor.email = malloc(100);

        do {
            fscanf(professor_arq, "%d,%[^,],%[^,],%[^\n]\n", &professor.id_professor, professor.cpf, professor.nome, professor.email);

            if (professor.id_professor == id)
                break;
            else if (feof(professor_arq)) {
                professor.id_professor = -1;
                professor.cpf = NULL;
                professor.nome = NULL;
                professor.email = NULL;

                return professor;
            }

        } while (!feof(professor_arq));

        fclose(professor_arq);

        return professor;
    } else {
        struct professor professor;

        professor.cpf = malloc(12);
        professor.nome = malloc(100);
        professor.email = malloc(100);

        professor.id_professor = -1;
        professor.cpf = NULL;
        professor.nome = NULL;
        professor.email = NULL;

        return professor;
    }
}

char *obterNomeProfessorPorId(int id) {
    int ehValido = idValido("professor.csv", id);
    if (ehValido == 1) {
        FILE *professor_arq = fopen("data/professor.csv", "r");

        char *nome_Professor;
        int id_prof;

        nome_Professor = malloc(100);

        do {
            fscanf(professor_arq, "%d,%*[^,],%[^,],%*[^\n]\n", &id_prof, nome_Professor);

            if (id_prof == id)
                break;

        } while (!feof(professor_arq));

        fclose(professor_arq);

        return nome_Professor;
    }
}
