#include "../lib/aulasDisponiveis.h"  // structs e prototipos
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

void cadastroAula(struct aula cadastro, int *id_aula) {
    char salvarOpcao;

    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

    printf("Digite o tipo da aula:\n");
    printf("A - Artes Maciais\n");
    printf("B - Boxe\n");
    printf("C - Crossfit\n");
    printf("D - Danca\n");

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

	printf("Tipo de aula: ");
	corTexto(charTipoAula(cadastro.tipo), 'g');
    printf("\n");
    //getchar();

    printf("Digite o dia da semana: \n");
    printf("1 - Domingo\n");
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

	printf("Tipo de aula: ");
	corTexto(charTipoAula(cadastro.tipo), 'g');
    printf("\n");

    printf("Dia da semana: ");
    diaSemana(cadastro.dia);

    printf("\n");

    printf("Horario da aula no formato HH:MM: ");
    getchar();
    fgets(cadastro.horario, 6, stdin);

    /* funcao validarHorario. */

    while (validarHorario(cadastro.horario) != 1) {
        system(clear);

        corTexto("O formato do horario inserido esta incorreto \n", 'r');

        printf("Por favor insira as informacoes da aula:\n\n");
        printf("Horario da aula no formato HH:MM: ");
        fgets(cadastro.horario, 6, stdin);
    }

    /* Cadastro id professor */

	do {
		system(clear);

		printf("Por favor insira as informacoes da aula:\n\n");

		printf("Tipo de aula: ");
		corTexto(charTipoAula(cadastro.tipo), 'g');
		printf("\n");

		printf("Dia da semana: ");
		diaSemana(cadastro.dia);
		printf("\n");

		printf("Horario da aula: ");
		corTexto(cadastro.horario, 'g');
		printf("\n");

		/*=========================================
		   Printar na tela a lista de professores 
					antes do imput
		===========================================*/

		printf("Cadastro ID Professor: ");
		scanf("%d", &cadastro.id_prof);

	} while (idValido("professor.csv", cadastro.id_prof) != 1);

	do {
		// Cadastro id aluno

		system(clear);

		printf("Por favor insira as informacoes da aula:\n\n");

		printf("Tipo de aula: ");
		corTexto(charTipoAula(cadastro.tipo), 'g');
		printf("\n");

		printf("Dia da semana: ");
		diaSemana(cadastro.dia);
		printf("\n");

		printf("Horario da aula: ");
		corTexto(cadastro.horario, 'g');
		printf("\n");

        printf("ID Professor: %d", cadastro.id_prof);
        printf("\n");

		printf("Cadastro ID aluno: ");
		scanf("%d", &cadastro.id_aluno);

	} while (idValido("aluno.csv", cadastro.id_aluno) != 1);

	/* Cadastro min turma */
	cadastro.minimo = 1000;
	cadastro.maximo = 0;
	int status = 0;

    while (cadastro.minimo > cadastro.maximo) {
        system(clear);

        if (status == 1) {
            corTexto("O numero minimo de pessoas na aula eh maior que o numero maximo de pessoas \n", 'r');
        }

        printf("Por favor insira as informacoes da aula:\n\n");

		printf("Tipo de aula: ");
		corTexto(charTipoAula(cadastro.tipo), 'g');
        printf("\n");

        printf("Dia da semana: ");
        diaSemana(cadastro.dia);
        printf("\n");

        printf("Horario da aula: ");
        corTexto(cadastro.horario, 'g');
        printf("\n");

        printf("ID Professor: %d", cadastro.id_prof);
        printf("\n");

        printf("ID Aluno: %d", cadastro.id_aluno);
        printf("\n");

        printf("Minimo de pessoas na aula: ");
        scanf("%d", &cadastro.minimo);

        /* Cadastro Max turma */

        system(clear);

        if (status == 1) {
            corTexto("O numero minimo de pessoas na aula eh maior que o numero maximo de pessoas \n", 'r');
        }

        printf("Por favor insira as informacoes da aula:\n\n");

		printf("Tipo de aula: ");
		corTexto(charTipoAula(cadastro.tipo), 'g');
        printf("\n");

        printf("Dia da semana: ");
        diaSemana(cadastro.dia);
        printf("\n");

        printf("Horario da aula: ");
        corTexto(cadastro.horario, 'g');
        printf("\n");

        printf("ID Professor: %d", cadastro.id_prof);
        printf("\n");

        printf("ID Aluno: %d", cadastro.id_aluno);
        printf("\n");

        printf("Minimo de pessoas na aula: %d", cadastro.minimo);
        printf("\n");

        printf("Maximo de pessoas na aula: ");
        scanf("%d", &cadastro.maximo);

        if (cadastro.minimo > cadastro.maximo) {
            status = 1;
        }
    }
    /*
    Verificar que sempre o numero cadastro.maximo deve ter maior que
                    cadastro.minimo
     */

    /* Cadastro Faixa etaria */

    system(clear);

    printf("Por favor insira as informacoes da aula:\n\n");

	printf("Tipo de aula: ");
	corTexto(charTipoAula(cadastro.tipo), 'g');
    printf("\n");

    printf("Dia da semana: ");
    diaSemana(cadastro.dia);
    printf("\n");

    printf("Horario da aula: ");
    corTexto(cadastro.horario, 'g');
    printf("\n");

    printf("ID Professor: %d", cadastro.id_prof);
    printf("\n");

	printf("ID Aluno: %d", cadastro.id_aluno);
	printf("\n");

    printf("Minimo de pessoas na aula: %d", cadastro.minimo);
    printf("\n");

    printf("Maximo de pessoas na aula: %d", cadastro.maximo);
    printf("\n");

    printf("Faixa etaria da aula no formato XX-XX: ");
    getchar();
    fgets(cadastro.faixa_etaria, 6, stdin);

    /* validacao e salvamento */

	int retorno;

	do {
		system(clear);

		printf("Por favor insira as informacoes da aula:\n\n");

		printf("Tipo de aula: ");
		corTexto(charTipoAula(cadastro.tipo), 'g');
		printf("\n");

		printf("Dia da semana: ");
		diaSemana(cadastro.dia);
		printf("\n");

		printf("Horario da aula: ");
		corTexto(cadastro.horario, 'g');
		printf("\n");

		printf("ID Professor: %d", cadastro.id_prof);
		printf("\n");

		printf("ID Aluno: %d", cadastro.id_aluno);
		printf("\n");

		printf("Minimo de pessoas na aula: %d", cadastro.minimo);
		printf("\n");

		printf("Maximo de pessoas na aula: %d", cadastro.maximo);
		printf("\n");

		printf("Faixa etaria da aula: ");
		corTexto(cadastro.faixa_etaria, 'g');
		printf("\n");

		cadastro.horario = stringNewLine(cadastro.horario);
		cadastro.faixa_etaria = stringNewLine(cadastro.faixa_etaria);

		printf("Deseja salvar essa aula cadastrada?\n");
		corTexto("S - Sim\t", 'g');
		corTexto("N - Nao\n", 'r');
		printf(">>> ");
		scanf(" %c", &salvarOpcao);
		salvarOpcao = toupper(salvarOpcao);

		if (salvarOpcao == 'S') {
			cadastro.id_aula = *id_aula;
			retorno = salvarAula(cadastro);
		} else if (salvarOpcao == 'N') {
			break;
		}
	} while (salvarOpcao != 'S' || salvarOpcao == 'N');

	if (retorno) {
		*id_aula += 1;
	} else {
        corTexto("Erro ao abrir o arquivo\n", 'r');
	}
}

