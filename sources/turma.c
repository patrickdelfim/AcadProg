#include "../lib/turma.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

int confirmarAula(int id_professor, int id_aula) {
    FILE *aulas = fopen("data/aulas.csv", "r");
    FILE *professor = fopen("data/professor.csv", "r");
    FILE *relat = fopen("data/r_aulasconfirmadas.csv ", "w");

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

    rel.professor_nome = malloc(100);

    /*
    struct relatorio {
        char tipo;
        int dia;
        char horario[5];
        char *professor_nome;
        int qtd_aluno;
    };
*/

    do {
        fscanf(aulas, "%d,%d", &rel.tipo);

    } while (!feof(aulas));
}