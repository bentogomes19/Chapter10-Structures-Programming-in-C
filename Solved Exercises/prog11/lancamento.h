#ifndef LANCAMENTO_H
#define LANCAMENTO_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include "registros.h"
#include "menus.h"


void lancamento()
{
    char resp;
    int cod_aluno, cod_discp, total_faltas, achou;
    float  notafinal;
    menu_matricula();
    menu_lancamento();
    if(cont_mat == 0)
    {
        system("cls");
        printf("Não matriculas no sistema.. Tente novamente...\n");
        system("pause");
        system("cls");
    }
    else
    {
        for(int i=0; i<cont_mat; i++)
        {
            do
            {
                achou = 0;
                printf("Digite o codigo do aluno: ");
                scanf("%d", &cod_aluno);
                fflush(stdin);


                for(int j=0; j<cont_alunos; j++)
                {
                    if(cod_aluno == matricula[j].cod_aluno)
                    {
                        achou = 1;
                    }
                }
                if(achou ==0)
                {
                    printf("Aluno não existe em nosso sistema...\n");
                    Sleep(1600);
                }

            } while (achou == 0);
            
            do
            {
                achou = 0;
                printf("Digite o código da disciplina: ");
                scanf("%d", &cod_discp);
                fflush(stdin);

                for(int j=0; j<cont_discp; j++)
                {
                    if(cod_discp == matricula[j].cod_disciplina)
                    {
                        achou = 1;
                    }
                }
                if(achou == 0)
                {
                    printf("Disciplina  não existe em nosso sistema...\n");
                    Sleep(1600);
                }

            } while (achou == 0);

            printf("Digite o total de faltas que o aluno #%d teve: ", cod_aluno);
            scanf("%d", &total_faltas);
            fflush(stdin);
            matricula[i].total_faltas = total_faltas;

            printf("Digte a nota final do aluno $ %d: ", cod_aluno);
            scanf("%f", &notafinal);
            fflush(stdin);
            matricula[i].nota_final = notafinal;

            printf("Deseja continuar s/n?: ");
            resp = getchar();
            resp = toupper(resp);
            fflush(stdin);

            if(resp == 'N')
            {
                break;
            }
            
        }
    }
}


#endif