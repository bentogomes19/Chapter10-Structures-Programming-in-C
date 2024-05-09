#ifndef MOVIMENTACOES_H
#define MOVIMENTACOES_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include "registros.h"
#include "menus.h"

void produtos_cadastrados() // VER OS PRODUTOS CADASTRADOS NO SISTEMA
{
    if (count2 == 0)
    {
        msg_produto1(); // Alerta ao cliente que não há produtos cadastrados
    }
    else
    {
        printf("\t\t\t---->>> Produtos cadastrados <<<----\n");
        printf("%-15s %-20s  %-16s %-15s %-10s\n", "Código", "Descrição", "Unidade", "Preco Unitario", "QTD Estoque");
            for(int j=0; j<count2; j++)
            {
                printf("%-15d %-20s %-16s R$ %-15.2f %-10d\n\n", product[j].cod_produto, product[j].desc, product[j].unidade, product[j].preco_unit, product[j].qtd_estoque);
            }
            system("pause");
            system("cls");
    }
}   

void gerar_nf() // GERAR A NOTA FISCAL DO CLIENTE
{
    char resp;
    int cod_NF ,cod_cliente_usr, cod_produto_usr, achou, achou2, achou3, qtd_usr, posi;
    printf("\t\t\t --->> Nota Fiscal de Saída <<---\n");
    printf("Bem-vindo...\n\n");
    if(count1 == 0 || count2 == 0)
    {
        printf("Não há clientes ou produtos cadastrados em nosso sistema.. Consulte [01] - CADASTROS em nosso menu princial...\n");
        system("pause");
        system("cls");
    }
    if(count3 == 5)
    {
        NF_MAX();
    }
    else if (count1 != 0 || count2 != 0)
    {
        for(int g=0; g<5; g++) // NOTAS FISCAIS
        {
            do // CÓDIGO  DA NOTA FISCAL 
            {
                achou = 0;
                fflush(stdin);
                printf("Digite o código da Nota Fiscal (NF): ");
                scanf("%d", &cod_NF);
                fflush(stdin);

                for(int i=0; i<2; i++)
                {
                    if(cod_NF == nota[i].num_NF)
                    {
                        achou = 1;
                    }
                }
                if(achou == 1)
                {
                    printf("\n\tJá existe uma nota fiscal cadastrada com esse número... Tente novamente...\n");
                    Sleep(2000);
                }

            } while(achou == 1);

            do // CÓDIGO DO CLIENTE
            {
                achou = 0;
                printf("\nDigite o código do cliente | Digite 0 para sair: ");
                scanf("%d", &cod_cliente_usr);
                fflush(stdin);

                for(int i=0; i<count1; i++)
                {
                    if(cod_cliente_usr == cli[i].cod_cliente)
                    {
                        achou = 1;
                    }
                }
                if(achou == 0 && cod_cliente_usr != 0)
                {
                    msg_cliente1(); // Caso o sistema não encontre um cliente --> Verificação de variáveis
                }
            } while (achou == 0 && cod_cliente_usr != 0 );

            if(cod_cliente_usr == 0)
            {
                system("cls");
                break;
            }

            for(int j=0; j<2; j++) // Contar a quantidade de itens das notas fiscais de saída que estão sendo geradas
            {
                count4 = 0;
                printf("\n\t\t -->> NF_%d <<--\n", cod_NF);
                printf("\t\t -->> Cliente %d <<--\n\n", cod_cliente_usr);

                do // Retorna para o usuário inserir o código novamente --> "Produto já existe nesta nota..."
                {
                    do // Retorna para o código --> "O produto não possui estoque em nosso sistema...Tente Novamente"
                    {
                        do // CÓDIGO DO PRODUTO 
                        {
                            achou = 0;
                            printf("\nDigite o código do produto | Digite 0 para sair: ");
                            scanf("%d", &cod_produto_usr);
                            fflush(stdin);

                            for(int i=0; i<count2; i++)
                            {
                                if(cod_produto_usr == product[i].cod_produto) // Verificar se o produto existe no sistema
                                {
                                    achou = 1;
                                    posi = i;
                                }
                            }
                            if(achou == 0 && cod_produto_usr != 0)
                            {
                                msg_produto2(); // Caso o sistema não encontre um código digitado pelo usuário "Produto não cadastrado"
                            }
                        } while (achou == 0 && cod_produto_usr != 0);

                        if(cod_produto_usr == 0) // PARA ELE VOLTAR AO MENU ANTERIOR
                        {
                            system("cls");
                            break;
                        }

                        achou2 = 0; // temos produtos no estoque
                        for(int k=0; k<count2; k++)
                        {
                            if(product[k].qtd_estoque == 0)
                            {
                                achou2 = 1; // Confirma que o estoque é igual a zero
                            }
                        }
                        if(achou2 == 1)
                        {
                            printf("\n\tO produto não possui estoque em nosso sistema...Tente Novamente\n");
                            Sleep(1500);
                            printf("\tAguarde...\n");
                            Sleep(1000);
                            achou2 = 0;
                            system("cls");
                            break;
                        }
                    } while (achou2 == 1);

                    achou3 = 0;
                    for(int h=0; h<10; h++) // VERIFICAR SE EXISTE ALGUM PRODUTO COM NOTA FISCAL IUGAL 
                    {
                        if(itens_nota[h].num_NF == cod_NF && itens_nota[h].cod_produto == cod_produto_usr)
                        {
                            achou3 = 1; // Significa que o sistema localizou um produto ja existente nesta nota Fiscal
                        }
                    }
                    if(achou3 == 1)
                    {
                        printf("Produto já existe nesta nota...\n");
                        Sleep(2000);
                    } 
                } while (achou3 == 1);
                
                if(cod_produto_usr == 0) // QUANDO O USUÁRIO INSERIR ZERO ELE RETORNA AO MENU DO PROGRAMA
                {
                    system("cls");
                    break; // Quebra de laço
                }

                if(achou2 == 0)
                {
                    do
                    {
                        printf("\n\t ->> Digite a quantidade: ");
                        scanf("%d", &qtd_usr);
                        fflush(stdin);

                        if(qtd_usr > product[posi].qtd_estoque)
                        {
                            printf("Estoque insuficiente...\n");
                            Sleep(2000);
                        }
                    } while (qtd_usr > product[posi].qtd_estoque);
                }
                itens_nota[count5].num_NF = cod_NF;
                itens_nota[count5].cod_produto = cod_produto_usr;
                itens_nota[count5].qtd = qtd_usr;
                itens_nota[count5].preco_venda = qtd_usr * product[posi].preco_unit;
                nota[g].total_geral += (qtd_usr * product[posi].preco_unit);
                count5++;
                count4++;
                printf("\t\t --->>>> Produto incluído na nota com sucesso <<<<----\n");
                product[posi].qtd_estoque --;

                if(count5 == 2)
                {
                    printf("Só é permitido 2 itens de nota por nota fiscal...\n");
                    Sleep(2000);
                    break;
                }

                if(count4 < 2)
                {
                    printf("\nDeseja cadastrar outro produto nesta nota? S/N: ");
                    resp = getchar();
                    resp = toupper(resp);
                    fflush(stdin);
                }
                if(resp == 'N')
                {
                    break;   
                }

            }
            nota[g].num_NF = cod_NF;
            nota[g].cod_cliente = cod_cliente_usr;
            count3++; 
            if(cod_cliente_usr == 0) // QUANDO O USUÁRIO INSERIR ZERO ELE RETORNA AO MENU DO PROGRAMA
            {
                system("cls");
                break;
            }
 
            if(cod_produto_usr == 0) // QUANDO O USUÁRIO INSERIR ZERO ELE RETORNA AO MENU DO PROGRAMA
            {
                system("cls");
                break;
            }

            if(count3 == 5) // Indica que o sistema atingiu a capacidade máxima de armazenamento do Registro
            {
                NF_MAX();
                break;
            }

            printf("\nNotas cadastradas %d/%d\n", count3, 5);
            printf("Deseja continuar s/n?: ");
            resp = getchar();
            resp = toupper(resp);
            fflush(stdin);

            if(resp == 'N')
            {
                system("cls");
                break;
            }
        }
    }
}

void movimentacoes() //  deverá permitir a digitação de notas fiscais de saída
{
    int op;
    do
    {
        menu_movimentacoes();
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            produtos_cadastrados(); // VER OS PRODUTOS CADASTRADOS NO SISTEMA
            break;
        case 2:
            system("cls"); 
            gerar_nf(); // GERAR A NOTA FISCAL DO CLIENTE
            break;
        case 3:
            system("cls");
            break;
        default:
            codigo_invalido(); // Mensagem do sistema
            break;
        }
    } while (op != 3);

}


#endif