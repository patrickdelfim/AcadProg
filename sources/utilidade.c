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

