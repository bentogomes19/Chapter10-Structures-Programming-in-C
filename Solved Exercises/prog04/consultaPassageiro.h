#include <stdio.h>
#include "dados.h"
#include <string.h>
#include <windows.h>
void consulta_passageiros()
{
    char nome[50];
    int achou;
    printf("**** Consulta por passageiros ****\n");
    printf("**********************************\n");
    fflush(stdin);
    printf("Digite o nome do passageiro: ");
    fgets(nome, 50, stdin);
    fflush(stdin);
    achou = 0;
    for(int i=0; i<count; i++)
    {
        if(strcmp(reserv[i].nome, nome)==0)
        {
            printf("reservas Numero do avião: %d\n", reserv[i].num_avi);
            achou = 1;
        }
    }
    if(achou == 0) // Nome encontrado
    {
        printf("Nenhuma reserva está cadastrada para este nome...\n");
        Sleep(2000);
        system("cls");
    }
    else
    {
        system("pause");
        system("cls");
    }
}