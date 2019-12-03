#ifndef VALIDADORES_H_
#define VALIDADORES_H_

#include <stdio.h>
#include <string.h>

#include "../lib/utilidade.h"

int validarCPF(char *cpf);

int validarEMAIL(char *email);

int validarHorario(int hora, int minuto);

int idValido(char *caminho, int id);

int inscricaoValida(int id_aluno, int id_aula);

#endif
