#ifndef REPROVADOS_H
#define REPROVADOS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "registros.h"

void reprovados()
{
    if(cont_alunos == 0)
    {
        system("cls");
        printf("Não ha alunos cadastrados");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Consulta de Alunos Reprovados\n\n"); 
        printf("%-10s %-25s %-20s %-20s \n", "Codigo Aluno", "Codigo Disciplina", "Faltas", "Nota Final");
        for(int i=0; i<cont_mat; i++)
        {
            if(matricula[i].nota_final < 7 )
            {
                 printf("%-10d %-25d  %-20d  %-20.2f \n", matricula[i].cod_aluno, matricula[i].cod_disciplina, matricula[i].total_faltas, matricula[i].nota_final);
            }
        }
    }
}


#endif