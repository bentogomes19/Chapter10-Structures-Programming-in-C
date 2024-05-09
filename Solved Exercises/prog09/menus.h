#ifndef MENUS_H
#define MENUS_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menu_clientes() // Menu para o cadastro de clientes 
{
    printf("****************************************\n");
    printf("*         CADASTRO DE CLIENTES         *\n");
    printf("****************************************\n");
    printf("[01] - Incluir Clientes\n");
    printf("[02] - Alterar Clientes\n");
    printf("[03] - Excluir Clientes\n");
    printf("[04] - Voltar\n");
}

void menu_produtos() // Menu para o cadastros de produtos
{
    printf("****************************************\n");
    printf("*         CADASTRO DE PRODUTOS         *\n");
    printf("****************************************\n");
    printf("[01] - Incluir Produtos\n");
    printf("[02] - Alterar Produtos\n");
    printf("[03] - Excluir Produtos\n");
    printf("[04] - Voltar\n");
}

void menu_iniciar() // Menu principal do programa
{
    printf("*******************************************\n");
    printf("        SISTEMA AUTOMÁTICO DE ESTOQUES     \n");
    printf("*******************************************\n");
    printf("[01] - CADASTROS\n");
    printf("[02] - MOVIMENTAÇÕES\n");
    printf("[03] - CONSULTAS\n");
    printf("[04] - SAIR\n");
}

void menu_cadastros() // Menu de cadastro 
{
    printf("***********************************\n");
    printf("*              CADASTROS          *\n");
    printf("***********************************\n");
    printf("[01] - Manutenção de CLIENTES\n");
    printf("[02] - Manutenção de PRODUTOS\n");
    printf("[03] - Voltar\n");
}

/* Msg para Codigo inválido*/
void codigo_invalido() // Função para código inválido no programa
{
    system("cls");
    printf("Código Inválido...Tente novamente...\n");
    Sleep(1000);
    system("cls");
}

/*Msgs para o caso de o sistema conter mais de três clientes ou seis produtos cadastrados */

void clientes_MAX() // Alerta o usuário caso o sistema atinja a capacidade máxima de clientes cadastrados
{
    system("cls");
    printf("Erro no sistema... Sistema com 3 clientes já cadastrados...\n");
    Sleep(700);
    printf("Cadastros permitidos: 3 Clientes.\n");
    Sleep(1000);
    system("cls");
}

void produtos_MAX() // Alerta o usuário caso o sistema atinja a capacidade máxima de produtos cadastrados
{
    system("cls");
    printf("Erro no Sistema... Sistema com 6 produtos já cadastrados...\n");
    Sleep(700);
    printf("Cadastros permitidos: 6 produtos.\n");
    Sleep(1000);
    system("cls");
}

void msg_client0() // Caso o sistem não tenha clientes cadastrados mostrar ao usuário uma mensagem
{
    system("cls");
    printf("O sistema não há clientes cadastrados...\n");
    Sleep(1000);
    system("cls");
}

void msg_cliente1() // Caso o sistema não encontre um cliente --> Verificação de variáveis
{
    printf("Código do cliente não foi encontrado... Tente novamente...\n");
    Sleep(1300);
    system("cls");
}

void msg_produto1() // Caso o sistem não tenha clientes cadastrados mostrar ao usuário uma mensagem
{
    system("cls");
    printf("O sistema não há produtos cadastrados...\n");
    Sleep(1000);
    system("cls");
}

void msg_produto2() // Caso o sistema não encontre um código digitado pelo usuário
{
    printf("Não há produtos cadastrados em nosso sistema com este código...Tente novamente...\n");
    Sleep(1200);
}


#endif