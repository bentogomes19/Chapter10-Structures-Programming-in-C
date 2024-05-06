#include <stdio.h>
#include <windows.h>
#include "dados.h"
#include <string.h>

void verificar()
{
    char nome[50];
    int num_avi_usr, achou, lotado, posi;
    printf("**** Reservar Passagem ****\n");
    printf("***************************\n");

    if(count > 60)
    {
        printf("O sistema define um limite de 60 reservas...Tente novamente ou reinicie o programa...\n");
        Sleep(3000);
        system("cls");
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            printf("Voo -> %d | Lugares Disponíveis: %d\n", aviao[i], lugares[i]);
        }

        printf("Digite o número do avião: ");
        scanf("%d", &num_avi_usr);
        fflush(stdin);
        achou = 0; // Número não encontrado
        for(int i=0; i<4; i++)
        {
            if(num_avi_usr == aviao[i])
            {
                achou = 1; // Número encontrado...
            }
        }
        if(achou == 1)
        {
            lotado = 0;
            for(int i=0; i<4; i++) // Verificação se há lugares disponíveis
            {
                if (num_avi_usr  == aviao[i] && lugares[i] != 0) // Caso haja lugares disponíveis
                {
                    printf("Lugares disponíveis: %d\n\n", lugares[i]);
                    system("pause");
                    lotado = 1;
                    posi = i;
                }
            }
            if(lotado == 1)
            {
                reserv[count].num_avi = num_avi_usr;
                printf("Digite o seu nome: ");
                fgets(nome, 50, stdin);
                fflush(stdin);
                strcpy(reserv[count].nome, nome);
                system("cls");
                printf("\nReserva confirmada...\n");
                count ++;
                lugares[posi] --;
                Sleep(1000);
                system("cls");
            }
            else 
            {
                system("cls");
                printf("Voo Lotado...\n");
                Sleep(2000);
                system("cls");

            }
        }
        else
        {
            system("cls");
            printf("O número do avião não foi encontrado... Tente novamente...\n\n");
            Sleep(2000);
            system("cls");
        }
    }

}