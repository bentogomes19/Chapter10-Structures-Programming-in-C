#ifndef MOSTRAROBRAS1_H
#define MOSTRAROBRAS1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registros.h"

void mostrarObras1()
{
    if (count_obras == 0 || count_tombos == 0)
    {
        printf("Nao ha cadastros...\n");
        system("pause");
    }
    else
    {
        int cod_area;
        system("cls");
        printf("***************************************\n");
        printf("       OBRAS POR AREA                  \n");
        printf("***************************************\n");
        printf("        [01] - Exatas                  \n");
        printf("        [02] - Humanas e Sociais       \n");
        printf("        [03] - Biomedicas              \n");
        printf("Digite codigo da area: ");
        scanf("%d", &cod_area);

        if(cod_area > 3)
        {
            printf("Obra nao encontrada... Tente novamente...\n");
            system("pause");
            system("cls");
        }

        printf("========================================================================================================\n");
        printf("###      TOMBO      ###      OBRA      ###      AUTOR      ###     EDITORA     ###     COD AREA     ###\n");
        printf("========================================================================================================\n");
        for (int i = 0; i < count_tombos; i++)
        {
            if (tombo[i].cod_area == cod_area)
            {
                printf("         %-15d     %-15s     %-15s      %-15s      %-15d\n", tombo[i].num_tombo, tombo[i].nome_obra, tombo[i].nome_autor, tombo[i].nome_editora, tombo[i].cod_area);
            }
        }
        system("pause");
    }
}

#endif