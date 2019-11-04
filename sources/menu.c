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

    printf("X - Sair\n");

    printf(">>> ");
    scanf(" %c", &opcao);

    return opcao;
}

// TODO:
// int cadastroAluno(struct Aluno aluno) {
//     puts(aluno.nome);

//     return 1;
// }