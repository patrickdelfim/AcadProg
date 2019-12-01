#include "../lib/inscricoes.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void inscreverAluno() {
    int id, id_aluno, id_aula;
    int alunoValido = 0, aulaValida = 0;

    while (alunoValido != 1) {
        system(clear);

        if (alunoValido == 2) {
            corTexto("Id do aluno Invalido \n", 'r');
        }

        printf("digite o Id do aluno: ");
        scanf("%d", &id_aluno);

        FILE *arq = fopen("data/aluno.csv", "r");

        do {
            fscanf(arq, "%d,%*s,%*s,%*s\n", &id);
            if (id_aluno == id) {
                alunoValido = 1;
            }
        } while (!feof(arq));
        fclose(arq);
        if (alunoValido != 1) {
            alunoValido = 2;
        }
    }

    while (aulaValida != 1) {
        system(clear);

        if (aulaValida == 2) {
            corTexto("Id da aula Invalida \n", 'r');
        }

        printf("digite o Id da aula: ");
        scanf("%d", &id_aula);

        FILE *fptr = fopen("./data/aulas.csv", "r");

        do {
            fscanf(fptr, "%d,%*c,%*d,%*s,%*d,%*d,%*s\n", &id);
            if (id_aula == id) {
                aulaValida = 1;
            }
        } while (!feof(fptr));
        fclose(fptr);

        if (aulaValida != 1) {
            aulaValida = 2;
        }
    }

    if (alunoValido == 1 && aulaValida == 1) {
        salvarInscricao(id_aluno, id_aula);
    }
}

int salvarInscricao(int id_aluno, int id_aula) {
    FILE *fptr = fopen("./data/inscricoes.csv", "a");

    if (fptr == NULL) {
        corTexto("Erro ao abrir o arquivo\n", 'r');
        return 0;
    }

    fprintf(fptr, "%d,%d\n", id_aluno, id_aula);

    fclose(fptr);

    return 1;
}

int cancelarInscricao(int id_aula, int id_aluno) {
    FILE *insc = fopen("data/inscricoes.csv", "r");
    FILE *insc_aux = fopen("data/inscricoes~.csv", "w");

    if (insc == NULL) {
        return 0;
    }

    printf("Id aluno: %d, Id aula: %d\n", id_aluno, id_aula);
    int id_aluno_l, id_aula_l;

    do {
        fscanf(insc, "%d,%d\n", &id_aula_l, &id_aluno_l);

        if (id_aula_l != id_aula || id_aluno_l != id_aluno) {
            printf("\nnao exclui %d %d", id_aula_l, id_aluno_l);
            fprintf(insc_aux, "%d,%d\n", id_aula_l, id_aluno_l);

        } else if (id_aula_l == id_aula && id_aluno_l == id_aluno) {
            printf("\nEsse foi excluido %d %d", id_aula_l, id_aluno_l);
        }

    } while (!feof(insc));

    fclose(insc);
    fclose(insc_aux);

    remove("data/inscricoes.csv");

    rename("data/inscricoes~.csv", "data/inscricoes.csv");

    return 1;
}
