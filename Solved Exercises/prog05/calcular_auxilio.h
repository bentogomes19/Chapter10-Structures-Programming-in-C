#include <stdio.h>
#include "dados.h"

void calcular_auxilio()
{
    for(int i=0; i<count; i++)
    {
        if(func[i].sal_ini <= 550)
        {
            func[i].aux = 0.20 * func[i].sal_ini;
        }
        if(func[i].sal_ini > 500 && func[i].sal_ini < 800)
        {
            func[i].aux = 0.15 * func[i].sal_ini;
        }
        if(func[i].sal_ini >= 800)
        {
            func[i].aux = 0.05 * func[i].sal_ini;
        }
    }
}