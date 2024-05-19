#ifndef MOSTRAR_H
#define MOSTRAR_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "menus.h"
#include "registros.h"

void mostrar1() // Mostrar o numero do vendedor que mais vendeu em determinado mes
{

    if (cont_vendas == 0)
    {
        printf("Nao ha vendas cadastradas no sistema...\n");
        system("pause");
        system("cls");
    }
    else if (cont_vendedores == 0)
    {
        printf("Nao ha vendedores cadastrados no sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        bool achou = false;
        char maior_nome[30];
        int mes, posi;
        float maior;
        menu_mostrar1();

        printf("Digite o mês: ");
        scanf("%d", &mes);
        maior = 0;
        for (int i = 0; i < cont_vendas; i++)
        {
            if (mes == vendas[i].mes_venda && vendas[i].valor_venda > maior)
            {
                maior = vendas[i].valor_venda;
                posi = i;
                achou = true;
            }
        }
        if (achou == false)
        {
            printf("nao houve vendas no respectivo mes informado..\n");
            system("pause");
            system("cls");
        }
        else
        {
            strcpy(maior_nome, vendas[posi].nome);

            printf("O vendedor que mais vendeu no mes %d foi: %s com R$ %.2f \n", mes, maior_nome, maior);
            system("pause");
            system("cls");
        }
    }
}

void mostrar2() // Mostrar o numero do mes com mais vendas
{

    if (cont_vendas == 0)
    {
        printf("Nao ha vendas cadastradas no sistema...\n");
        system("pause");
        system("cls");
    }
    else if (cont_vendedores == 0)
    {
        printf("Nao ha vendedores cadastrados no sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        menu_mostrar2();
        int maior;

        maior = 0;
        for (int i = 0; i < 12; i++)
        {
            if (total_vendas[i] > maior)
            {
                maior = i;
            }
        }
        /// Quantidade de vendas
        printf("O mes com maior vendas foi: %d\n", maior);
        system("pause");
        system("cls");
    }
}

#endif