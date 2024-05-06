#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

void cadastro1() // Cadastro dos números dos aviões
{
    printf("****    CADASTRO DO NÚMERO DOS AVIÕES  ****\n");
    for(int i=0; i<4; i++)
    {
        printf("%d -> Digite o número do avião: ", i+1);
        scanf("%d", &aviao[i]);
    }

    printf("Verifique seus dados...\n\n");
    for(int i=0; i<4; i++)
    {
        printf("Avião %d --> Número do avião: %d\n", i+1, aviao[i]);
    }
    system("pause");
    system("cls");

}

void cadastro2() // Cadastrar o número de lugares disponíveis em cada avião
{
    printf("****    CADASTRAR O NÚMERO DE LUARES DIPONÍVEIS     ****\n");

    for(int i=0; i<4; i++)
    {
        printf("%d -> Digite o número de lugares disponíveis no avião %d: ", i+1, aviao[i]);
        scanf("%d", &lugares[i]);
    }

    printf("Verifique seus dados...\n\n");

    for(int i=0; i<4; i++)
    {
        printf("Lugares disponíveis --> %d\n", lugares[i]);
    }
    system("pause");
    system("cls");
}


