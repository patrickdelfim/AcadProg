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
    if(c == '@') { // Verifica se tem arroba
      if (arroba)  
        break; 

      arroba = 1;

      if (i < 3)  // Verifica se tem 3 letras antes do arroba;
       break; 

    } else if (arroba){
      if (ponto) { 
        depoisPonto++;

    }else if(c == '.') {
      ponto = 1;
      if (antesPonto < 3) { //Verifica se tem 3 letras antes do ponto
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

int validarHorario(char *horario) {
    int tam = strlen(horario);

    // tamanho de tam dando 40 ????

        int num[4];
    int i = 0;

    /*              transformar a string em vetor de inteiro e
     verificar se o formato tem 5 caracteres HH:MM e depois se a hora eh valida */

    if (tam == 5) {
        if (horario[2] == ':') {
            for (i = 0; i < tam - 3; i++) {
                num[i] = horario[i] % 48;
            }
            for (i = 2; i < tam - 1; i++) {
                num[i] = horario[i + 1] % 48;
            }

            if (num[0] >= 0 && num[0] <= 1 && num[1] >= 0 && num[1] <= 9 && num[2] >= 0 && num[2] <= 5 && num[3] >= 0 && num[3] <= 9) {
                return 1;
            } else if (num[0] == 2 && num[1] >= 0 && num[1] <= 3 && num[2] >= 0 && num[2] <= 5 && num[3] >= 0 && num[3] <= 9) {
                return 1;
            }
        }

        /*              transformar a string em vetor de inteiro e
     verificar se o formato tem 4 caracteres H:MM e depois se a hora eh valida */

    } else if (tam == 4) {
        if (horario[1] == ':') {
            for (i = 0; i < tam - 3; i++) {
                num[i] = horario[i] % 48;
            }
            for (i = 1; i < tam - 1; i++) {
                num[i] = horario[i + 1] % 48;
            }

            if (num[0] >= 1 && num[0] <= 9 && num[1] >= 0 && num[1] <= 5 && num[2] >= 0 && num[2] <= 9) {
                return 2;
            }
        }
    }

    return 0;
}