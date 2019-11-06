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
    int valido = 0, depoisArroba = tam, depoisPonto = tam;

    for (int i = 0; i < tam; i++) {
        /* pelo menos 3 caracteres antes do arroba para ser um email valido.*/

        if (i > 3) {
            /* verifica se o email tem arroba*/
            if (email[i] == '@') {
                valido++;
                depoisArroba = i;
            }
            /* verifica se o email tem pelo menos 2 caracteres depois do arroba e tambem ponto*/
            if (i > depoisArroba + 2) {
                if (email[i] == '.') {
                    valido++;
                    depoisPonto = i;
                }
            }
            /* verifica se o email tem pelo menos 2 caracteres depois do ponto*/
            if (i > depoisPonto + 2) {
                valido++;
            }
        }
    }

    if (valido >= 3) {
        return 1;
    } else {
        return 0;
    }
}