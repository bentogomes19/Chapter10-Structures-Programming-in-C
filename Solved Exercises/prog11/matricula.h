#ifndef MATRICULA_H
#define MATRICULA_H

/* o aluno está apenas se inscrevendo na disciplina
que ainda não foi cursada. Dessa maneira, os campos ‘total de faltas’ e ‘nota final’ não deverão ser
preenchidos). */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "registros.h"
#include "menus.h"


void matricula1() // Realizar o cadastro da matricula
{
	char resp;
	int achou;
	int cod_aluno, cod_discp;
	menu_matricula();

	if(cont_alunos == 0)
	{
		printf("Não há alunos cadastrados...\n");
		system("pause");
		system("cls");
	}
	else
	{

		for(int i=0; i<30; i++)
		{
			do
			{
				achou = 0;
				printf("Digite o codigo do aluno: ");
				scanf("%d", &cod_aluno);
				fflush(stdin);

				for(int j=0; j<cont_alunos; j++)
				{
					if(cod_aluno == alunos[j].cod_aluno)
					{
						achou = 1;
					}
				}

				if(achou == 0)
				{
					printf("Aluno não existe em nosso sistema...\n");
					Sleep(1600);
				}
				else
				{
					matricula[i].cod_aluno = cod_aluno;
				}
				
			} while (achou == 0);

			do
			{
				achou = 0;
				printf("Aluno %d | Digite o codigo da disciplina: ", cod_aluno);
				scanf(" %d", &cod_discp);
				fflush(stdin);

				for(int j=0; j<cont_discp; j++)
				{
					if(cod_discp == disciplina[j].cod_disciplina)
					{
						achou = 1;
					}
				}

				if(achou == 0)
				{
					printf("Disciplina nao encontrada em nosso sistema...\n");
					Sleep(1600);
				}
				else
				{
					matricula[i].cod_disciplina = cod_discp;
				}


			} while (achou == 0);
			cont_mat++;
			
			printf("Deseja continuar S/n?: ");
            resp = getchar();
            resp=toupper(resp);
            fflush(stdin);

            if(resp == 'N')
            {
                break;
            }
            printf("\n\n");
		}

		printf("\n\nAlunos Matriculados no sistema...\n\n");
		printf("%-10s %-15s %-20s %-30s\n ", "Cod Aluno", "Cod Disciplina", "Total de Faltas", "Nota Final");
		for(int i=0; i<cont_mat; i++)
		{
			printf(" %-10d %-15d %-20d %-30f\n", matricula[i].cod_aluno, matricula[i].cod_disciplina, matricula[i].total_faltas, matricula[i].nota_final);
		}
	}

}

#endif