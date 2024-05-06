#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "cadastros.h"
#include "dados.h"
#include "reserva.h"
#include "consultaAviao.h"
#include "consultaPassageiro.h"
/*4. Faça um programa que efetue reserva de passagens aéreas de determinada companhia. O programa
deverá ler os números dos aviões e o número de lugares disponíveis em cada um. Utilize um vetor de
quatro posições, no qual cada posição representa um avião, e outro vetor também de quatro posições
para armazenar os lugares disponíveis.
O programa deverá mostrar o seguinte menu de opções:
1. Cadastrar o número dos aviões.
2. Cadastrar o número de lugares disponíveis em cada avião.
3. Reservar passagem.
4. Consultar por avião.
5. Consultar por passageiro.
6. Finalizar.
Imagine que poderão ser registradas até 60 reservas e que cada uma deverá possuir o número do avião
e o nome do passageiro.
Para realizar a opção 1, deverá ser solicitado ao usuário o número dos quatro aviões disponíveis.
Para realizar a opção 2, deverá ser solicitado ao usuário o número de lugares disponíveis em cada avião
cadastrado na opção 1.
Para realizar a opção 3, deverá ser verificado se o número do avião digitado é válido. Posteriormente,
checar se, no avião escolhido, ainda existe lugar disponível. Caso exista, o programa deverá diminuir o
total de vagas e mostrar a mensagem Reserva confirmada. Caso contrário, deverá mostrar a mensagem
Voo lotado. Observe que não podem ser feitas mais de 60 reservas.
Para realizar a opção 4, deverá ser solicitado o número do avião desejado e, posteriormente, deverão
ser exibidas todas as suas reservas.
Para realizar a opção 5, deverá ser solicitado o nome do passageiro e, posteriormente, deverão ser exibidas todas as reservas feitas em seu nome.
A opção 6 encerra o programa.*/

int main()
{
    int op;
    // setlocale(LC_ALL, "Portuguese");

    do
    {
        // Menu 
        printf("*******         RESERVAS DE PASSAGENS AÉREAS            *********\n");
        printf("                        Menu de Opções                           \n");
        printf("*****************************************************************\n");
        printf("[01] - Cadastrar o número de aviões\n");
        printf("[02] - Cadastrar o número de lugares disponíveis em cada avião\n");
        printf("[03] - Reservar passagem\n");
        printf("[04] - Consulta por avião\n");
        printf("[05] - CConsulta por passageiro\n");
        printf("[06] - Finalizar\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            cadastro1();
            break;
        case 2:
            system("cls");
            cadastro2();
            break;
        case 3:
            system("cls");
            verificar();
            break;
        case 4:
            system("cls");
            consulta_aviao();
            break;
        case 5:
            system("cls");
            consulta_passageiros();
            break;
        case 6:
            system("cls");
            break;
        default:
            system("cls");
            printf("Código inválido...Tente novamente...");
            Sleep(1000);
            system("cls");
            break;
        }

    } while (op != 6);

    return 0;
}