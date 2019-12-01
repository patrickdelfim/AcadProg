#ifndef VALIDADORES_H_
#define VALIDADORES_H_

#include <stdio.h>
#include <string.h>

#include "../lib/utilidade.h"

int validarCPF(char *cpf);

int validarEMAIL(char *email);

int validarHorario(char *horario);

int idValido(char *caminho, int id);

void printId(char *caminho);

#endif

