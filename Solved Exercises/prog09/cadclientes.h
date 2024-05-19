#ifndef CADCLIENTES_H
#define CADCLIENTES_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "registros.h"
#include "menus.h"

void incluir_clientes() // inclusão, tomando cuidado para não cadastrar dois clientes com o mesmo código
{
    int achou;
    char resp;
    printf("***************************\n");
    printf("*  Inclusão de Clientes   *\n");
    printf("***************************\n");
    printf("Bem-vindo...\n");
    if(count1 == 3) // Count1 = total de clientes cadastrados
    {
        clientes_MAX(); // Alerta do sistema
    }
    else
    {
        for(int i=0; i<3; i++)
        {
            do
            {
                achou = 0;
                printf("Digite o código do cliente: ");
                scanf("%d", &cli[i].cod_cliente);
                fflush(stdin);
                for(int j=0; j<3; j++)
                {
                    if(i != j && cli[i].cod_cliente == cli[j].cod_cliente)
                    {
                        achou = 1;
                    }
                }
                if(achou == 1)
                {
                    printf("Código já cadastrado em nosso sitema...\n");
                    Sleep(500);
                    printf("\nTente Novamente...\n\n");
                    Sleep(500);
                }

            } while (achou == 1);
            
            printf("Digite o Endereço do cliente # %d: ", cli[i].cod_cliente);
            fgets(cli[i].end, 60, stdin);
            fflush(stdin);

            printf("Digite o Telefone do Cliente # %d: ", cli[i].cod_cliente);
            fgets(cli[i].fone, 20, stdin);
            fflush(stdin);
            count1 ++;
            if(count1 != 3)
            {
                printf("Deseja continuar S/N ?: ");
                resp = getchar();
                resp = toupper(resp);
            }
            if(count1 == 3)
            {
                printf("O sistem atingiu o limite de cadastros...\n");
                printf("Aguarde...");
                Sleep(1300);
                system("cls");
            }

            if(resp == 'N')
            {
                system("cls");
                break;
            }

        }
        printf("Verificar dados.\n"); // Verificar dados
        for(int i=0; i<count1; i++)
        {
            printf("Cliente Código-> #%d\n", cli[i].cod_cliente);
            printf("Endereço -> %s", cli[i].end);
            printf("Telefone -> %s", cli[i].fone);
            printf("\n\n");
        }
        system("pause");
        system("cls");
    }

}

void alterar_clientes() // o único campo que não pode ser alterado é o código
{
    int cod_usr, achou, posi, op;
    char endereco[60], telefone[20];
    printf("***********************************\n");
    printf("*      Alterar Dados Clientes     *\n");
    printf("***********************************\n");

    if(count1 == 0)
    {
        msg_client0();  // Alerta do Sistema
    }
    else
    {
        achou = 0;
        do
        {
            printf("Digite o código do cliente: ");
            scanf("%d", &cod_usr);
            fflush(stdin);
            for(int i=0; i<3; i++)
            {
                if(cod_usr == cli[i].cod_cliente)
                {
                    achou = 1;
                    posi = i;
                }
            }
            if(achou == 1)
            {
                printf("\nCliente Código: %d\n", cli[posi].cod_cliente);
                printf("Endereço: %s", cli[posi].end);
                printf("Telefone: %s", cli[posi].fone);
                printf("\n\n");

                do
                {
                    printf("[01] - Alterar Endereço\n");
                    printf("[02] - Alterar Telefone\n");
                    printf("[03] - Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &op);
                    fflush(stdin);

                    if(op != 1 && op != 2 && op != 3)
                    {
                        codigo_invalido(); // Alerta do Sistema
                    }
                } while (op > 3 || op < 1);

                if(op == 1)
                {
                    printf("Digite o novo endereço: ");
                    fgets(endereco, 60, stdin);
                    fflush(stdin);

                    printf("Endereço antigo: %s", cli[posi].end);
                    strcpy(cli[posi].end, endereco);

                    printf("Novo endereço: %s", endereco);
                    printf("\n\n Dados atualizados com sucesso...\n");
                    Sleep(2000);
                    system("cls");
                }
                if(op == 2)
                {
                    printf("Digite o novo telefone: ");
                    fgets(telefone, 20, stdin);
                    fflush(stdin);

                    printf("Telefone antigo: %s", cli[posi].fone);
                    strcpy(cli[posi].fone, telefone);

                    printf("Novo Telefone: %s", telefone);
                    printf("\n\n Dados atualizados com sucesso...\n ");
                    Sleep(2000);
                    system("cls");

                }
                if(op == 3)
                {
                    system("cls");
                }

            }
            else
            {
                msg_cliente1(); // Alerta do Sistema
            }

        } while (achou == 0);

    }
}

void excluir_clientes() //exclusão, tomando cuidado para não permitir a exclusão de clientes que possuam nota fiscal.
{
    int cod_usr, visu;
    printf("***************************\n");
    printf("*  Excluir Clientes       *\n");
    printf("***************************\n");

    if(count1 == 0)
    {
        msg_client0();
    }
    else
    {
        int achou = 0, achou2;
        int posi;
        do
        {
            printf("Digite o código do cliente |: ");
            scanf("%d", &cod_usr);
            fflush(stdin);

            for(int i=0; i<3; i++)
            {
                if(cod_usr == cli[i].cod_cliente)
                {
                    achou = 1;
                    posi = i;
                }
            }
            if(achou == 0)
            {
                codigo_invalido();
            }
        } while (achou != 1);

        if (achou == 1)
        {
            achou2 = 0;
            for(int j=0; j<5; j++)
            {
                if(cli[posi].cod_cliente == nota[j].cod_cliente)
                {
                    achou2 = 1;
                }
            }
            if(achou2 == 1)
            {
                printf("O cliente %d apresenta uma nota fiscal em nosso sistema...\n\n", cod_usr);
                Sleep(1500);

            }
            else
            {
                for(int i=0; i<3; i++)
                {
                    cli[i].cod_cliente = cli[i+1].cod_cliente;
                    strcpy(cli[i+1].end, cli[i].end);
                    strcpy(cli[i+1].fone, cli[i].fone);
                }
                system("cls");
                printf("Cliente excluido com sucesso...\n");
                Sleep(1500);
                system("cls");
                count1--;
            }
        }
    }
}

#endif