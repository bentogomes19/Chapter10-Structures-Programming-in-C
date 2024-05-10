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
#include "cadprodutos.h"
#include "movimentacoes.h"
#include "consultas.h"
/* 9. Crie um pequeno sistema para controle automatizado de estoque com os seguintes registros:

        Clientes          Notas               Itens_notas                Produtos
        Cod_cliente     Numero_NF               Numero_NF               Cod_produto
        Endereco        Cod_cliente             Cod_produto              Descricao
        Telefone        Total_geral             Quantidade                Unidade
                                                Preco_venda            Preco_unitario
                                                                       Qtdade_estoque

O sistema deverá conter os seguintes módulos: CADAsTROs, MOVIMENTAÇÕEs, CONsUlTAs,
além de uma opção para sAÍDA. 
 
 1. O módulo CADAsTROs deverá fazer a manutenção das informações sobre clientes e produtos (seis
produtos e três clientes):

a) Manutenção de ClIENTEs — inclusão, tomando cuidado para não cadastrar dois clientes com o mesmo
código; alteração, o único campo que não pode ser alterado é o código; exclusão, tomando cuidado para não
permitir a exclusão de clientes que possuam nota fiscal.

b) Manutenção de PRODUTOs — inclusão, tomando cuidado para não cadastrar dois produtos com o mesmo
código; alteração, o único campo que não pode ser alterado é o código; exclusão, tomando cuidado para não
permitir a exclusão de produtos pertencentes a alguma nota fiscal. 

2. O módulo MOVIMENTAÇÕEs deverá permitir a digitação de notas fiscais de saída, de acordo com as especificações a seguir, supondo que poderão ser gravadas até cinco notas fiscais contendo dois itens em cada uma: 

a) Não cadastrar duas notas com o mesmo número.

b) Uma nota só pode ser emitida a um cliente que já exista.

c) Todos os produtos da nota devem estar previamente cadastrados; caso contrário, emitir mensagem de erro.

d) Não cadastrar duas vezes um produto na mesma nota.

e) Quando um produto for confirmado, baixar sua quantidade em estoque e gravar um registro em ITENs_NOTAs.

3. O módulo CONsUlTAs deverá permitir as consultas descritas a seguir:

a) Todos os produtos com preços entre dois valores digitados pelo usuário.

b) Todas as notas e os itens da nota de um cliente escolhido pelo usuário.

c) Todas as notas e os itens da nota com total geral superior a um valor escolhido pelo usuário. */
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
            system("cls");
            movimentacoes();
            break;
        case 3:
            system("cls");
            consultas();
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