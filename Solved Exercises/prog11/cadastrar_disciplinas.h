#ifndef CADASTRAR_DISCIPLINAS_H
#define CADASTRAR_DISCIPLINAS_H
#include "registros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Cadastrar todas as disciplinas que poderão ser oferecidas no ano (não devem ser permitidas duas
disciplinas com o mesmo código) */

void cadastrar_disciplinas()
{
    int resp, achou;
    if(cont_discp > 6)
    {
        printf("O Sistema atingiu o limite permitido de disciplinas cadastradas...\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("[01] - Cadastrar Disciplinas\n\n");

        for(int i=0; i<6; i++)
        {
            do
            {
                achou = 0;
                printf("Disciplina # %d --> Digite o código da disciplina: ", i+1);
                scanf("%d", &disciplina[i].cod_disciplina);
                fflush(stdin);
                
                for(int j=0; j<6; j++)
                {
                    if(i != j && disciplina[i].cod_disciplina == disciplina[j].cod_disciplina)
                    {
                        achou = 1;
                    }
                }
                if(achou == 1)
                {
                    printf("Já existe uma disciplina com este código...Tente novamente...\n");
                    system("pause");
                }
            } while (achou == 1);

            printf("Disciplina # %d --> Digite a descrição da disciplina (NOME DA MATÉRIA): ", i+1);
            fgets(disciplina[i].desc, 30, stdin);
            fflush(stdin);
            disciplina[i].desc[strcspn(disciplina[i].desc, "\n")] = '\0';

            printf("Disciplina # %d --> Digite a carga horária: ", i+1);
            scanf("%d", &disciplina[i].carga_horaria);
            fflush(stdin);
            cont_discp ++;
            printf("Deseja continuar S/N?: ");
            resp = getchar();
            resp=toupper(resp);
            fflush(stdin);

            if(resp == 'N')
            {
                break;
            }
            printf("\n\n");

        }
        system("cls");
        printf("Disciplinas Cadastradas\n");
        printf("%-10s  %-15s  %-30s\n", "Código", "Descrição", "Carga Horária");
        for(int i=0; i<cont_discp; i++)
        {
            printf("%-10d  %-15s  %-30d\n", disciplina[i].cod_disciplina, disciplina[i].desc, disciplina[i].carga_horaria);
        }   
        
        system("pause");
        system("cls");
    }
}


#endif