#include "../lib/aulasDisponiveis.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void cadastroAula(struct aula cadastro) {
    char salvarOpcao;

    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

    printf("Digite o tipo da aula:\n");
    printf("A - Artes Maciais\n");
    printf("B - Boxe\n");
    printf("C - Crossfit\n");
    printf("D - Dança\n");

    scanf(" %c", &cadastro.tipo);
    cadastro.tipo = toupper(cadastro.tipo);

    while (cadastro.tipo != 'A' && cadastro.tipo != 'B' && cadastro.tipo != 'C' && cadastro.tipo != 'D') {
        system(clear);

        corTexto("Tipo da aula Invalido porfavor digite novamente\n", 'r');
        printf("Digite o tipo da aula:\n");
        printf("A - Artes Maciais\n");
        printf("B - Boxe\n");
        printf("C - Crossfit\n");
        printf("D - Dança\n");

        scanf(" %c", &cadastro.tipo);
        cadastro.tipo = toupper(cadastro.tipo);
    }

    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

    printf("tipo da aula: ");
    corTexto(cadastro.tipo, 'g');
    printf("\n");
    //getchar();

    printf("Digite o dia da semana: ");
    printf("1 - domingo\n");
    printf("2 - Segunda\n");
    printf("3 - Terca\n");
    printf("4 - Quarta\n");
    printf("5 - Quinta\n");
    printf("6 - Sexta\n");
    printf("7 - Sabado\n");

    scanf("%d", &cadastro.dia);

    while (cadastro.dia != 1 && cadastro.dia != 2 && cadastro.dia != 3 && cadastro.tipo != 4 && cadastro.tipo != 5 && cadastro.tipo != 6 && cadastro.tipo != 7) {
        system(clear);

        corTexto("Dia da semana Invalido porfavor digite novamente\n", 'r');
        printf("Digite o dia da semana:\n \n 1 = domingo   2 = segunda \n 3 = terca   4 = quarta \n 5 = quinta   6 = sexta \n 7 = sabado");

        scanf("%d", &cadastro.dia);
    }
    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

    printf("dia da semana: ");
    switch (cadastro.tipo) {
        case (1):
            corTexto("Domingo", 'g');
            break;
        case (2):
            corTexto("Segunda-feira", 'g');
            break;
        case (3):
            corTexto("Terca-feira", 'g');
            break;
        case (4):
            corTexto("Quarta-feira", 'g');
            break;
        case (5):
            corTexto("Quinta-feira", 'g');
            break;
        case (6):
            corTexto("Sexta-feira", 'g');
            break;
        case (7):
            corTexto("Sabado", 'g');
            break;
    }
}