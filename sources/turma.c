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

    free(rel.professor_nome);
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

/*Funcao de gerar relatorio de aula cancelada tambem exercendo a as funcoes
de deletar todas as ocorrencias do id da aula em incricoes, atualizando o arquivo de aulas confirmadas
e deletando a aula do arquivo aula.csv*/

int relAulaCancelada() {
    FILE *aulas = fopen("data/aulas.csv", "r");
    FILE *professor = fopen("data/professor.csv", "r");
    FILE *relat = fopen("data/r_aulascanceladas.csv", "w");

    int idProf, idAula, n_Alunos, verificador_Aula, validador, validadorDelAula, validadorConfAulas;

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
            //if (validador == 0)
            //  return 0;
            validadorDelAula = deletarAulaCancelada(idAula);
            //if (validadorDelAula == 0)
            // return 0;
            validadorConfAulas = relAulaConfirmada();
            //if (validadorConfAulas == 0)
            //  return 0;

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

int deletarAulaCancelada(int idAula) {
    FILE *aulas = fopen("data/aulas.csv", "r");
    FILE *aulas_aux = fopen("data/aulas~.csv", "w");

    if (aulas == NULL)
        return 0;

    struct aula aula;

    aula.faixa_etaria = malloc(100);
    do {
        fscanf(aulas, "%d,%d,%d,%d,%d,%d:%d,%c,%[^\n]\n",  // Formatacao do arquivo

               &aula.id_aula,  // Campos organizados
               &aula.id_prof,
               &aula.minimo,
               &aula.maximo,
               &aula.dia,
               &aula.hora,
               &aula.minuto,
               &aula.tipo,
               aula.faixa_etaria);

        if (aula.id_aula != idAula)

            fprintf(
                aulas_aux,
                "%d,%d,%d,%d,%d,%s,%c,%s\n",
                aula.id_aula,
                aula.id_prof,
                aula.minimo,
                aula.maximo,
                aula.dia,
                horaString(aula.hora, aula.minuto),
                aula.tipo,
                aula.faixa_etaria);

        else if (aula.id_aula == idAula)
            printf("exclui um ai 2\n");

    } while (!feof(aulas));

    fclose(aulas);
    fclose(aulas_aux);

    remove("data/aulas.csv");

    rename("data/aulas~.csv", "data/aulas.csv");

    return 1;
}

/* ===============================================
        Ordenacao do relatorio aulas Confirmadas
   =============================================== */

int ordenarRelatorioAulasConfirmadas() {
    FILE *relat = fopen("data/r_aulasconfirmadas.csv", "r");
    FILE *aux = fopen("data/aux.csv", "w");

    if (relat == NULL)
        return 0;
    if (aux == NULL)
        return 0;

    struct relatorio *lista = listarAulasConfirmadas();
    int tam = contarLinha("r_aulasconfirmadas.csv");

    for (int j = 0; j < tam - 1; j++) {
        for (int i = 0; i < tam - 1 - j; i++) {
            //ordenado = 0;
            if (lista[i].dia < lista[i + 1].dia) {
                trocarRelatorioAulasConfirmadas(&lista[i], &lista[i + 1]);
            } else if (lista[i].dia == lista[i + 1].dia && lista[i].hora < lista[i + 1].hora) {
                trocarRelatorioAulasConfirmadas(&lista[i], &lista[i + 1]);
            } else if (lista[i].dia == lista[i + 1].dia && lista[i].hora == lista[i + 1].hora && lista[i].minuto < lista[i + 1].minuto) {
                trocarRelatorioAulasConfirmadas(&lista[i], &lista[i + 1]);
            }
        }
    }

    for (int i = 0; i < tam; i++) {
        fprintf(aux, "%c,%d,%d:%d,%s,%d\n",

                lista[i].tipo,
                lista[i].dia,
                lista[i].hora,
                lista[i].minuto,
                lista[i].professor_nome,
                lista[i].qtd_aluno);
    }

    fclose(relat);
    fclose(aux);

    remove("data/r_aulasconfirmadas.csv");

    rename("data/aux.csv", "data/r_aulasconfirmadas.csv");

    for (int i = 0; i < tam; i++) {
        printf("%c ", lista[i].tipo);
        printf("%d\n", lista[i].dia);
    }
}

struct relatorio *listarAulasConfirmadas() {
    FILE *relat = fopen("data/r_aulasconfirmadas.csv", "r");

    if (relat == NULL)
        return NULL;

    int tam = contarLinha("r_aulasconfirmadas.csv");

    struct relatorio *relat_lista;
    relat_lista = malloc(sizeof(*relat_lista) * tam);

    int i = 0;

    do {
        relat_lista[i].professor_nome = malloc(100);

        fscanf(
            relat,

            "%c,%d,%d:%d,%[^,],%d\n",

            &relat_lista[i].tipo,
            &relat_lista[i].dia,
            &relat_lista[i].hora,
            &relat_lista[i].minuto,
            relat_lista[i].professor_nome,
            &relat_lista[i].qtd_aluno);

        i++;
    } while (!feof(relat));

    fclose(relat);

    return relat_lista;
}
void trocarRelatorioAulasConfirmadas(struct relatorio *relat1, struct relatorio *relat2) {
    // TODO:
    // invereter a posicao dos relatorios na lista!

    struct relatorio temp = *relat1;

    *relat1 = *relat2;
    *relat2 = temp;
}

/* ===============================================
        Ordenacao do relatorio aulas canceladas
   =============================================== */

int ordenarRelatorioAulasCanceladas() {
    FILE *relat = fopen("data/r_aulascanceladas.csv", "r");
    FILE *aux = fopen("data/aux.csv", "w");

    if (relat == NULL)
        return 0;
    if (aux == NULL)
        return 0;

    struct relatorio2 *lista = listarAulasCanceladas();
    int tam = contarLinha("r_aulascanceladas.csv");

    for (int j = 0; j < tam - 1; j++) {
        for (int i = 0; i < tam - 1 - j; i++) {
            //ordenado = 0;
            if (lista[i].dia < lista[i + 1].dia) {
                trocarRelatorioAulasCanceladas(&lista[i], &lista[i + 1]);
            } else if (lista[i].dia == lista[i + 1].dia && lista[i].hora < lista[i + 1].hora) {
                trocarRelatorioAulasCanceladas(&lista[i], &lista[i + 1]);
            } else if (lista[i].dia == lista[i + 1].dia && lista[i].hora == lista[i + 1].hora && lista[i].minuto < lista[i + 1].minuto) {
                trocarRelatorioAulasCanceladas(&lista[i], &lista[i + 1]);
            }
        }
    }

    for (int i = 0; i < tam; i++) {
        fprintf(aux, "%c,%d,%d:%d,%s,%s\n",

                lista[i].tipo,
                lista[i].dia,
                lista[i].hora,
                lista[i].minuto,
                lista[i].professor_nome,
                lista[i].email);
    }

    fclose(relat);
    fclose(aux);

    remove("data/r_aulascanceladas.csv");

    rename("data/aux.csv", "data/r_aulascanceladas.csv");

    for (int i = 0; i < tam; i++) {
        printf("%c ", lista[i].tipo);
        printf("%d\n", lista[i].dia);
    }
}

struct relatorio2 *listarAulasCanceladas() {
    FILE *relat = fopen("data/r_aulascanceladas.csv", "r");

    if (relat == NULL)
        return NULL;

    int tam = contarLinha("r_aulascanceladas.csv");

    struct relatorio2 *relat_lista;
    relat_lista = malloc(sizeof(*relat_lista) * tam);

    int i = 0;

    do {
        relat_lista[i].professor_nome = malloc(100);
        relat_lista[i].email = malloc(100);

        fscanf(
            relat,

            "%c,%d,%d:%d,%[^,],%[^\n]\n",

            &relat_lista[i].tipo,
            &relat_lista[i].dia,
            &relat_lista[i].hora,
            &relat_lista[i].minuto,
            relat_lista[i].professor_nome,
            relat_lista[i].email);

        i++;
    } while (!feof(relat));

    fclose(relat);

    return relat_lista;
}
void trocarRelatorioAulasCanceladas(struct relatorio2 *relat1, struct relatorio2 *relat2) {
    // TODO:
    // invereter a posicao dos relatorios na lista!

    struct relatorio2 temp = *relat1;

    *relat1 = *relat2;
    *relat2 = temp;
}