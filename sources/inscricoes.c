#include "../lib/inscricoes.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void inscreverAluno() {
    int id, id_aluno, id_aula;
    int alunoValido = 0, aulaValida = 0;

    while (alunoValido == 0) {
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

        system(clear);
        if (alunoValido == 0) {
            corTexto("Id do aluno Invalido \n", 'r');
        }
    }

    while (aulaValida == 0) {
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

        system(clear);
        if (aulaValida == 0) {
            corTexto("Id da aula Invalida \n", 'r');
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