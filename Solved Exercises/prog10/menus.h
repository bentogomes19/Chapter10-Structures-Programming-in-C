#ifndef MENUS_H
#define MENUS_H
#include "registros.h"
#include <stdlib.h>
#include <windows.h>
/* MENUS DO PROGRAMA */

void menu_footer2() // Cabeçalho 2 do programa // Cadastro funcionários
{
    printf("\t\t\t -->>> Controle Automatizado de Funcionários - Empresa <<--\n");
    printf("\t\t\t\t -->>> Funcionários Cadastrados: %d / 20 <<<---\n", count_func);
}

void menu_footer() // Cabeçalho do programa
{
    printf("\t\t\t -->>> Controle Automatizado de Funcionários - Empresa <<--\n");
    printf("\t\t\t\t -->>> Filiais Cadastradas: %d / 4 <<<---\n", count_fil);
}

void menu_principal() // Menu principal do programa 
{
    printf("\t\t\t -->>> Controle Automatizado de Funcionários - Empresa <<--\n");
    printf("Menu de opções\n");
    printf("[01] - Cadastrar Filiais\n");
    printf("[02] - Cadastrar Funcionário\n");
    printf("[03] - Consulta\n");
    printf("[04] - Sair\n");

}

/* MENSAGENS DE ALERTA E VALIDAÇÕES */

void codigo_invalido()
{
    system("cls");
    printf("Código inválido.... Tente novamente...\n");
    Sleep(1400);
    system("cls");

}

void filial_MAX()
{
    system("cls");
    printf("O sistema está com cadastro lotado... Cadastros permitidos: 4\n");
    Sleep(1700);
    system("cls");
}

void FUNC_MAX()
{
    system("cls");
    printf("O sistema está com cadastro de funcionários lotado... Cadastros permitidos: 5\n");
    Sleep(1700);
    system("cls");
}

void FUNC_0()
{
    printf("Não há filiais cadastradas em nosso sistema...\n");
    system("pause");
    system("cls");
}

#endif