#ifndef CADASTRAR_ALUNOS_H
#define CADASTRAR_ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "registros.h"


void cadastrar_alunos() // realiza o cadastro dos alunos
{
	char resp;
	int achou;
	if(cont_alunos >= 10)
	{
		printf("O sistema atingiu o limite de alunos...\n");
		Sleep(1800);
		system("cls");
	}
	else
	{	
		for(int i=0; i<10; i++) // Cadastro dos 10 alunos 
		{
			do
			{
				achou = 0;
				printf("Digite o código do aluno: ");
				scanf("%d", &alunos[i].cod_aluno);
				fflush(stdin);

				for(int j=0; j<10; j++)
				{
					if(i != j && alunos[i].cod_aluno == alunos[j].cod_aluno)
					{
						achou = 1;
					}
				}
				if(achou == 1)
				{
					printf("Aluno já cadastrado com este código... Tente novamente...\n");
					Sleep(1700);
				}
			} while (achou == 1);

			printf("Digite o nome do aluno: ");
			gets(alunos[i].nome_aluno);
			fflush(stdin);

			do
			{
				printf("Digite a série do aluno %s [ 5-9 serie ]: ", alunos[i].nome_aluno);
				scanf("%d", &alunos[i].serie);
				fflush(stdin);

				if(alunos[i].serie < 5 || alunos[i].serie > 9)
				{
					printf("Código inválido..Tente novamente...\n");
					Sleep(1700);
				}
			} while (alunos[i].serie < 5 || alunos[i].serie > 9);
			cont_alunos++;

			printf("Deseja continar S/N?: ");
			resp = getchar();
			resp = toupper(resp);
			fflush(stdin);

			if(resp == 'N')
			{
				break;
			}
		}
		printf("Alunos cadastrados...\n");
		printf("%-10s   %-20s %-30s \n", "Codigo_aluno", "Nome", "Serie" );
		for(int i=0; i<cont_alunos; i++)
		{
			printf("%-10d     %-20s  %-30d \n", alunos[i].cod_aluno, alunos[i].nome_aluno, alunos[i].serie);
		}
		system("pause");
		system("cls");
	}	
}

#endif