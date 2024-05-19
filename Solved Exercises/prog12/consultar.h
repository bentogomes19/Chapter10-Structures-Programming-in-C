#ifndef CONSULTAR_H
#define CONSULTAR_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "registros.h"
#include "menus.h"

void consultar_vendas2() // Consultar o total de vendass de determinado vendedor
{

    if (cont_vendas == 0)
    {
        printf("O sistema nao possui vendas cadastradas no sistema\n");
        system("pause");
        system("cls");
    }
    else
    {
        bool achou;
        int cod1;
        system("cls");
        menu_consultas();

        do
        {
            printf("Digite o codigo do vendedor(a): ");
            scanf("%d", &cod1);
            fflush(stdin);

            for (int j = 0; j < cont_vendedores; j++)
            {
                if (cod1 == vendedores[j].cod_vendedor)
                {
                    achou = true;
                }
            }
            if (achou == false)
            {
                printf("Codigo invalido... Tente novamente\n");
                Sleep(1200);
                system("cls");
                menu_cadastrar_vendas();
            }

        } while (achou == false);

        printf("========================================================================\n");
        printf("## Vendedor   ##   Código   ## Valor da Venda R$  ##  Mês da Venda  #   \n");
        printf("========================================================================\n");
        for (int i = 0; i < cont_vendas; i++)
        {
            if (cod1 == vendas[i].cod_vendedor)
            {
                printf("     %-10s      %-8d      R$ %-10.2f        %-10d\n", vendas[i].nome, vendas[i].cod_vendedor, vendas[i].valor_venda, vendas[i].mes_venda);
            }
        }

        printf("Digite qualquer tecla para voltar ao menu principal...");
        getchar();
        system("cls");
    }
}

void consultar_vendas1() // Consultar as vendas de um funcionario em determinado mes
{

    if (cont_vendas == 0)
    {
        printf("O sistema nao possui vendas cadastradas no sistema\n");
        system("pause");
        system("cls");
    }
    else
    {
        int cod1, mes;

        system("cls");
        menu_consultas();
        vendedores_cadastrados();

        printf("Digite o codigo do vendedor(a): ");
        scanf("%d", &cod1);

        printf("Digite o mes (1- JANEIRO -> 12 - DEZEMBRO): ");
        scanf("%d", &mes);

        printf("===================================================\n");
        printf("Vendedor ## Valor da Venda (R$) ## Mes da Venda    \n");
        printf("===================================================\n");
        for (int i = 0; i < cont_vendas; i++)
        {
            if (cod1 == vendas[i].cod_vendedor && mes == vendas[i].mes_venda)
            {
                printf("%-15s   R$ %-10.2f       %02d\n", vendas[i].nome, vendas[i].valor_venda, vendas[i].mes_venda);
            }
        }
        system("pause");
        system("cls");
    }
}

#endif