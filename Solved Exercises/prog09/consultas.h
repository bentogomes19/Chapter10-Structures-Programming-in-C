#ifndef CONSULTAS_H
#define CONSULTAS_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "registros.h"
#include "menus.h"

void consulta1() // Todos os produtos com preços entre dois valores digitados pelo usuário.
{
    float valor1, valor2;
    printf("*****************************\n");
    printf("********* CONSULTAS *********\n");
    printf("*****************************\n\n");

    printf("Digite dois preços (R$): ");
    scanf("%f %f", &valor1, &valor2);

    printf("%-15s %-20s  %-16s %-15s %-10s\n", "Código", "Descrição", "Unidade", "Preco Unitario", "QTD Estoque");
    for(int j=0; j<count2; j++)
    {
        if(product[j].preco_unit >= valor1 && product[j].preco_unit <= valor2)
        {
            printf("%-15d %-20s %-16s R$ %-15.2f %-10d\n\n", product[j].cod_produto, product[j].desc, product[j].unidade, product[j].preco_unit, product[j].qtd_estoque);
        }
    }
    system("pause");
    system("cls");

}
  
void consulta2() // Todas as notas e os itens da nota de um cliente escolhido pelo usuário
{
    int cod_cliente_usr, achou, nota_NF;
    printf("*****************************\n");
    printf("********* CONSULTAS *********\n");
    printf("*****************************\n\n");
    if(count3 == 0)
    {
        printf("Não Há notas fiscais cadastradas... Prossiga até [02] - Movimentações para cadastrar uma nota fiscal..\n");
        system("pause");
        system("cls");
    }
    else
    {
        do
        {
            printf("Digite o código do cliente: ");
            scanf("%d", &cod_cliente_usr);
            achou = 0;
            for(int i=0; i<count1; i++)
            {
                if(cod_cliente_usr == cli[i].cod_cliente)
                {
                    achou = 1;

                }
            }
            if(achou == 0)
            {   
                msg_cliente1();
            }

        } while(achou == 0);

        achou = 0;
        printf("\t\t\t --->>> NOTAS FISCAIS <<<---\n");
        for(int i=0; i<count3; i++)
        {
            if(cod_cliente_usr == nota[i].cod_cliente)
            {
                achou = 1;
                printf("\t\t\t ------------------------------\n");
                printf("\t\t\t Codigo NF: %d\n", nota[i].num_NF);
                printf("\t\t\t Total: R$ %.2f\n", nota[i].total_geral);
                printf("\t\t\t ------------------------------\n\n");
                nota_NF = nota[i].num_NF;
            }
            for(int j=0; j<count5; j++)
            {
                if(itens_nota[j].num_NF == nota_NF)
                {
                    printf("\t\t\t\t *******************************\n");
                    printf("\t\t\t\t * Codigo Produto: %d\n", itens_nota[j].cod_produto);
                    printf("\t\t\t\t * Quantidade: %d\n", itens_nota[j].qtd);
                    printf("\t\t\t\t * Preço de Venda: R$ %.2f\n", itens_nota[j].preco_venda);
                    printf("\t\t\t\t *******************************\n");
                }
            }
        }

        if(achou == 0)
        {
            printf("Não há notas cadastradas...\n\n");
            system("pause");
        }
        system("cls");
    }
    
}  

void consultas()
{
    int op;
    menu_consultas();
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        system("cls");
        consulta1();
        break;
    case 2:
        system("cls");
        consulta2();
        break;
    case 3:
        system("cls");
        break;
    default:
        codigo_invalido();
        break;
    }
}

#endif