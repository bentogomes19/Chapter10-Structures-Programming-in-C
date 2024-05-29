#ifndef MOSTRAROBRAS3_H
#define MOSTRAROBRAS3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "registros.h"

void mostrarObras3()
{
    if (count_obras == 0 || count_tombos == 0)
    {
        printf("Nao ha cadastros...Tente novamente...\n");
        system("pause");
        system("cls");
    }
    else
    {
        bool achou;
        achou = false;
        char nome_editora[30];
        fflush(stdin);
        system("cls");
        printf("*******************************\n");
        printf("       OBRAS POR EDITORA       \n");
        printf("*******************************\n");

        printf("Digite o nome da editora: ");
        fgets(nome_editora, 30, stdin);
        nome_editora[strcspn(nome_editora, "\n")] = '\0';
        fflush(stdin);

        for (int i = 0; i < count_tombos; i++)
        {
            if (strcmp(nome_editora, tombo[i].nome_editora) == 0)
            {
                achou = true;
            }
        }
        if (achou == false)
        {
            printf("nao foi possivel encontrar o nome da obra...\n");
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
                if (strcmp(nome_editora, tombo[i].nome_editora) == 0)
                {
                    printf("         %-15d     %-15s     %-15s      %-15s      %-15d\n", tombo[i].num_tombo, tombo[i].nome_obra, tombo[i].nome_autor, tombo[i].nome_editora, tombo[i].cod_area);
                }
            }
            system("pause");
        }
    }
}

#endif