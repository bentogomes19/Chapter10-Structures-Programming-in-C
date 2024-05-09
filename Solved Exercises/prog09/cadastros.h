#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"
#include "menus.h"
#include "cadclientes.h"
#include "cadprodutos.h"

/*1. O módulo CADASTROS deverá fazer a manutenção das informações sobre clientes e produtos (seis
produtos e três clientes):

a) Manutenção de ClIENTEs — inclusão, tomando cuidado para não cadastrar dois clientes com o mesmo
código; alteração, o único campo que não pode ser alterado é o código; exclusão, tomando cuidado para não
permitir a exclusão de clientes que possuam nota fiscal.

b) Manutenção de PRODUTOs — inclusão, tomando cuidado para não cadastrar dois produtos com o mesmo
código; alteração, o único campo que não pode ser alterado é o código; exclusão, tomando cuidado para não
permitir a exclusão de produtos pertencentes a alguma nota fiscal.*/

void mnt_clientes() // Manutenção de clientes --> alterar, cadastrar ou excluir clientes
{
        int op;
        do
        {
            menu_clientes(); // menus.h
            printf("Escolha uma das opções acima: ");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                system("cls");
                incluir_clientes(); // [01] - Adicionar clientes no sistem
                break;
            case 2:
                system("cls");
                alterar_clientes(); // [02] - Alterar dados do cliente
                break;
            case 3:
                system("cls");
                excluir_clientes(); // [03] - Excluir Clientes
                break;
            case 4:
                system("cls");
                break;
            default:
                codigo_invalido();
                break;
            }

        } while (op != 4);
}

void mnt_produtos() // Manutenção de produtos --> Incluir produtos, alterar produtos e excluir produtos
{
    int op;
    do
    {
        menu_produtos();
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            incluir_produtos(); // Inclusão de produtos no sistema
            break;
        case 2:
            system("cls");
            alterar_produtos(); // Alterar dados do produto no sistema
            break;
        case 3: 
            system("cls");
            excluir_produtos(); // Excluir alguns produtos do sistema
            break;
        case 4:
            system("cls");
            break;
        default:
            codigo_invalido(); // Alerta do sistema
            break;
        }
    } while (op != 4);
    
}

void cadastros() // ENTRADA NOS CADASTROS (MENU) dar ao usuário opçoes de cadastros
{
    int op;
    do
    {
        menu_cadastros(); // menus.h
        printf("Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            mnt_clientes(); // Manutenção de clientes
            break;
        case 2:
            system("cls");
            mnt_produtos(); // Manutenção de Produtos
            break;
        case 3:
            system("cls");
            break;
        default:
            codigo_invalido();
            break;
        }

    } while (op != 3);

}