#ifndef CADASTROS_H
#define CADASTROS_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "menus.h"
#include "registros.h"

void cadastrar_vendedor() // Função para cadastrar vendedores MAX 4
{
    int achou;
    char resp;
    if (cont_vendedores >= 4)
    {
        system("cls");
        printf("O sistema só pode cadastrar 4 vendedores... Reinicie o sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        system("cls");
        menu_cadastrar_vendedor();
        printf("Só é permitido o cadastro de 4 vendedores...\n");

        for (int i = cont_vendedores; i < 4; i++)
        {
            do
            {
                achou = 0;
                printf("Digite o codigo do vendedor(a): ");
                scanf("%d", &vendedores[i].cod_vendedor);
                fflush(stdin);

                for (int j = 0; j < 4; j++)
                {
                    if (i != j && vendedores[i].cod_vendedor == vendedores[j].cod_vendedor)
                    {
                        achou = 1;
                    }
                }

                if (achou == 1)
                {
                    printf("Vendedor já cadastrado com este código... Tente novamente...\n");
                    Sleep(1000);
                }

            } while (achou == 1);

            printf("Digite o nome: ");
            fgets(vendedores[i].nome, 30, stdin);
            vendedores[i].nome[strcspn(vendedores[i].nome, "\n")] = '\0';
            fflush(stdin);

            cont_vendedores++;

            if (cont_vendedores == 4)
            {
                printf("4 cadastrados realizados com sucesso...\n");
                Sleep(700);
                printf("Aguarde...\n");
                Sleep(1200);
                system("cls");
                break;
                ;
            }

            printf("Deseja contiunar s/n?: ");
            resp = getchar();
            resp = toupper(resp);
            fflush(stdin);

            if (resp == 'N')
            {
                system("cls");
                break;
            }
        }
        menu_cadastrar_vendedor();
        menu_verificar_dados();
        printf("===============================\n");
        printf("## Vendedor   ##   Código   ## \n");
        printf("===============================\n");
        for (int i = 0; i < cont_vendedores; i++)
        {
            printf("%-10s            %-10d\n", vendedores[i].nome, vendedores[i].cod_vendedor);
        }
        getchar();
        system("cls");
    }
}

void cadastrar_venda() // Função para cadastrar vendas ...
{
    if (cont_vendedores == 0) // Caso o sistema não tenha vendedores cadastrados
    {
        printf("Nao ha vendedores cadastrados... Digite 1 no menu principal para cadastrar vendedores...\n");
        system("pause");
        system("cls");
    }
    else if (cont_vendas > 100) // Se o a quantidade de vendas for superior a 100 
    {
        printf("O sistema atingiu o limite de vendas cadastradas...\n");
        system("pause");
        system("cls");
    }
    else
    {
        char resp;
        bool achou;
        int cod1, posi;
        system("cls");
        menu_cadastrar_vendas(); // "menus.h"

        for (int i = cont_vendas; i < 100; i++)
        {
            do
            {
                achou = false;
                printf("Venda # %d ## Digite o codigo do vendedor(a): ", i + 1);
                scanf("%d", &cod1);
                fflush(stdin);

                for (int j = 0; j < cont_vendedores; j++)
                { // Verificando dados -- o sistema so cadastra se o usuario inserir um vendedor em 1 - cadastrar vendedor
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
            vendas[i].cod_vendedor = cod1;

            achou = false;
            for (int k = 0; k < cont_vendedores; k++)
            {
                if (cod1 == vendedores[k].cod_vendedor)
                {
                    achou = true;
                    posi = k;
                }
            }
            if (achou == true)
            {
                strcpy(vendas[i].nome, vendedores[posi].nome);
            }

            printf("Venda # %d ## Digite o valor da venda R$:  ", i + 1);
            scanf("%f", &vendas[i].valor_venda);
            fflush(stdin);

            do
            {
                achou = false;
                printf("Venda # %d ## Digite o mes da venda (1-JANEIRO -> 12-DEZEMBRO) : ", i + 1);
                scanf("%d", &vendas[i].mes_venda);
                fflush(stdin);

                for (int j = 0; j < cont_vendas; j++)
                {
                    if (i != j && cod1 == vendas[j].cod_vendedor && vendas[i].mes_venda == vendas[j].mes_venda)
                    {
                        achou = true;
                        break;
                    }
                }
                if (achou == true)
                {
                    printf("O vendedor ja possui uma venda neste mes...\n");
                    Sleep(800);
                    printf("Por favor, Tente novamente...\n ");
                    Sleep(1000);
                }
            } while (achou == true);

            total_vendas[vendas[i].mes_venda]++;

            cont_vendas++;

            printf("Venda cadastrada com sucesso...");
            Sleep(1600);
            system("cls");
            menu_cadastrar_vendas();

            printf("Deseja contnuar (s/n)?: ");
            resp = getchar();
            resp = toupper(resp);
            fflush(stdin);

            if (resp == 'N')
            {
                break;
            }
        }

        system("cls");
        menu_cadastrar_vendas();
        menu_vendas_cadastradas();
        printf("========================================================================\n");
        printf("## Vendedor   ##   Código   ## Valor da Venda R$  ##  Mês da Venda  #   \n");
        printf("========================================================================\n");
        for (int i = 0; i < cont_vendas; i++)
        {
            printf("     %-10s      %-8d      R$ %-10.2f        %-10d\n", vendas[i].nome, vendas[i].cod_vendedor, vendas[i].valor_venda, vendas[i].mes_venda);
        }

        printf("Digite qualuqer tecla para continuar...");
        getchar();
        system("cls");
    }
}

#endif