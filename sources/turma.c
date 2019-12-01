#include "../lib/turma.h"  // structs e prototipos

int relAulaConfirmada() {
    FILE *aulas = fopen("data/aulas.csv", "r");
    FILE *professor = fopen("data/professor.csv", "r");
    FILE *relat = fopen("data/r_aulasconfirmadas.csv", "w");

    int idProf, idaula;

    if (aulas == NULL) {
        corTexto("Erro ao abrir o arquivo: aulas.csv\n", 'r');
        return 0;
    }
    if (professor == NULL) {
        corTexto("Erro ao abrir o arquivo: professor.csv\n", 'r');
        return 0;
    }
    if (relat == NULL) {
        corTexto("Erro ao abrir o arquivo: r_aulasconfirmadas.csv\n", 'r');
        return 0;
    }

    struct relatorio rel;

    do {
        fscanf(aulas, "%d,%d,%*[^,],%*[^,],%d,%d:%d,%c,%*[^\n]\n", &idaula, &idProf, &rel.dia, &rel.hora, &rel.minuto, &rel.tipo);

        rel.professor_nome = obterNomeProfessorPorId(idProf);
        rel.qtd_aluno = contadorAula(idaula);

        fprintf(relat, "%c,%d,%s,%s,%d\n", rel.tipo, rel.dia, horaString(rel.hora, rel.minuto), rel.professor_nome, rel.qtd_aluno);

    } while (!feof(aulas));

    fclose(aulas);
    fclose(professor);
    fclose(relat);

    return 1;
}

int contadorAula(int id_aula) {
    FILE *inscricao = fopen("data/inscricoes.csv", "r");
    int contador = 0, id_aula_f;

    if (inscricao == NULL) {
        exit(1);
    }
    do {
        fscanf(inscricao, "%*d,%d\n", &id_aula_f);

        if (id_aula == id_aula_f) {
            contador++;
        }

    } while (!feof(inscricao));

    fclose(inscricao);

    return contador;
}

int relAulaCancelada() {
    FILE *aulas = fopen("data/aulas.csv", "r");
    FILE *professor = fopen("data/professor.csv", "r");
    FILE *relat = fopen("data/r_aulascanceladas.csv", "w");

    int idProf, idAula, n_Alunos, verificador_Aula, validador;

    if (aulas == NULL) {
        corTexto("Erro ao abrir o arquivo: aulas.csv\n", 'r');
        return 0;
    }
    if (professor == NULL) {
        corTexto("Erro ao abrir o arquivo: professor.csv\n", 'r');
        return 0;
    }
    if (relat == NULL) {
        corTexto("Erro ao abrir o arquivo: r_aulasconfirmadas.csv\n", 'r');
        return 0;
    }

    printf("digite o minimo de alunos para a aula: ");
    scanf("%d", &n_Alunos);

    struct relatorio2 rel;

    do {
        fscanf(aulas, "%d,%d,%*[^,],%*[^,],%d,%d:%d,%c,%*[^\n]\n", &idAula, &idProf, &rel.dia, &rel.hora, &rel.minuto, &rel.tipo);

        verificador_Aula = contadorAula(idAula);

        rel.professor_nome = obterNomeProfessorPorId(idProf);
        rel.email = obterEmailProfessorPorId(idProf);

        if (n_Alunos > verificador_Aula) {
            validador = cancelarTodasInscricao(idAula);

            fprintf(relat, "%c,%d,%s,%s,%s\n", rel.tipo, rel.dia, horaString(rel.hora, rel.minuto), rel.professor_nome, rel.email);
        }

    } while (!feof(aulas));

    free(rel.professor_nome);
    free(rel.email);
    fclose(aulas);
    fclose(professor);
    fclose(relat);

    return 1;
}
