#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

/*5. Faça um programa que leia o código, a descrição, o valor unitário e a quantidade em estoque dos 50 produtos
comercializados por uma papelaria. Essas informações devem ser armazenadas em um registro do tipo vetor
em ordem crescente de código. Depois da leitura, o programa deverá:

■■ realizar uma rotina que permita alterar a descrição, o valor unitário e a quantidade em estoque de
determinado produto, que deverá ser localizado por meio da informação de seu código;

■■ realizar uma rotina que mostre todos os produtos cuja descrição comece com determinada letra
(informada pelo usuário);

■■ mostrar todos os produtos com quantidade em estoque inferior a cinco unidades. */

struct produtos // estrutra de dados sobre os produtos
{
    int codigo;      // Codigo do produto
    char nome[30];   // nome do produto
    float vlr_unit;  // valor unitario do produto
    int qtd_estoque; // quantidade disponivel em estoque no sistema
};
struct produtos prod[50];

void func_produtos_cadastrados(int cont_prod)
{
    printf("============================================================================================\n");
    printf("##     PRODUTO     ##   CODIGO   ##   VALOR UNITARIO (R$)   ##    UNIDADES DISPONIVEIS   ## \n");
    printf("============================================================================================\n");
    for (int i = 0; i < cont_prod; i++)
    {
        printf("%-20s      %2d     %15.2f       %20d\n", prod[i].nome, prod[i].codigo, prod[i].vlr_unit, prod[i].qtd_estoque);
    }
}

void func_alterar_dados(int cont_prod)
{
    bool achou = false;
    char novo_nome[30];
    int op;
    int cod_prod, posi;
    printf("[01] - Alterar dados\n");
    do
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &cod_prod);
        fflush(stdin);

        for (int i = 0; i < cont_prod; i++)
        {
            if (cod_prod == prod[i].codigo)
            {
                achou = true;
                posi = i;
                break;
            }
        }
        if (achou == true)
        {
            printf("============================================================================================\n");
            printf("##     PRODUTO     ##   CODIGO   ##   VALOR UNITARIO (R$)   ##    UNIDADES DISPONIVEIS   ## \n");
            printf("============================================================================================\n");
            for (int i = 0; i < cont_prod; i++)
            {
                if (cod_prod == prod[i].codigo)
                {
                    printf("%-20s      %2d     %15.2f       %20d\n", prod[i].nome, prod[i].codigo, prod[i].vlr_unit, prod[i].qtd_estoque);
                }
            }
        }
        else
        {
            printf("Codigo não encontrado... Tente novamente\n");
            system("pause");
        }

    } while (achou == false);

    do
    {
        /* code */
        printf("[01] - Nome do produto\n");
        printf("[02] - Valor Unitário R$\n");
        printf("[03] - Quantidade em estoque\n");
        printf("[04] - Voltar\n");
        printf("Escolha o que deseja alterar: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            printf("Digite um novo nome para o produto # %d: ", cod_prod);
            fgets(novo_nome, 30, stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0';
            strcpy(prod[posi].nome, novo_nome);
            fflush(stdin);
            printf("Nome alterado com sucesso...\n");
            Sleep(1200);
            break;
        case 2:
            printf("Digite um novo valor unitario (R$) para o produto # %d: ", cod_prod);
            scanf("%f", &prod[posi].vlr_unit);
            fflush(stdin);
            printf("Valor alterado com sucesso...\n");
            Sleep(1000);
            break;
        case 3:
            printf("Digite a nova quantidade no estoque do produto # %d: ", cod_prod);
            scanf("%d", &prod[posi].qtd_estoque);
            fflush(stdin);
            printf("Estoque alterado com sucesso...\n");
            Sleep(1200);
            break;
        case 4:
            system("cls");
            break;
        default:
            printf("Codigo invalido... Tente novamente..\n");
            system("pause");
            break;
        }
    } while (op != 4);
}

