#include <stdio.h>
#include <windows.h>
#include "dados.h"

void consulta_aviao()
{
    int num_avi_usr, achou;
    printf("**** Consulta por Avião ****\n");
    printf("****************************\n");

    for(int i=0; i<4; i++) // Mostrar os voos disponíveis e 
    {
        printf("Voo -> %d | Lugares disponíveis: %d\n", aviao[i], lugares[i]);
    }

    
    printf("Digite o número do avião: ");
    scanf("%d", &num_avi_usr);
    achou = 0;
    for(int i=0; i<4; i++)
    {
        if(num_avi_usr == aviao[i])
        {
            achou = 1;
        }
    }
    if(achou == 1) // Numero do avião foi encontrado
    {
        achou = 0;
        for(int i=0; i<count; i++) // Count == quantidade de reservas feitas
        {
            if(reserv[i].num_avi == num_avi_usr)
            {
                printf("Voo -> %d | Nome: %s", reserv[i].num_avi, reserv[i].nome);
                achou = 1;
            }
        }
        if(achou == 0)
        {
            printf("Nenhuma reserva está cadastrada para este avião");
        }
        system("pause");
        system("cls");
    }
    else
    {
        printf("O Número do avião não existe...\n");
        Sleep(2000);
        system("cls");
    }
}