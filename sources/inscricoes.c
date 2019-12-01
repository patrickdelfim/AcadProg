#include "../lib/inscricoes.h"  // structs e prototipos

void inscreverAluno() {
    int id, id_aluno, id_aula;
    int alunoValido = 0, aulaValida = 0;

    printf("digite o Id do aluno: ");
    scanf("%d", &id_aluno);

    printf("digite o Id da aula: ");
    scanf("%d", &id_aula);

    alunoValido = idValido("aluno.csv", id_aluno);
    aulaValida = idValido("aula.csv", id_aula);

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
    FILE *insc = fopen("data/inscricoes.csv", "r");
    FILE *insc_aux = fopen("data/inscricoes~.csv", "w");

    int relatorio = relatorioInscricaoCancelada(id_aluno, id_aula);

    if (relatorio != 0)
        return 0;

    if (insc == NULL)
        return 0;

    int id_aluno_l, id_aula_l;

    do {
        fscanf(insc, "%d,%d\n", &id_aluno_l, &id_aula_l);

        if (id_aula_l != id_aula || id_aluno_l != id_aluno)
            fprintf(insc_aux, "%d,%d\n", id_aluno_l, id_aula_l);
        else if (id_aula_l == id_aula && id_aluno_l == id_aluno)
            printf("exclui um ai\n");

    } while (!feof(insc));

    fclose(insc);
    fclose(insc_aux);

    remove("data/inscricoes.csv");

    rename("data/inscricoes~.csv", "data/inscricoes.csv");

    return 1;
}

int cancelarTodasInscricao(int id_aula) {
    FILE *insc = fopen("data/inscricoes.csv", "r");
    FILE *insc_aux = fopen("data/inscricoes~.csv", "w");

    if (insc == NULL)
        return 0;

    int id_aluno_l, id_aula_l;

    do {
        fscanf(insc, "%d,%d\n", &id_aluno_l, &id_aula_l);

        if (id_aula_l != id_aula)
            fprintf(insc_aux, "%d,%d\n", id_aluno_l, id_aula_l);
        else if (id_aula_l == id_aula)
            printf("exclui um ai\n");

    } while (!feof(insc));

    fclose(insc);
    fclose(insc_aux);

    remove("data/inscricoes.csv");

    rename("data/inscricoes~.csv", "data/inscricoes.csv");

    return 1;
}

int relatorioInscricaoCancelada(int id_aluno, int id_aula) {
    FILE *relat = fopen("data/r_inscricoescanceladas.csv", "a");

    printf("oi\n");
    if (relat == NULL)
        return 0;

    struct aluno aluno;

    aluno.cpf = malloc(11);
    aluno.nome = malloc(100);
    aluno.email = malloc(100);

    aluno = obterAlunoPorId(id_aluno);

    if (aluno.id_aluno == -1)
        return 0;

    struct aula aula;

    aula.faixa_etaria = malloc(5);

    aula = obterAulaPorId(id_aula);

    if (aula.id_aula == -1)
        return 0;

    struct relatorio rel;

    rel.aluno_nome = malloc(sizeof(aluno.nome));
    rel.email_aluno = malloc(sizeof(aluno.email));

    rel.tipo = aula.tipo;
    rel.dia = aula.dia;
    rel.hora = aula.hora;
    rel.minuto = aula.minuto;
    rel.aluno_nome = aluno.nome;
    rel.email_aluno = aluno.email;

    fprintf(
        relat,

        "%c,%d,%s,%s,%s",

        rel.tipo,
        rel.dia,
        horaString(rel.hora, rel.minuto),
        rel.aluno_nome,
        rel.email_aluno);

    fclose(relat);

    free(aluno.cpf);
    free(aluno.nome);
    free(aluno.email);
    free(aula.faixa_etaria);
    free(rel.aluno_nome);
    free(rel.email_aluno);

    return 1;
}
