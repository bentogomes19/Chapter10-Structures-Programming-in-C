#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"
#include "cadastrar_obras.h"
#include "cadastrar_tombos.h"
#include "mostrarObras1.h"
#include "mostrarObras2.h"
#include "mostrarObras3.h"

int main(void)
{

    int op;

    do
    {
        system("cls");
        printf("********************************************\n");
        printf("##########   ACERVO BIBLIOTECA   ###########\n");
        printf("********************************************\n");
        printf("         Menu de opcoes                     \n");
        printf("        [01] - Cadastrar tombos             \n");
        printf("        [02] - Cadastrar Obras              \n");
        printf("        [03] - Mostrar obras POR AREA       \n");
        printf("        [04] - Mostrar obras POR AUTOR      \n");
        printf("        [05] - Mostrar obras POR EDITORA    \n");
        printf("        [06] - Encerrar o Programa          \n");
        printf("*********** Escolha uma opcao **************\n");
        printf("> ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            cadastrar_tombos(); // Função para cadastrar tombos da biblioteca
            break;
        case 2:
            cadastrar_obras(); // Função para cadastrar as obras da biblioteca
            break;
        case 3:
            mostrarObras1(); // Função para mostrar as obras por área 1 - exatas 2 - humanas 3 - biomedicas
            break;
        case 4:
            mostrarObras2(); // Função para mostrar as obras por autor
            break;
        case 5:
            mostrarObras3(); // Função para mostrar as obras por editora
            break;
        case 6:
            break;

        default:
            printf("Codigo invalido... Tente novamente\n");
            system("pause");
            break;
        }

    } while (op != 6);

    return 0;
}