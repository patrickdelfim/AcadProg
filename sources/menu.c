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