int salvarAula(struct aula aula) {
    FILE *fptr = fopen("./data/aulas.csv", "a");

    if (fptr == NULL) {
        return 0;
    }

    fprintf(
			fptr,
			"%d,%d,%d,%d,%d,%d,%c,%s,%s\n",
			aula.id_aula,
			aula.id_aluno,
			aula.id_prof,
			aula.minimo,
			aula.maximo,
			aula.dia,
			aula.tipo,
			aula.horario,
			aula.faixa_etaria
			);

    fclose(fptr);

    return 1;
}

// converter char para nome de categoria de aula

char *charTipoAula(char tipo) {
    if (tipo == 'A')
        return "Artes Maciais";
    else if (tipo == 'B')
        return "Boxe";
    else if (tipo == 'C')
        return "CrossFit";
    else if (tipo == 'D')
        return "Danca";
}

struct aula obterAulaPorId(int id) {
	int ehValido = idValido("aulas.csv", id);

	if (ehValido == 1) {
		FILE *aulas_arq = fopen("data/aulas.csv", "r");

		struct aula aula;
		aula.horario = malloc(100);
		aula.faixa_etaria = malloc(100);

		do {
			fscanf(
				aulas_arq, // Ponteiro pro aquivo

				"%d,%d,%d,%d,%d,%d,%c,%[^,],%[^\n]\n", // Formatacao do arquivo

				&aula.id_aula, // Campos organizados
				&aula.id_aluno,
				&aula.id_prof,
				&aula.minimo,
				&aula.maximo,
				&aula.dia,
				&aula.tipo,
				aula.horario,
				aula.faixa_etaria
			);

			if (aula.id_aula == id)
				break;
			else
				if (feof(aulas_arq)) {
					aula.id_aula = -1;
					aula.id_aluno = -1;
					aula.id_prof = -1;
					aula.minimo = -1;
					aula.maximo = -1;
					aula.dia = -1;
					aula.tipo = '0';
					aula.horario = NULL;
					aula.faixa_etaria = NULL;

					return aula;
				}

		} while(!feof(aulas_arq));


		fclose(aulas_arq);

		return aula;
	} else {
		struct aula aula;

		aula.id_aula = -1;
		aula.id_aluno = -1;
		aula.id_prof = -1;
		aula.minimo = -1;
		aula.maximo = -1;
		aula.dia = -1;
		aula.tipo = '0';
		aula.horario = NULL;
		aula.faixa_etaria = NULL;

		return aula;
	}
}
