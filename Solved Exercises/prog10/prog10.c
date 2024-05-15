#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
/*10. Uma empresa do ramo de material esportivo deseja ter um controle automatizado dos funcionários
que trabalham em cada uma de suas filiais. sabe-se que essa empresa possui quatro filiais com quatro
vendedores e um gerente em cada uma delas. Todos devem ser cadastrados como funcionários.

Faça um programa que realize esse controle, com as seguintes rotinas:

a) Cadastrar filial, observando que não podem existir duas filiais com o mesmo número.

b) Cadastrar funcionário, observando que: 
    1) não podem existir dois funcionários com o mesmo número; 
    2) cada funcionário deve ser cadastrado em uma filial;
    3) cada filial pode ter apenas um gerente e no máximo quatro vendedores;

c) Criar uma consulta a todas as filiais, mostrando o nome do gerente e dos vendedores, o valor total gasto com
pagamento de salários por filial e o valor gasto com pagamento de salário geral. */


/* BIBLIOTECAS DE ESTRUTURAS + SUB-ROTINAS */
#include "menus.h"
#include "registros.h"
#include "cadastro_filiais.h"
#include "cadastro_func.h"
#include "consulta.h"

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
            cadastro_func();
            break;
        case 3: // Consulta
            system("cls");
            consultas();
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