void mostrar_produtos(int cont_prod)
{

    if (cont_prod == 0)
    {
        printf("Não ha produtos cadastrados no sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        int cont = 0;
        bool achou;
        char letra;
        do
        {
            achou = false;
            fflush(stdin);
            printf("Mostrar produtos por letra informada...\n");
            printf("Digite uma letra qualquer: ");
            scanf("%c", &letra);
            fflush(stdin);

            for (int i = 0; i < cont_prod; i++)
            {

                if (letra == prod[i].nome[0])
                {
                    achou = true;
                    cont++;
                }
            }
            if (achou == false)
            {
                printf("Nao foi possivel encontrar o produto... Digite outra letra...\n");
                system("pause");
            }

        } while (achou == false);

        printf("============================================================================================\n");
        printf("##     PRODUTO     ##   CODIGO   ##   VALOR UNITARIO (R$)   ##    UNIDADES DISPONIVEIS   ## \n");
        printf("============================================================================================\n");
        for (int i = 0; i < cont; i++)
        {
            printf("%-20s      %2d     %15.2f       %20d\n", prod[i].nome, prod[i].codigo, prod[i].vlr_unit, prod[i].qtd_estoque);
        }

        system("pause");
        system("cls");
    }
}

void mostrar_produtos2(int cont_prod)
{
    system("cls");
    printf("============================================================================================\n");
    printf("##     PRODUTO     ##   CODIGO   ##   VALOR UNITARIO (R$)   ##    UNIDADES DISPONIVEIS   ## \n");
    printf("============================================================================================\n");
    for (int i = 0; i < cont_prod; i++)
    {
        if (prod[i].qtd_estoque < 5)
        {
            printf("%-20s      %2d     %15.2f       %20d\n", prod[i].nome, prod[i].codigo, prod[i].vlr_unit, prod[i].qtd_estoque);
        }
    }
    system("pause");
    system("cls");
}

int main(void)
{
    bool achou;
    int op;
    char resp;
    int i, cont_prod = 0;
    printf("===============================================\n");
    printf("##############  PAPELARIA MAGNUS ##############\n");
    printf("============= SISTEMA DE ESTOQUE ==============\n");

    printf("Cadastro de 50 produtos da papelaria...\n\n");

    for (i = 0; i < 50; i++)
    {
        do
        {
            achou = false;
            printf("Produto # %d -> Digite o codigo do produto: ", i + 1);
            scanf("%d", &prod[i].codigo);
            fflush(stdin);
            for (int j = 0; j < cont_prod; j++)
            {
                if (i != j && prod[i].codigo == prod[j].codigo)
                {
                    achou = true;
                }
            }
            if (achou == true)
            {
                printf("Já existe um produto cadastrado com esse codigo tente novamente...\n");
            }

        } while (achou == true);

        printf("Produto # %d -> Digite o nome do produto: ", i + 1);
        fgets(prod[i].nome, 30, stdin);
        prod[i].nome[strcspn(prod[i].nome, "\n")] = '\0';
        fflush(stdin);

        printf("Produto # %d -> Digite o valor unitário (R$): ", i + 1);
        scanf("%f", &prod[i].vlr_unit);
        fflush(stdin);

        printf("Produto # %d -> Digite a quantidade em estoque: ", i + 1);
        scanf("%d", &prod[i].qtd_estoque);
        fflush(stdin);
        cont_prod++;

        printf("Deseja continuar s/n?: ");
        resp = getchar();
        resp = toupper(resp);
        fflush(stdin);

        if (resp == 'N')
        {
            break;
        }
    }

    system("cls");
    printf("Produtos cadastrados no sistema...\n");
    func_produtos_cadastrados(cont_prod);

    getchar();

    do
    {
        system("cls");
        printf("Menu de opões\n");
        printf("[01] - Alterar dados\n");
        printf("[02] - Mostrar os produtos I\n");
        printf("[03] - Mostrar os produtos II\n");
        printf("[04] - Sair do sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            func_alterar_dados(cont_prod);
            break;
        case 2:
            mostrar_produtos(cont_prod);
            break;
        case 3:
            mostrar_produtos2(cont_prod);
            break;
        case 4:
            break;
        default:
            printf("Codigo invalido... Tente novamente..\n");
            system("pause");
            break;
        }
    } while (op != 4);

    return 0;
}