#include "../lib/validadores.h"

int validarCPF(char *cpf) {
    int i, j, tam = strlen(cpf);
    int num[11];
    int soma1 = 0, soma2 = 0, flag;
    int resto1, resto2;

    // verificar se cpf tem 11 digitos
    if (tam != 11) {
        return 2;  // Tamanho insuficiente
    }

    // verificar se todos os caracteres sao numeros
    for (i = 0; i < tam; i++) {
        if (cpf[i] < 48 || cpf[i] > 57) {
            return 3;  // Letra no meio do CPF
        }
    }

    // transformar a string em vetor de inteiro
    for (i = 0; i < tam; i++) {
        num[i] = cpf[i] % 48;
    }

    //==========================================//
    //     Inicio calculo verificador cpf       //
    //==========================================//

    flag = 1;

    for (i = 0; i < tam - 1; i++) {
        if (num[i] != num[i + 1])
            flag = 0;
    }

    if (flag == 1) {
        return 4;  // Numeros iguais exp: 11111111111

    } else {
        //calculo primeiro digito verificador
        for (int i = 0, j = 10; j >= 2; i++, j--) {
            soma1 += num[i] * j;
        }

        resto1 = (soma1 * 10) % 11;
    }

    //calculo segundo digito verificador
    for (i = 0, j = 11; j >= 2; i++, j--) {
        soma2 += num[i] * j;
    }

    resto2 = (soma2 * 10) % 11;

    // converter digito verificador para 0 se necessario.
    if (resto1 == 10) {
        resto1 = 0;
    }
    if (resto2 == 10) {
        resto2 = 0;
    }

    // retornar resultado final
    if (resto1 == num[9] && resto2 == num[10]) {
        return 1;  // CPF valido
    } else {
        return 0;  // CPF invalido
    }
}

int validarEMAIL(char *email) {
    int tam = strlen(email);
    int arroba = 0;
    int ponto = 0;
    int antesPonto = 0;
    int depoisPonto = 0;
    int i;

    for (i = 0; i < tam; i++) {
        char c = email[i];
        if (c == '@') {  // Verifica se tem arroba
            if (arroba)
                break;

            arroba = 1;

            if (i < 3)  // Verifica se tem 3 letras antes do arroba;
                break;

        } else if (arroba) {
            if (ponto) {
                depoisPonto++;

            } else if (c == '.') {
                ponto = 1;
                if (antesPonto < 3) {  //Verifica se tem 3 letras antes do ponto
                    break;
                }

            } else {
                antesPonto++;
            }
        }
    }

    if (i == tam && depoisPonto > 1)
        return 1;
    else
        return 0;
}

int validarHorario(int hora, int minuto) {
	if (hora < 0 || hora > 24)
		return 0;
	if (minuto < 0 || minuto > 60)
		return 0;

	return 1;
}

int idValido(char *caminho, int id) {
    FILE *arq = fopen(concat("data/", caminho), "r");

    if (arq == NULL) {
        return -1;
    }

    int valido = 0, id_loop;

    do {
        fscanf(arq, "%d,%*[^\n]\n", &id_loop);

        valido = 0;

        if (id == id_loop) {
            valido = 1;
            break;
        }
    } while (!feof(arq));

    fclose(arq);

    return valido;
}

/* COLOCAR ESSA FUNCAO EM UTILITARIO \/\/\/ */

void printId(char *caminho) {
    FILE *arq = fopen(concat("data/", caminho), "r");

    if (arq == NULL) {
        exit(1);
    }
    // deveria fazer isso com memoria normal ou dinamica?
    char nome[20];
    char teste[10];
    int id_loop, flip = 0;

    while (!feof(arq)) {
        fscanf(arq, "%d,%*[^,],%[^,],%*[^\n]\n", &id_loop, nome); // fscanf(arq, "%d,%*s,%s,%*s\n", &id_loop, nome);

        /*===========================================
            -=-=-=-=-=-=-=-=-=-=-=-=-=-=--=--=--=-
            NOME DO PROFESSOR NAO ESTA IMPRIMINDO (problema na leitura. por algum motivo nao esta 
            lendo apenas os valores que preciso e sim o arquivo todo.)
            -=-=-=-=-=-=-=-=-=-=-=-=-=-=--=--=--=-
        ===============================================*/

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

int inscricaoValida(int id_aluno, int id_aula) {
	int valido = 0, aluno, aula;

	FILE *arq = fopen("data/inscricoes.csv", "r");

	do {
		fscanf(arq, "%d,%d\n", &aluno, &aula);
		
		printf("%d %d\n", aluno, aula);
		if (aluno == id_aluno && aula == id_aula) {
			valido = 1;
			break;
		}

	} while(!feof(arq));

	return valido;
}
