#ifndef UTILIDADE_H_
#define UTILIDADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void corTexto(char *texto, char opcao);
char *stringNewLine(char *str);
void cleanBuffer(char *str);
char *concat(char *str1, char *str2);
int ultimoId(char *nomeArquivo);
void diaSemana(int dia);
void criarData();
char *horaString(int hora, int minuto);

#endif

