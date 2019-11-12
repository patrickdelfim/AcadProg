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

    printf(">>> ");
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

        printf(">>> ");
        scanf(" %c", &cadastro.tipo);
        cadastro.tipo = toupper(cadastro.tipo);
    }

    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

    printf("tipo da aula: %c", cadastro.tipo);
    /* corTexto(cadastro.tipo, 'g'); */
    printf("\n");
    //getchar();

    printf("Digite o dia da semana: \n");
    printf("1 - domingo\n");
    printf("2 - Segunda\n");
    printf("3 - Terca\n");
    printf("4 - Quarta\n");
    printf("5 - Quinta\n");
    printf("6 - Sexta\n");
    printf("7 - Sabado\n");

    printf(">>> ");
    scanf("%d", &cadastro.dia);

    while (cadastro.dia != 1 && cadastro.dia != 2 && cadastro.dia != 3 && cadastro.dia != 4 && cadastro.dia != 5 && cadastro.dia != 6 && cadastro.dia != 7) {
        system(clear);

        corTexto("Dia da semana Invalido porfavor digite novamente\n \n", 'r');
        printf("Digite o dia da semana: \n");
        printf("1 - domingo\n");
        printf("2 - Segunda\n");
        printf("3 - Terca\n");
        printf("4 - Quarta\n");
        printf("5 - Quinta\n");
        printf("6 - Sexta\n");
        printf("7 - Sabado\n");

        printf(">>> ");
        scanf("%d", &cadastro.dia);
    }
    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

    printf("tipo da aula: %c", cadastro.tipo);
    printf("\n");

    printf("dia da semana: ");
    switch (cadastro.dia) {
        case 1:
            corTexto("Domingo", 'g');
            break;
        case 2:
            corTexto("Segunda-feira", 'g');
            break;
        case 3:
            corTexto("Terca-feira", 'g');
            break;
        case 4:
            corTexto("Quarta-feira", 'g');
            break;
        case 5:
            corTexto("Quinta-feira", 'g');
            break;
        case 6:
            corTexto("Sexta-feira", 'g');
            break;
        case 7:
            corTexto("Sabado", 'g');
            break;
        default:
            printf("Error! deu ruim lelek");
    }

    printf("\n");

    printf("Horario da aula no formato HH:MM: ");
    getchar();
    fgets(cadastro.horario, 6, stdin);

    int teste = validarHorario(cadastro.horario);

    printf("\n teste eh :%d \n", teste);

    /* funcao validarHorario dando errado. */
    /*
    while (validarHorario(cadastro.horario) != 1 || validarHorario(cadastro.horario) != 2) {
        system(clear);
        

        if (validarHorario(cadastro.horario) == 1) {
            break;

        } else if (validarHorario(cadastro.horario) == 2) {
            /
            Adicionar procedimento para adicionar 0 antes do numero de horario caso a verificadao 
            retorne 2;
            

            break;
        } else if (validarHorario(cadastro.horario) == 0) {
            corTexto("O formato do horario inserido esta incorreto \n", 'r');
            getchar();
        }

        printf("Por favor insira as informacoes da aula:\n\n");

        printf("Horario da aula no formato HH:MM: ");
        getchar();
        fgets(cadastro.horario, 6, stdin);
    }
    */

    if (validarHorario(cadastro.horario) != 1 && validarHorario(cadastro.horario) != 2) {
        while (1) {
            system(clear);
            if (validarHorario(cadastro.horario) == 1) {
                printf("\n teste1 eh :%d \n", teste);
                break;
            } else if (validarHorario(cadastro.horario) == 2) {
                printf("\n teste2 eh :%d \n", teste);
                break;
            } else if (validarHorario(cadastro.horario) == 0) {
                printf("\n teste eh3 :%d \n", teste);
                corTexto("O formato do horario inserido esta incorreto \n", 'r');
                getchar();
            }
            printf("\n teste eh4 :%d \n", teste);
            printf("Por favor insira as informacoes da aula:\n\n");

            printf("Horario da aula no formato HH:MM: ");
            fgets(cadastro.horario, 6, stdin);
        }
    }
}