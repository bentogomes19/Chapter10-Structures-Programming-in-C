#ifndef CADPRODUTOS_H
#define CADPRODUTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "registros.h"
#include "menus.h"

void incluir_produtos() // INCLUSÃO DE PRODUTOS >  tomando cuidado para não cadastrar dois produtos com o mesmo código 
{
    int cod_produto, achou;
    char resp;
    printf("***************************\n");
    printf("*  Inclusão de Produtos   *\n");
    printf("***************************\n");
    printf("Bem-vindo...\n");
    if(count2 == 6)
    {
        produtos_MAX(); // Erro no Sistema... Sistema com 6 produtos já cadastrados...
    }
    else
    {
        for(int j=0; j<6; j++)
        {
            do
            {
                achou = 0; // não encontrou produtos com o mesmo código
                printf("Digite o código do produto: ");
                scanf("%d", &cod_produto);
                fflush(stdin);

                for(int k=0; k<6; k++)
                {
                    if(cod_produto == product[k].cod_produto)
                    {
                        achou = 1;
                    }
                }
                if(achou == 1)
                {
                    printf("Já existe um produto cadastrado com este código... Tente Novamente...\n");
                    Sleep(1500);
                }
            } while (achou != 0);
            product[j].cod_produto = cod_produto;

            printf("Digite a descrição do produto: ");
            fgets(product[j].desc, 30, stdin);
            product[j].desc[strcspn(product[j].desc, "\n")] = '\0';
            fflush(stdin);

            printf("Digite a unidade do produto: ");
            fgets(product[j].unidade, 20, stdin);
            product[j].unidade[strcspn(product[j].unidade, "\n")] = '\0';
            fflush(stdin);

            printf("Digite o preço unitário do produto: ");
            scanf("%f", &product[j].preco_unit);
            fflush(stdin);

            printf("Digite a quantidade em estoque: ");
            scanf("%d", &product[j].qtd_estoque);
            fflush(stdin);

            count2 ++;

            if(count2 == 6)
            {
                produtos_MAX();
                break;
            }

            printf("Deseja continuar S/N ?: ");
            resp = getchar();
            resp = toupper(resp);
            
            if(resp == 'N')
            {
                system("cls");
                break;
            }
            printf("\n\n");
        }
        printf("Verificar dados.\n"); // Verificar dados
        printf("%-15s %-20s  %-16s %-15s %-10s\n", "Código", "Descrição", "Unidade", "Preco Unitario", "QTD Estoque");
        for(int j=0; j<count2; j++)
        {
            printf("%-15d %-20s %-16s R$ %-15.2f %-10d\n\n", product[j].cod_produto, product[j].desc, product[j].unidade, product[j].preco_unit, product[j].qtd_estoque);
        }
        system("pause");
        system("cls");
    }
}

void alterar_produtos() // ALTERAÇÃO DE PRODUTOS >  o único campo que não pode ser alterado é o código; 
{
    int cod_produto, achou, posi, op, qtd_estoque_usr;
    char desc_usr[30], unidade_usr[20];
    float preco_unit_usr;
    printf("***************************\n");
    printf("*      Alterar Produtos   *\n");
    printf("***************************\n");
    printf("Bem-vindo...\n");
    if(count2 == 0)
    {
        msg_produto1();
    }
    else
    {
        achou = 0;
        do
        {
            printf("Digite o código do produto: ");
            scanf("%d", &cod_produto);
            fflush(stdin);
            for(int j=0; j<count2; j++)
            {
                if(cod_produto == product[j].cod_produto)
                {
                    achou = 1;
                    posi = j; // Coleta a posição do vetor em que está armazenado o código do produto
                }
            }
            if(achou == 1)
            {
                printf("\nProduto Econtrado...\n\n");
                printf("Código do Produto-> #%d\n", product[posi].cod_produto);
                printf("Descrição -> %s\n", product[posi].desc);
                printf("Unidade-> %s\n", product[posi].unidade);
                printf("Preço Unitário: R$ %.2f\n", product[posi].preco_unit);
                printf("Quantidade em estoque: %d\n", product[posi].qtd_estoque);
                Sleep(3000);
                system("cls");

                do
                {   /*Menu*/
                    printf("[01] - Alterar Descrição\n");
                    printf("[02] - Alterar Unidade\n");
                    printf("[03] - Alterar Preço\n");
                    printf("[04] - Alterar Estoque\n");
                    printf("[05] - Voltar\n");
                    printf("Digite uma opção: ");
                    scanf("%d", &op);
                    fflush(stdin);

                    if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5) /* Validações */
                    {
                        codigo_invalido(); // Alerta do Sistema
                    }
                    
                } while (op > 5 || op < 1);

                if (op == 1) // ALTERAR DESCRIÇÃO DO PRODUTO
                {
                    printf("[01] - Alterar Descrição... Produto #%d --> %s\n", product[posi].cod_produto, product[posi].desc);
                    printf("Digite a nova descrição do produto: ");
                    fgets(desc_usr, 30, stdin);
                    fflush(stdin);

                    strcpy(product[posi].desc, desc_usr);
                    printf("Descrição Alterada com sucesso...\n\n");
                    Sleep(2000);
                    printf("Descrição --> %s", product[posi].desc);
                    system("pause");
                    system("cls");
                }
                if(op == 2) // ALTERAR UNIDADE DO PRODUTO
                {
                    printf("[02] - Alterar unidade... Produto #%d --> %s\n", product[posi].cod_produto, product[posi].desc);
                    printf("Digite a nova unidade do produto: ");
                    fgets(unidade_usr, 20, stdin);
                    fflush(stdin);

                    strcpy(product[posi].unidade, unidade_usr);
                    printf("Unidade alterada com sucesso...\n\n");
                    Sleep(1000);
                    printf("Unidade --> %s", product[posi].unidade);
                    system("pause");
                    system("cls");

                }
                if(op == 3) // ALTERAR O PREÇO DO PRODUTO
                {
                    printf("[03] - Alterar o preço... Produto #%d --> %s\n", product[posi].cod_produto, product[posi].desc);
                    printf("Digite o novo preço unitário (R$): ");
                    scanf("%f", &preco_unit_usr);
                    fflush(stdin);

                    product[posi].preco_unit = preco_unit_usr;
                    printf("Preço alterado com sucesso...\n");
                    Sleep(1000);
                    printf("Preço Unitário: R$ %.2f\n", product[posi].preco_unit);
                    system("pause");
                    system("cls");
                }
                if(op == 4) // ALTERAR A QUANTIDADE NO ESTOQUE 
                {
                    printf("[04] - Alterar Estoque... Produto #%d --> %s", product[posi].cod_produto, product[posi].desc);
                    printf("Digite a quantidade de itens no estoque: ");
                    scanf("%d", &qtd_estoque_usr);
                    fflush(stdin);

                    product[posi].qtd_estoque = qtd_estoque_usr;
                    printf("Estoque atualizado com sucesoo...\n");
                    Sleep(1000);
                    printf("Estoque atualizado: %d\n", product[posi].qtd_estoque);
                    system("pause");
                    system("cls");
                }   

                if(op == 5)
                {
                    system("cls");
                }
                
            }
            if(achou == 0)
            {
                msg_produto2();
            }
        } while (achou == 0);
    
        
    }
}   

