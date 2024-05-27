#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>
#define MAX 100

struct cliente
{
    int codigo_cliente; // Codigo do cliente
    char nome[30];      // Nome do cliente
};
struct cliente cliente[MAX];

struct conta
{
    int numero;         // Numero da conta
    float valor_compra; // Valor da compra
    int codigo_cliente; // Codigo do cliente
};
struct conta conta[MAX];

int count_clientes = 0;
int count_contas = 0;
void func_cadastrar_clientes()
{
    char nome1[30], resp;
    bool achou;
    int codigo_usr;

    if (count_clientes == 100)
    {
        printf("O sistema atingiu o limite de cadastros...");
        Sleep(2000);
        system("cls");
    }
    else
    {
        for (int i = 0; i < MAX; i++)
        {
            do
            {
                achou = false;
                printf("Cliente %d -> Digite o seu codigo: ", i + 1);
                scanf("%d", &codigo_usr);

                for (int j = 0; j < count_clientes; j++)
                {
                    if (codigo_usr == cliente[j].codigo_cliente)
                    {
                        achou = true;
                    }
                }

                if (achou == true)
                {
                    printf("Código ja cadastrado no sistema... Tente novamente...\n");
                }
                else
                {
                    cliente[i].codigo_cliente = codigo_usr;
                }
            } while (achou == true);

            fflush(stdin);
            printf("Cliente %d -> Digite o seu nome: ", i + 1);
            gets(nome1);
            fflush(stdin);
            
            strcpy(cliente[i].nome, nome1);

            count_clientes++;
            printf("Cadastro feito com sucesso...\n");
            Sleep(1200);

            do
            {
                printf("Deseja continuar s/n?: ");
                resp = getchar();
                resp = toupper(resp);
                fflush(stdin);

                if (resp != 'N' && resp != 'S')
                {
                    printf("Codigo inválido... Tente novamente..\n");
                }
            } while (resp != 'N' && resp != 'S');

            if (resp == 'N')
            {
                system("cls");
                break;
            }
        }
    }
}

void func_cadastrar_contas()
{
    char resp;
    bool achou;
    int num_conta, cod_cliente;
    float valor_compra;

    if (count_clientes == 0)
    {
        printf("O sistema não há clientes cadastrados... Tente novamente...\n");
        system("pause");
        system("cls");
    }
    else
    {

        do
        {
            system("cls");
            printf("Digite o código do cliente: ");
            scanf("%d", &cod_cliente);

            for (int i = 0; i < count_clientes; i++)
            {
                if (cod_cliente == cliente[i].codigo_cliente)
                {
                    achou = true;
                }
            }
            if (achou == true)
            {
                printf("Cliente localizado...\n");
            }
            else
            {
                printf("Cliente não encontrado não é possivel criar a conta...\n");
                system("pause");
                system("cls");
            }
        } while (achou == false);

        for (int i = 0; i < MAX; i++)
        {
            printf("Conta %d -> Digite o numero da conta: ", i + 1);
            scanf("%d", &num_conta);

            printf("Conta %d -> Digite o valor da compra (R$): ", i + 1);
            scanf("%f", &valor_compra);

            conta[i].codigo_cliente = cod_cliente;
            conta[i].numero = num_conta;
            conta[i].valor_compra = valor_compra;
            count_contas++;
            printf("Conta cadastrada com sucesso...\n");
            Sleep(1500);

            fflush(stdin);
            printf("Cliente # %d -> Deseja continuar o cadastrado com esta conta %d ?: ", cod_cliente, num_conta);
            resp = getchar();
            resp = toupper(resp);
            fflush(stdin);

            if (count_contas == 100)
            {
                printf("O sistema atingiu o limite de cadastro de contas... Aguarde...\n");
                conta[i].codigo_cliente = 0;
                conta[i].numero = 0;
                conta[i].valor_compra = 0;
                Sleep(2000);
                system("cls");
            }

            if (resp == 'N')
            {
                system("cls");
                break;
            }
        }
    }
}

void func_excluir_clientes()
{

    if (count_clientes == 0)
    {
        printf("Não ha clientes cadastrados no sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        bool achou;
        int op, cod_cliente, posi;
        do
        {
            printf("\nDigite 1 para verificar os clientes cadastrados | 2 para excluir um cliente | 3 - Voltar ao menu: ");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                system("cls");
                printf("================================\n");
                printf("##   Cliente   ##   Codigo   ##\n");
                printf("================================\n");
                for (int i = 0; i < count_clientes; i++)
                {
                    printf("## %-11s ## %-9d ##\n", cliente[i].nome, cliente[i].codigo_cliente);
                }
                break;
            case 2:
                achou = false;
                printf("Excluiir cliente...\n\n");
                printf("Digite o codigo do cliente: ");
                scanf("%d", &cod_cliente);

                for (int i = 0; i < count_clientes; i++)
                {
                    if (cod_cliente == cliente[i].codigo_cliente)
                    {
                        achou = true;
                        posi = i;
                    }
                }
                if (achou == false)
                {
                    printf("Não foi possivel encontra a conta...\n");
                    break;
                }
                else
                {
                    achou = false;
                    for (int i = 0; i < count_contas; i++)
                    {
                        if (cod_cliente == conta[i].codigo_cliente)
                        {
                            achou = true;
                        }
                    }
                    if (achou == true)
                    {
                        printf("Exclusão não permitida.\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cliente[posi].codigo_cliente = cliente[posi + 1].codigo_cliente;
                        strcpy(cliente[posi + 1].nome, cliente[posi].nome);
                        count_clientes--;
                        printf("Conta excluida com sucesso...\n");
                        Sleep(1700);
                        system("cls");
                    }
                }
                break;
            case 3:
                system("cls");
                break;
            default:
                printf("Codigo inválido.... Tente novamente...\n");
                break;
            }
        } while (op != 3);
    }
}

int main(void)
{
    int op;

    do
    {
        printf("========================\n");
        printf("## Cadastros Sistema ## \n");
        printf("========================\n");
        printf("Menu de opções\n");
        printf("[01] - Cadastrar Clientes\n"); // Funcão para cadastrar clientes
        printf("[02] - Cadastrar Contas\n");   // Função para cadastrar contas
        printf("[03] - Excluir Cliente\n");    // Função para excluir clientes
        printf("[04] - Sair\n");               // Sair do programa
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            func_cadastrar_clientes();
            break;
        case 2:
            func_cadastrar_contas();
            break;
        case 3:
            func_excluir_clientes();
            break;
        case 4:
            break;
        default:
            printf("Código inválido... Tente novamente...\n");
            system("pause");
            system("cls");
            break;
        }
    } while (op != 4);

    return 0;
}
