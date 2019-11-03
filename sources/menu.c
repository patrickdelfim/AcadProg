#include <stdio.h>
#include <stdlib.h>

//==================================//
//   Funcoes relativas a menus e    //
//        input do usuario          //
//==================================//

char menuInicial() {
    char opcao;
    system("cls");
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