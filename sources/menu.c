//==================================//
//   Funcoes relativas a menus e    //
//        input do usuario          //
//==================================//

#include "../lib/menu.h"

char menuInicial() {
    char opcao;
    system(clear);
    printf("Bem Vindo!\n\n");
    printf("Escolha uma opcao:\n");

    printf("1 - Cadastro de aluno\n");
    printf("2 - Cadastro de professor\n");
    printf("3 - Cadastro de aula\n");
    printf("4 - Inscrever aluno\n");
    printf("5 - Cancelar inscricao\n");
    printf("6 - Fechar turmas\n");
    printf("7 - Turmas Confirmadas\n");

    corTexto("\nX - Sair\n", 'r');

    printf(">>> ");
    scanf(" %c", &opcao);

    return opcao;
}

// TODO:
// int cadastroAluno(struct Aluno aluno) {
//     puts(aluno.nome);

//     return 1;
// }
