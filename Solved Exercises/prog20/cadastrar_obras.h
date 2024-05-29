#ifndef CADASTRAR_OBRAS_H
#define CADASTRAR_OBRAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "registros.h"

void cadastrar_obras() // Cadastrar informações da obra
{

    bool achou;
    if (count_obras >= 60 || count_tombos == 0)
    {
        printf("O sistema so permite o cadastro de 60 obras...\n");
        system("pause");
    }
    else
    {
        int num_tombo;
        char resp;
        int dia, mes, ano;
        system("cls");
        printf("***********************************\n");
        printf("******** CADASTRO DE OBRAS ********\n");
        printf("***********************************\n");

        for (int i = 0; i < 60; i++)
        {
            do
            {

                achou = false;
                printf("Digite o numero do tombo: ");
                scanf(" %d", &num_tombo);
                fflush(stdin);

                for (int j = 0; j < count_tombos; j++)
                {
                    if (num_tombo == tombo[j].num_tombo)
                    {
                        achou = true;
                    }
                }
                if (achou == false)
                {
                    printf("O numero informado nao existe em nosso sistema...\n");
                }
            } while (achou == false);
            obra[i].num_tombo = num_tombo;

            printf("Digite o numero do exemplar: ");
            scanf("%d", &obra[i].num_exemplar);

            printf("Digite a data da compra: ");
            scanf("%d %d %d", &dia, &mes, &ano);
            fflush(stdin);
            obra[i].data_compra[0] = dia;
            obra[i].data_compra[1] = mes;
            obra[i].data_compra[2] = ano;

            count_obras++;
            printf("Cadastro feito com sucesso...\n");

            printf("Deseja continuar s/n ?: ");
            scanf("%c", &resp);
            resp = toupper(resp);
            fflush(stdin);

            if (resp == 'N')
            {
                system("cls");
                break;
            }
        }
        printf("Obras cadastradas...\n");

        printf("==================================================================\n");
        printf("##  NUMERO TOMBO  ##  NUM EXEMPLAR  ##  DATA DA COMPRA (d/m/y) ## \n");
        printf("==================================================================\n");

        for (int i = 0; i < count_obras; i++)
        {
            printf("     %-10d          %-10d              %d %d %d\n", obra[i].num_tombo, obra[i].num_exemplar, obra[i].data_compra[0], obra[i].data_compra[1], obra[i].data_compra[2]);
        }
        system("pause");
        system("cls");
    }
}

#endif