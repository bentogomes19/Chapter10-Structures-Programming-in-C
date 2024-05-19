#ifndef MENUS_H
#define MENUS_H
#include <stdio.h>

/* MENUS DO PROGRAMA */
void menu_principal()
{
    printf("*************************\n");
    printf("* Controle de Matrícula *\n");
    printf("*************************\n");
    printf("[01] - Cadastrar Disciplinas\n");
    printf("[02] - Cadastrar Alunos\n");
    printf("[03] - Realizar Matrícula\n");
    printf("[04] - Lançar Notas\n");
    printf("[05] - Consultar Alunos Reprovados\n");
    printf("[06] - Sair\n");
}

void menu_matricula()
{
    printf("*************************\n");
    printf("* Controle de Matrícula *\n");
    printf("*************************\n");
}

void menu_lancamento()
{

    printf("*************************\n");
    printf("* Lançamentos Notas     *\n");
    printf("*************************\n");
}


/* MENSAGENS E ALERTAS PARA O USUÁRIO */

void codigo_invalido() // Mensagem caso o usuário insira dados inválidos no sistema
{
    printf("Código Inválido... Tente Novamente...\n");
    system("pause");
    system("cls");
}


#endif