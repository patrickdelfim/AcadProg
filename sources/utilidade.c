#include "../lib/utilidade.h"

void corTexto(char *texto, char opcao) {
    switch (opcao) {
        case 'r':
            printf("\e[0;91m");
            printf("%s", texto);
            printf("\e[0m");
            break;
        case 'g':
            printf("\e[0;92m");
            printf("%s", texto);
            printf("\e[0m");
            break;
        case 'y':
            printf("\e[0;93m");
            printf("%s", texto);
            printf("\e[0m");
            break;
    }
}

char *stringNewLine(char *str) {
    // Funcao para remover o \n

    int len = strlen(str);

    if (str[len - 1] != '\n') {
        return str;
    }

    str[len - 1] = '\0';

    return str;
}

void cleanBuffer(char *str) {
    //fgets executa até newline, o que quer dizer que \n não será lido na primeira iteração do fgets
    char *pn;
    if ((pn = strchr(str, '\n')) != NULL)
        // se \n for encontrado, será substituido por \n
        *pn = '\0';
    else {
        // caso \n não seja encontrado, quer dizer que tivemos nosso input truncado
        int ch;

        // então devemos remover tudo que sobrar em stdin
        while (((ch = getchar()) != EOF) && (ch != '\n'))
            ;
    }
    // debug
    //fprintf(stderr, "\ntamString:%ld string lida [%s]\n",strlen(cadastro.cpf),cadastro.cpf);
}

char *concat(char *str1, char *str2) {
    /*

	pq n funciona ????

	char *retorno; // size of = 8
	int tamTotal = strlen(str1) + strlen(str2); 

	retorno = malloc(tamTotal + 1); */

    int tamTotal = strlen(str1) + strlen(str2);
    char *retorno;  // size of = 2
	retorno = malloc(tamTotal + 1);

    strncpy(retorno, str1, tamTotal);

    if (strlen(str1) < tamTotal) {
        strncat(retorno, str2, tamTotal - strlen(retorno));
    }

    return retorno;
}

int ultimoId(char *caminho) {
    FILE *arq = fopen(concat("data/", caminho), "r");

    if (arq == NULL) {
		if(access(arq, F_OK) == -1) {
			// Verifica se o arquivo nao existe
			return 0;
		}
        return -1;
    }

    int id = 0, maiorId = 0;

    do {
        fscanf(arq, "%d,%*s,%*s,%*s\n", &maiorId);
        if (maiorId > id) {
            id = maiorId;
        }
    } while (!feof(arq));

	fclose(arq);

    return id;
}

void diaSemana(int dia) {
    switch (dia) {
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
            printf("Error!");
    }
}

void criarData() {
	// Funcao para criar a pasta data se nao houver

	#ifdef _WIN32
		system("mkdir data");
	#endif
	#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
		system("chmod 775 data");
	#endif
}
