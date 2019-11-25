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

int cancelarInscricao(int id_aluno, int id_aula) {
	FILE *inscricoes = fopen("data/inscricoes.csv", "r");
	FILE *inscri = fopen("data/inscricoes~.csv", "w");
	FILE *relat = fopen("data/r_inscricoescanceladas.csv", "w");
	FILE *aluno = fopen("data/aluno.csv", "r");
	FILE *aulas = fopen("data/aulas.csv", "r");

	if (inscricoes == NULL) {
		corTexto("Erro ao abrir o arquivo: inscricoes.csv\n", 'r');
		return 0;
	} if (relat == NULL) {
		corTexto("Erro ao abrir o arquivo: r_inscricoescanceladas.csv\n", 'r');
		return 0;
	} if (aluno == NULL) {
		corTexto("Erro ao abrir o arquivo: aluno.csv\n", 'r');
		return 0;
	} if (aulas == NULL) {
		corTexto("Erro ao abrir o arquivo: aluno.csv\n", 'r');
		return 0;
	}


	struct relatorio {
		char tipo;
		int dia;
		char horario[5];
		char *aluno_nome;
		char *email_aluno;
		// telefone;
	};
	
	struct relatorio rel;

	rel.aluno_nome = malloc(100);
	rel.email_aluno = malloc(100);

	int id_aluno_i, id_aula_i;
    do {
		fscanf(inscricoes, "%d,%d", &id_aluno_i, &id_aula_i);

		if(id_aluno_i == id_aluno && id_aula_i == id_aula) {
			do {
				fscanf(aluno, "%d,%*s,%s,%s", &id_aluno_i, rel.aluno_nome, rel.email_aluno);

				if (id_aluno_i == id_aluno) {
					break;
				}
			} while (!feof(aluno));

			do {
				fscanf(aulas, "%d,%c,%d,%s,%*d,%*d,%*s", &id_aula_i, &rel.tipo, &rel.dia, rel.horario);

				if (id_aula_i == id_aula) {
					break;
				}
			} while(!feof(aulas));
			
			break;
		}
    } while (!feof(inscricoes));

	printf("tipo: %c\n", rel.tipo);
	printf("horario: %s\n", rel.horario);
	printf("dia: %d\n", rel.dia);
	printf("nome: %s\n", rel.aluno_nome);
	printf("email: %s\n", rel.email_aluno);

	fclose(inscricoes);
	fclose(inscri);
	fclose(relat);
	fclose(aluno);
	fclose(aulas);

	remove("data/inscricoes~.csv");

	return 1;
}
