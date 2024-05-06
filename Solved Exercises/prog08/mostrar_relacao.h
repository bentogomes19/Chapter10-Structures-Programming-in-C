#include <stdio.h>
#include <stdlib.h>


void mostrar_relacao()
{
    printf("Relação de Professores...\n\n");
    for(int i=0; i<count; i++)
    {
        printf("N do Registro: %d\n", prof[i].nr_registro);
        printf("Nome: %s\n", prof[i].nome);
        for(int j=0; j<5; j++)
        {
            if(prof[i].cod_titulo == titulo[j].cod_titulo)
            {
                printf("Título: %s\n", titulo[j].desc);
                printf("Valor Hora/Aula: R$ %.2f\n", titulo[j].valor_hora);
                prof[i].total_geral = titulo[j].valor_hora * prof[i].total_horas;
            }
        }
        printf("Total H/A: %d\n", prof[i].total_horas);
        printf("Total Geral: R$ %.2f\n", prof[i].total_geral);
        printf("\n\n");
    }
}