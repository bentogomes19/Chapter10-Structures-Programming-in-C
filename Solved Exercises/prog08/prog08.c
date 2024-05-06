#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include "dados.h"
#include "cadastro_titulos.h"
#include "cadastro_prof.h"
#include "mostrar_relacao.h"
#include <locale.h>

/*8. Veja os campos de alguns registros:
Professor (número de registro, nome, cod_título, total h/a semanal)
Título (cod_título, descrição, valor hora/aula)
Elabore um programa que:
■■ Crie uma rotina para cadastrar os títulos. sabe-se que nessa escola existem cinco títulos.
■■ Crie uma rotina para cadastrar os professores. sabe-se que nessa escola trabalham 14 professores,
e cada um deve estar associado a um título previamente cadastrado.
■■ Crie uma rotina para mostrar a relação de professores, conforme o layout a seguir.

No do registro      Nome                Título (descrição)      Valor hora/ aula        Total H/A       Total geral
111                 João da Silva       Mestre                      R$ 60,50               10          R$ 605,00
113                 Maria Oliveira      Especialista                R$ 40,00               8           R$ 320,00*/

int main(void)
{
    // setlocale(LC_ALL, "Portuguese");
    char resp;
    cadastrar_titulos();
    printf("Deseja continuar S/N?: ");
    resp = getchar();
    resp = toupper(resp);

    if(resp == 'N')
    {
        exit(0);
    }
    else
    {
        cadastrar_prof();
        system("cls");
        mostrar_relacao();
    }

    return 0;
}