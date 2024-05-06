#include <stdio.h>
#include "dados.h"


void calcular_ht() // Cacular hora trabalhada
{
    for(int i=0; i<count; i++)
    {
        if(func[i].cat == 'G' && func[i].turno == 'N')
        {
            func[i].vlr_hora = 0.18 * sal_min;
        }
        if(func[i].cat == 'G' && (func[i].turno == 'M' || func[i].turno == 'V'))
        {
            func[i].vlr_hora = 0.15 * sal_min;
        }
        if(func[i].cat == 'O' && func[i].turno == 'N')
        {
            func[i].vlr_hora = 0.13 * sal_min;
        }
        if(func[i].cat == 'O' && (func[i].turno == 'M' || func[i].turno == 'V'))
        {
            func[i].vlr_hora = 0.10 * sal_min;
        }

    }

}
