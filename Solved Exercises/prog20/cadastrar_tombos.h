#ifndef CADASTRAR_TOMBOS_H
#define CADASTRAR_TOMBOS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "registros.h"

void cadastrar_tombos()
{
    char resp;
    bool achou;
    if (count_tombos >= 20)
    {
        printf("Nao ha obras cadastradas...\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("**********************************\n");
        printf("  ####  CADASTRO DE TOMBOS  ####  \n");
        printf("**********************************\n");

        for (int i = 0; i < 20; i++)
        {
            do
            {
                achou = false;
                printf("Digite o numero do tombo: ");
                scanf(" %d", &tombo[i].num_tombo);
                fflush(stdin);

                for (int j = 0; j < count_tombos; j++)
                {
                    if (i != j && tombo[i].num_tombo == tombo[j].num_tombo)
                    {
                        achou = true;
                    }
                }
                if (achou == true)
                {
                    printf("O numero informado ja esta cadastrado no sistema...Tente novamente\n");
                }
            } while (achou == true);

            printf("Digite o nome da obra: ");
            fgets(tombo[i].nome_obra, 50, stdin);
            tombo[i].nome_obra[strcspn(tombo[i].nome_obra, "\n")] = '\0';
            fflush(stdin);

            printf("Digite o nome do autor: ");
            fgets(tombo[i].nome_autor, 50, stdin);
            tombo[i].nome_autor[strcspn(tombo[i].nome_autor, "\n")] = '\0';
            fflush(stdin);

            printf("Digite o nome da editora: ");
            fgets(tombo[i].nome_editora, 30, stdin);
            tombo[i].nome_editora[strcspn(tombo[i].nome_editora, "\n")] = '\0';
            fflush(stdin);

            do
            {
                printf("Codigo de area\n");
                printf("[01] - Exatas\n");
                printf("[02] - Humanas e sociais\n");
                printf("[03] - Biomedicas\n");
                printf("Informe o codigo da area: ");
                scanf("%d", &tombo[i].cod_area);
                fflush(stdin);

                if(tombo[i].cod_area < 0 || tombo[i].cod_area > 3)
                {   
                    printf("Codigo invalido... Tente novamente...\n");
                } 
            } while (tombo[i].cod_area < 0 || tombo[i].cod_area > 3);

            count_tombos++;
            printf("Cadastro realizado com sucesso...\n");

            printf("Deseja continuar s/n?: ");
            scanf("%c", &resp);
            resp = toupper(resp);
            fflush(stdin);

            if (resp == 'N')
            {
                system("cls");
                break;
            }
        }

        printf("========================================================================================================\n");
        printf("###      TOMBO      ###      OBRA      ###      AUTOR      ###     EDITORA     ###     COD AREA     ###\n");
        printf("========================================================================================================\n");
        for (int i = 0; i < count_tombos; i++)
        {
            printf("         %-15d     %-15s     %-15s      %-15s      %-15d\n", tombo[i].num_tombo, tombo[i].nome_obra, tombo[i].nome_autor, tombo[i].nome_editora, tombo[i].cod_area);
        }
        system("pause");
    }
}
#endif