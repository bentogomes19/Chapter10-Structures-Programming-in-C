#ifndef MENUS_H
#define MENUS_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"
/* MENUS DO PROGRAMA */
void menu_principal()
{

    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$ !!!!!!!!! CONTROLE DE VENDAS !!!!!!!!!!!! $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("############## LOJAS DENNER #################\n\n");
    printf("# 1 # Cadastrar Vendedores\n");
    printf("# 2 # Cadastrar uma Venda\n");
    printf("# 3 # Consultar Vendas do vendedor(a) no mês\n");
    printf("# 4 # Consultar Total de vendas do Vendedor(a)\n");
    printf("# 5 # Mostrar o vendedor(a) com mais vendas no mês\n");
    printf("# 6 # Mostrar o mês com mais vendas\n");
    printf("# 7 # Sair \n");
    printf("# Escolha uma opção: ");
}

void menu_cadastrar_vendedor()
{
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$ !!!!!!!!! CADASTRAR VENDEDOR !!!!!!!!!!!! $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void menu_cadastrar_vendas()
{
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$ !!!!!!!!! CADASTRAR VENDAS !!!!!!!!!!!! $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("--------------- %d/100 --------------------\n", cont_vendas);
}

void menu_consultas()
{
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$ !!!!!!!!! CONSULTAS !!!!!!!!!!!! $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void menu_verificar_dados()
{
    printf("*********************************\n");
    printf("-------- Verificar Dados --------\n");
    printf("*********************************\n");
}

void menu_vendas_cadastradas()
{
    printf("========================================================================\n");
    printf("##                  VENDAS CADASTRADAS NO SISTEMA                     ##\n");
    printf("========================================================================\n");
}

void vendedores_cadastrados()
{
    printf("****************************************\n");
    printf("-------- Vendedores Cadastrados --------\n");
    printf("****************************************\n");

    printf("===============================\n");
    printf("## Vendedor   ##   Código   ## \n");
    printf("===============================\n");

    for (int i = 0; i < cont_vendedores; i++)
    {
        printf("%-10s            %-10d\n", vendedores[i].nome, vendedores[i].cod_vendedor);
    }
}

void menu_mostrar1()
{
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$ !!!!!!!!! VENDEDOR COM MAIS VENDAS  !!!!!!!!!!!! $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void menu_mostrar2()
{
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("$ !!!!!!!!! MÊS COM MAIS VENDAS  !!!!!!!!!!!! $\n");
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}
/* ALERTAS DO SISTEMA */

void codigo_invalido()
{
    printf("Codigo invalido... Tente novamente....\n");
    Sleep(1200);
    system("cls");
}
#endif