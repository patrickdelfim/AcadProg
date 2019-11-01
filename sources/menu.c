#include <stdio.h>

//==================================//
//   Funcoes relativas a menus e    //
//        input do usuario          //
//==================================//

char menuInicial() {
    system("cls");
    printf("Bem Vindo!\n\n");
    printf("Escolha uma opcao:\n");

    printf("1 - Cadastro de aluno\n");

    printf("X - Sair\n");

    char opcao;

    printf(">>> ");
    opcao = getchar();

    return opcao;
}

// TODO:
// int cadastroAluno(struct Aluno aluno) {
//     puts(aluno.nome);

//     return 1;
// }