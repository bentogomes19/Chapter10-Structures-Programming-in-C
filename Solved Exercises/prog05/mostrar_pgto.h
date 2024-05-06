#include "dados.h"
#include <stdio.h>
#include <stdlib.h>


void mostrar_pgto() // Mostrar a folha de pagamento dos funcionários
{
    if(count == 0)
    {
        printf("Não há funcionários cadastrados... Tente novamente...\n");
        Sleep(1000);
        system("cls");
    }
    else
    {
        printf("Folha de Pagamento empresa\n");
        printf("%-20s %-18s %-26s %-18s %-22s %-18s\n", "Funcionário", "Horas Trabalhadas", "Valor Hora Trabalhada", "Salário Inicial", "Auxílio Alimentação", "Salário Final");
        for(int i = 0; i < count; i++)
        {
            printf("%-20s %-18d R$ %-24.2f R$ %-16.2f R$ %-20.2f R$ %-16.2f\n", func[i].nome, func[i].nr_horas, func[i].vlr_hora, func[i].sal_ini, func[i].aux, func[i].sal_final);
        }

    }

}