#ifndef MOSTRAROBRAS2_H
#define MOSTRAROBRAS2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "registros.h"

void mostrarObras2()
{
    char nome_autor[50];
    if (count_obras == 0 || count_tombos == 0)
    {
        printf("Nao ha cadastros no sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        bool achou;
        system("cls");
        fflush(stdin);
        printf("*****************************\n");
        printf("       OBRAS POR AUTOR       \n");
        printf("*****************************\n");
        printf("Digite o nome do autor: "); 
        fgets(nome_autor, 50, stdin);
        nome_autor[strcspn(nome_autor, "\n")] = '\0';
        fflush(stdin);

        achou = false;
        for (int i = 0; i < count_tombos; i++)
        {
            if (strcmp(nome_autor, tombo[i].nome_autor) == 0)
            {
                achou = true;
            }
        }
        if (achou == false)
        {
            printf("Nao foi possivel encontrar o autor...\n");
            system("pause");
            system("cls");
        }
        else
        {
            printf("========================================================================================================\n");
            printf("###      TOMBO      ###      OBRA      ###      AUTOR      ###     EDITORA     ###     COD AREA     ###\n");
            printf("========================================================================================================\n");
            for (int i = 0; i < count_tombos; i++)
            {
                if (strcmp(nome_autor, tombo[i].nome_autor) == 0)
                {
                    printf("         %-15d     %-15s     %-15s      %-15s      %-15d\n", tombo[i].num_tombo, tombo[i].nome_obra, tombo[i].nome_autor, tombo[i].nome_editora, tombo[i].cod_area);
                }
            }
            system("pause");
        }
    }
}

#endif