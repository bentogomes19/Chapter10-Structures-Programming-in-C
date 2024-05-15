#ifndef CONSULTAS_H
#define CONSULTAS_H

#include <stdlib.h>
#include <stdio.h>
#include "registros.h"
#include <windows.h>

void consultas()
{
    float soma = 0;
    printf("Consultas...\n\n");
    if(count_fil == 0)
    {
        printf("Não há filiais cadastradas em nosso sistema...  Tente novamente...\n");
        system("pause");
        system("cls");
    }
    else
    {
        for(int i=0; i<count_fil; i++)
        {
            printf("Filial --> %d || %s\n", filial[i].num_filial, filial[i].nome_filial);
        }

        for(int j=0; j<count_func; j++)
        {
            printf("Cód Funcionário: %d\n", func[j].cod_funcionario);
            printf("Nome Funcionario: %s\n", func[j].nome_funcionario);
            printf("Salário Funcionário: R$ %.2f\n", func[j].salario);
            printf("Cargo: %s\n\n", func[j].cargo);
            printf("Filial: %d\n", func[j].num_filial);
        }
        system("pause");
        system("cls");
    }
}


#endif