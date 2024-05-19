#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "registros.h"
#include "menus.h"
#include "cadastros.h"
#include "consultar.h"
#include "mostrar.h"

/*1. Uma empresa deseja controlar as vendas realizadas por seus vendedores a cada mês, durante um ano inteiro.
sabe-se que nessa empresa existem quatro vendedores.
É importante que esse controle seja automatizado, porque muitas consultas devem ser respondidas
imediatamente. O gerente necessita de um meio para cadastrar as vendas de todos os vendedores e,
depois, precisa ver um menu contendo as seguintes opções:

1. Cadastrar vendedor.

2. Cadastrar venda.

3. Consultar as vendas de um funcionário em determinado mês.

4. Consultar o total das vendas de determinado vendedor.

5. Mostrar o número do vendedor que mais vendeu em determinado mês.

6. Mostrar o número do mês com mais vendas.

7. Finalizar o programa.

Na opção 1: devem ser cadastrados vendedores, e não pode haver dois vendedores com o mesmo có-
digo.

Na opção 2: devem ser cadastradas vendas, informado o código do vendedor e o mês das vendas, mas
não podem existir duas vendas para o mesmo vendedor no mesmo mês.

Na opção 3: deve ser informado o número do vendedor e o número do mês que se deseja consultar,
para, então, descobrir e mostrar esse valor.

Na opção 4: deve ser informado o número do vendedor desejado, calculado e mostrado o total de suas
vendas.

Na opção 5: deve ser informado o número do mês que se deseja pesquisar, para então descobrir e mostrar o número do vendedor que mais vendeu nesse mês.

Na opção 6: deve ser descoberto e mostrado o mês com maior venda.

Na opção 7: o programa termina.*/


int main(void)
{
    int op;
    do
    {
        menu_principal();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrar_vendedor(); // Função para cadastro do vendedor
            break;
        case 2:
            cadastrar_venda(); // Cadastrar uma venda
            break;
        case 3:
            consultar_vendas1();  // Consultar o total de vendas de determinado vendedor
            break;
        case 4:
            consultar_vendas2(); // Consultar as vendas de um funcionário em determinado mes
            break;
        case 5:
            mostrar1(); // Mostrar o número do vendedor que mais vendeu em um determinado mes
            break;
        case 6:
            mostrar2(); // Mostrar o número do mes com mais vendas
            break;
        case 7:
            break; // Sair do programa
        default:
            codigo_invalido(); // Msg de código invalido criado em "menus.h"
            break;
        }
    } while (op != 7);

    return 0;
}