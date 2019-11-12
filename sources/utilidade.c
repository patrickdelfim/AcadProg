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

void cleanBuffer() {
	char c;
	while((c = getchar()) != '\n' && c == EOF);
}

char *concat(char *str1,char *str2){
    /*

	pq n funciona ????

	char *retorno; 
	int tamTotal = strlen(str1) + strlen(str2); 

	retorno = malloc(tamTotal + 1); */

	int tamTotal = strlen(str1) + strlen(str2);
    char retorno[tamTotal];


    strncpy(retorno,str1,tamTotal);

    if(strlen(str1) < tamTotal){
        strncat(retorno,str2,tamTotal - strlen(retorno));
    }

    return retorno;
}

int ultimoId(char *nomeArquivo) {
	// TODO:

	return 0;
}

void diaSemana(dia) {
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
