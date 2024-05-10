#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

/* BIBLIOTECAS DE ESTRUTURAS + SUB-ROTINAS */
#include "menus.h"
#include "registros.h"
#include "cadastro_filiais.h"

int main(void) 
{
    int op;

    do
    {
        menu_principal();
        printf("Digite uma das opções: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: // Cadastrar Filiais
            system("cls");
            cadastro_filiais();
            break;
        case 2: // Cadastrar Funcionários
            system("cls");

            break;
        case 3: // Consulta
            system("cls");

            break;
        case 4: // Sair do programa
            system("cls");
            break;
        
        default:
            codigo_invalido(); // Menus.h
            break;
        }

    } while(op != 4);
    
    return 0;
}