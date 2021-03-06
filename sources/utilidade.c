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

void corInt(int numero, char opcao) {
    switch (opcao) {
        case 'r':
            printf("\e[0;91m");
            printf("%d", numero);
            printf("\e[0m");
            break;
        case 'g':
            printf("\e[0;92m");
            printf("%d", numero);
            printf("\e[0m");
            break;
        case 'y':
            printf("\e[0;93m");
            printf("%d", numero);
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
    char *retorno;
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
        return -1;
    }

    int id = 0, maiorId = 0;

    do {
        fscanf(arq, "%d,%*[^\n]\n", &maiorId);
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

    DIR *pasta = opendir("data");

    if (!pasta) {
#ifdef _WIN32
        system("mkdir data");
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        system("mkdir data");
        system("chmod 775 data");
#endif
    }
}

char *horaString(int hora, int minuto) {
    char *retorno = malloc(6);

    if (hora < 10 && minuto < 10)
        sprintf(retorno, "0%d:0%d", hora, minuto);
    else if (hora < 10)
        sprintf(retorno, "0%d:%d", hora, minuto);
    else if (minuto < 10)
        sprintf(retorno, "%d:0%d", hora, minuto);
    else
        sprintf(retorno, "%d:%d", hora, minuto);

    return retorno;
}

int contarLinha(char *arquivo) {
    FILE *arq = fopen(concat("data/", arquivo), "r");

    int count = 0;
    char ch;

    do {
        fscanf(arq, "%*[^\n]%c", &ch);  // recebe somente \n

        count++;
    } while (!feof(arq));

    fclose(arq);

    return --count;
}

void printId(char *caminho) {
    FILE *arq = fopen(concat("data/", caminho), "r");

    if (arq == NULL) {
        exit(1);
    }
    // deveria fazer isso com memoria normal ou dinamica?
    char nome[20];
    int id_loop, flip = 0;

    while (!feof(arq)) {
        fscanf(arq, "%d,%*[^,],%[^,],%*[^\n]\n", &id_loop, nome);  // fscanf(arq, "%d,%*s,%s,%*s\n", &id_loop, nome);

        printf("id: %d ->  ", id_loop);
        printf("%s ", nome);
        if (flip == 1) {
            flip = 0;
            printf("\n");
        } else {
            flip = 1;
        }
    }

    fclose(arq);
}

void printIdAula() {
    FILE *arq = fopen("data/aulas.csv", "r");

    if (arq == NULL) {
        exit(1);
    }
    int id_loop, dia, hora, minuto;
    char tipo;

        while (!feof(arq)) {
        fscanf(arq, "%d,%*d,%*d,%*d,%d,%d:%d,%c,%*[^\n]\n",  // Formatacao do arquivo

               &id_loop,  // Campos organizados
               &dia,
               &hora,
               &minuto,
               &tipo);

        printf("Aula id: %d Dia:%d horario:%d:%d Tipo: %s", id_loop, dia, hora, minuto, charTipoAula(tipo));
        printf("\n");
    }
}