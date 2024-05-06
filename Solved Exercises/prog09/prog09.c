#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

/* ESTRUTURAS E SUB-ROTINAS */
#include "registros.h"
#include "cadastros.h"
#include "movimentacoes.h"
#include "consultas.h"
#include "menus.h"
#include "cadclientes.h"
#include "cad_produtos.h"

int main(void)
{   // setlocale(LC_ALL, "Portuguese");
    int op;
    do
    {           // MENU DE OPÇÕES
        menu_iniciar();
        printf("Escolha uma das opões acima: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            cadastros();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            codigo_invalido();
            break;
        }
        
    } while (op != 4);

    return 0;

}