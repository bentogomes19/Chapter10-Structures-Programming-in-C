#include <stdio.h>
#include "dados.h"

void calcular_salario_ini() // Calcular salário Incial
{
    for(int i=0; i<count; i++) // Coletar os salários inciais dos funcionários
    {
        func[i].sal_ini = func[i].nr_horas * func[i].vlr_hora;
    }
}