#ifndef INSCRICOES_H_
#define INSCRICOES_H_

#include <stdio.h>
#include <stdlib.h>

#include "../lib/aulasDisponiveis.h"
#include "../lib/inscricoes.h"
#include "../lib/professor.h"
#include "../lib/utilidade.h"
#include "../lib/validadores.h"

#ifdef _WIN32        // Caso o sistema operacional seja windows
#define clear "cls"  // o clear vai ser o comando cls
#endif
#if defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  // Caso seja unix like
#define clear "clear"                                                                                   // o clear sera o comando clear
#endif
//Struct aulas confirmadas
struct relatorio {
    char tipo;
    int dia;
    int hora;
    int minuto;
    char *professor_nome;
    int qtd_aluno;
};

//Struct aulas canceladas
struct relatorio2 {
    char tipo;
    int dia;
    int hora;
    int minuto;
    char *professor_nome;
    char *email;
};

int contadorAula(int id_aula);

int deletarAulaCancelada(int idAula);

// PROTOTIPO RELATORIO AULA CANCELADA
int relAulaConfirmada();
int ordenarRelatorioAulasConfirmadas();
struct relatorio *listarAulasConfirmadas();
void trocarRelatorioAulasConfirmadas(struct relatorio *relat1, struct relatorio *relat2);

// PROTOTIPO RELATORIO AULA CANCELADA
int relAulaCancelada();
int ordenarRelatorioAulasCanceladas();
struct relatorio2 *listarAulasCanceladas();
void trocarRelatorioAulasCanceladas(struct relatorio2 *relat1, struct relatorio2 *relat2);

#endif
