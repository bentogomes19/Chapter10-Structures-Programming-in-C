#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*7. Crie um programa para ler o código, o sexo (M — masculino; F — feminino) e o número de horas-
-aula ministradas pelos professores de uma escola durante um mês. sabe-se que um professor ganha
R$ 60,50 hora-aula e que a escola possui dez professores. Após a leitura, o programa deverá mostrar:
a) Uma listagem contendo o código, o salário bruto, o desconto e o salário líquido de todos o professores.
b) A média aritmética dos salários brutos dos professores do sexo masculino.
c) A média aritmética dos salários brutos dos professores do sexo feminino.
Os descontos devem ser assim calculados:

Sexo            Até 70 horas/aula ao mês            Mais que 70 horas/aula ao mês
Masculino               10%                                     8%
Feminino                7%                                      5%   */
int main(void)
{
    int invalido, count = 0;
    float soma_sal_masc = 0, soma_sal_fem = 0, count_masc = 0, count_fem = 0;
    float media_masc, media_fem;
    char resp;
    struct professores
    {
        int cod;
        char sexo;
        int nr_horas;
        float sal_bruto;
        float desc;
        float sal_liq;
    }; struct professores prof[10];

    for(int i=0; i<10; i++)
    {
        printf("Digite o código do professor %d: ", i+1);
        scanf("%d", &prof[i].cod);
        fflush(stdin);

        do
        {
            invalido = 0;
            printf("Digite o sexo do professor %d M - Masculino | F - Feminino: ", i+1);
            scanf("%c", &prof[i].sexo);
            prof[i].sexo=toupper(prof[i].sexo);
            fflush(stdin);
            
            if(prof[i].sexo != 'M' && prof[i].sexo != 'F')
            {
                printf("Código inválido...Tente novamente...\n");
                invalido = 1;
            }
        } while (invalido == 1);

        printf("Digite o número de horas-aula ministradas do professor %d: ", i+1);
        scanf("%d", &prof[i].nr_horas);
        fflush(stdin);
        count++;

        printf("Deseja continuar S/N?: ");
        resp = getchar();
        resp=toupper(resp);

        if(resp == 'N')
        {
            break;
        }
        system("cls");
    }

    for(int i=0; i<count; i++) // CALCULAR SALÁRIO BRUT0, DESCONTOS, SALÁRIO LÍQUIDO
    {
        prof[i].sal_bruto = prof[i].nr_horas * 60.50;
        if(prof[i].nr_horas <= 70)
        {
            if(prof[i].sexo == 'M')
            {
                prof[i].desc = 0.10 * prof[i].sal_bruto;
            }
            else
            {
                prof[i].desc = 0.07 * prof[i].sal_bruto;
            }
    
        }
        else
        {
            if(prof[i].sexo == 'M')
            {
                prof[i].desc = 0.08 * prof[i].sal_bruto;
            }
            else
            {
                prof[i].desc = 0.05 * prof[i].sal_bruto;
            }
        }

        if(prof[i].sexo == 'M')
        {
            soma_sal_masc += prof[i].sal_bruto;
            count_masc ++;
        }
        else
        {
            soma_sal_fem += prof[i].sal_bruto;
            count_fem ++;
        }
        
        prof[i].sal_liq = prof[i].sal_bruto - prof[i].desc;
    }

    printf("Listagem dos professores...\n");
    for(int i=0; i<count; i++)
    {
        printf("Professor %d\n", i+1);
        printf("Código: %d\n", prof[i].cod);
        printf("Salário Bruto: R$ %.2f\n", prof[i].sal_bruto);
        printf("Desconto: R$ %.2f\n", prof[i].desc);
        printf("Salário líquido: R$ %.2f\n", prof[i].sal_liq);
        printf("\n\n");
    }
    media_masc = soma_sal_masc / count_masc;
    media_fem = soma_sal_fem / count_fem;

    printf("A média dos salários brutos do sexo masculino: %.2f\n", media_masc);
    printf("A média dos salários brutos do sexo feminino: %.2f\n", media_fem);

    
    return 0;
}