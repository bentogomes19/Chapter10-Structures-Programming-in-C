#include <stdio.h>
#include "dados.h"

void sal_final()
{
    for(int i=0; i<count; i++)
    {
        func[i].sal_final = func[i].sal_ini + func[i].aux;
    }
}