void excluir_produtos() // EXCLUIR PRODUTOS > tomando cuidado para não permitir a exclusão de produtos pertencentes a alguma nota fiscal.
{

    int cod_produto, posi, achou, achou2, visu;
    printf("***************************\n");
    printf("*      Excluir Produtos   *\n");
    printf("***************************\n");
    printf("Bem-vindo...\n");
    
    if(count2 == 0)
    {
        msg_produto1(); // Mensagem do sistema "O sistema não há produtos cadastrados..."
    }
    else
    {

        do
        {
            achou = 0;
            visu = 0; // Usuário NÃO visualizou os produtos
            printf("Digite o código do produto (OBS: Digite 1 para visualizar produtos cadastrados): ");
            scanf("%d", &cod_produto);
            fflush(stdin);

            if(cod_produto == 1)
            {
                printf("%-15s %-20s  %-16s %-15s %-10s\n", "Código", "Descrição", "Unidade", "Preco Unitario", "QTD Estoque");
                for(int j=0; j<count2; j++)
                {
                    printf("%-15d %-20s %-16s R$ %-15.2f %-10d\n\n", product[j].cod_produto, product[j].desc, product[j].unidade, product[j].preco_unit, product[j].qtd_estoque);
                    visu = 1; // Usuário VISUALIZOU os produtos
                }
                system("pause");
            }
            for(int j=0; j<count2; j++)
            {
                if(cod_produto == product[j].cod_produto)
                {
                    achou = 1;
                    posi = j;
                }
            }
            if(achou == 1)
            {
                printf("Produto Encontrado...\n");
                printf("Código do Produto-> #%d\n", product[posi].cod_produto);
                printf("Descrição -> %s\n", product[posi].desc);
                printf("Unidade-> %s\n", product[posi].unidade);
                printf("Preço Unitário: R$ %.2f\n", product[posi].preco_unit);
                printf("Quantidade em estoque: %d\n", product[posi].qtd_estoque);
                system("pause");
            }
            else if(achou == 0 && visu == 0) // Caso ele não encontre o produto (achou = 0); caso o cliente digite o código do produto (visu = 0)
            {
                msg_produto2(); // Mensagem "Não há produtos cadastrados em nosso sistema com este código...Tente novamente..."
            }

        } while(achou == 0);
 
        achou2 = 0;
        for(int k=0; k<10; k++) // Verificar se o produto possui alguma nota fiscal cadastrada no sistema
        {
            if(product[posi].cod_produto == itens_nota[k].cod_produto)
            {
                achou2 = 1;
            }
        }
        if(achou2 == 1)
        {
            printf("O produto informado apresenta uma nota fiscal em nosso sistema...\n");
            system("pause");
            system("cls");
        }
        else
        {
            for(int j=0; j<count2; j++)
            {
                product[j].cod_produto = product[j+1].cod_produto;
                strcpy(product[j+1].desc, product[j].desc); 
                strcpy(product[j+1].unidade, product[j].unidade); 
                product[j].preco_unit = product[j+1].preco_unit;
                product[j].qtd_estoque = product[j+1].qtd_estoque;
            }
            system("cls");
            printf("Produto excluido com sucesso...\n");
            Sleep(1500);
            system("cls");
            count2--;
        }
    }
}

#endif