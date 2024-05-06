#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "dados.h"
#include "cadastrofunc.h"
#include "calcular_salario_ini.h"
#include "calcular_auxilio.h"
#include "sal_final.h"
#include "mostrar_pgto.h"
/*5. Uma empresa possui 18 funcionários, sobre os quais se tem estas informações: nome, número de horas
trabalhadas no mês, turno de trabalho (pode ser M — matutino; V — vespertino; ou N — noturno),
categoria (pode ser O — operário; ou G — gerente) e valor da hora trabalhada. sabendo-se que essa
empresa deseja informatizar sua folha de pagamento, faça um programa que leia o nome, o número de
horas trabalhadas no mês, o turno e a categoria dos funcionários, não permitindo que sejam informados turnos e categorias inexistentes. O programa deverá calcular o valor da hora trabalhada, conforme
a tabela a seguir, adotando o valor de R$ 550,00 para o salário-mínimo.

Categoria         Turno                 Valor da hora trabalhada
G                   N                      18% do salário-mínimo
G                 M ou V                   15% do salário-mínimo
O                   N                       13% do salário-mínimo
O                 M ou V                    10% do salário-mínimo

O programa deverá calcular o salário inicial dos funcionários, com base no valor da hora e no número
de horas trabalhadas. Todos recebem um auxílio-alimentação, de acordo com o seu salário inicial, conforme a tabela a seguir.

Salário inicial                 Auxílio-alimentação
 R$ 550,00                     20% do salário inicial
 R$ 550,00 e R$ 800,00         15% do salário inicial
 R$ 800,00                     5% do salário inicial

O programa deverá mostrar o nome, o número de horas trabalhadas, o valor da hora trabalhada, o
salário inicial, o auxílio-alimentação e o salário final (salário inicial + auxílio-alimentação) de todos os funcionários. Ele deverá apresentar o seguinte menu de opções:
1. Cadastrar funcionários.
2. Mostrar folha de pagamento.
3. sair...*/

int main()
{
    int op;
    do
    {
        printf("Menu de Opções\n");
        printf("[01] - Cadastrar Funcionários\n");
        printf("[02] - Mostrar folha de pagamento\n");
        printf("[03] - Sair\n");
        printf("Digite uma opção... ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: // Cadastrar Funcionários
            system("cls");
            cadastrofunc();
            calcular_ht();
            calcular_salario_ini();
            calcular_auxilio();
            sal_final();
            break;
        case 2: // Mostrar folha de pagamento
            system("cls");
            mostrar_pgto();
            break;
        case 3: // Sair do Programa
            break;
        default: // Caso de código inválido... 
            system("cls");
            printf("Código inválido... Tente novamente..\n");
            Sleep(1000);
            system("cls");
            break;
        }

    } while (op != 3);

    return 0;
}
