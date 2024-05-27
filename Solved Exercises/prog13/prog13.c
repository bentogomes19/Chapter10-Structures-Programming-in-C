#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*2. A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre salário,
idade e número de filhos. Faça um programa que leia esses dados de 20 pessoas, calcule e mostre:

■■ a média de salário da população;

■■ a média do número de filhos;

■■ o maior salário;

■■ o percentual de mulheres com salário superior a R$ 1.000,00. */
struct habitantes
{
    int idade;
    float salario;
    int n_filhos;
    char sexo;
};
struct habitantes hab[20];

float media_sal(struct habitantes hab[], int cont_hab)
{
    float x, soma_sal = 0;
    for (int i = 0; i < cont_hab; i++)
    {
        soma_sal += hab[i].salario;
    }
    x = soma_sal / cont_hab;
    return x;
}

float media_filhos(struct habitantes hab[], int cont_hab)
{
    float y, soma_filhos = 0;
    for (int i = 0; i < cont_hab; i++)
    {
        soma_filhos += hab[i].n_filhos;
    }

    y = soma_filhos / cont_hab;
    return y;
}

float maior_sal(int cont_hab)
{
    float maior = 0;
    for (int i = 0; i < cont_hab; i++)
    {
        if (i == 0)
        {
            maior = hab[i].salario;
        }
        if (hab[i].salario > maior)
        {
            maior = hab[i].salario;
        }
    }
    return maior;
}

float func_perc_mulheres(int cont_hab)
{
    float perc, qtd_mulher2 = 0, qtd_mulher1 = 0;
    for (int i = 0; i < cont_hab; i++)
    {
        if (hab[i].sexo == 'F')
        {
            qtd_mulher1++;
            if (hab[i].salario > 1000)
            {
                qtd_mulher2++;
            }
        }
    }
    perc = (qtd_mulher2 / qtd_mulher1) * 100;
    return perc;
}

int main(void)
{
    char cod_char;
    char resp;
    float media1, media2, maior_salario, percentual;
    int cont_hab = 0;
    printf("*****************************************\n");
    printf("******** PREFEITURA DE AMERICANA ********\n");
    printf("*****************************************\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Habitante # %d -> Digite o seu salario (R$): ", i + 1);
        scanf("%f", &hab[i].salario);
        fflush(stdin);

        printf("Habitante # %d -> Digite a sua idade: ", i + 1);
        scanf("%d", &hab[i].idade);
        fflush(stdin);

        printf("Habitante # %d -> Digite o numero de filhos: ", i + 1);
        scanf("%d", &hab[i].n_filhos);
        fflush(stdin);

        printf("Habitante # %d -> Digite o seu sexo M ou F: ", i + 1);
        scanf("%c", &hab[i].sexo);
        hab[i].sexo = toupper(hab[i].sexo);
        fflush(stdin);
        cod_char = hab[i].sexo;
        cod_char = toupper(cod_char);

        cont_hab++;
        printf("Deseja continuar s/n?: ");
        resp = getchar();
        resp = toupper(resp);
        fflush(stdin);

        if (resp == 'N')
        {
            break;
        }
    }

    media1 = media_sal(hab, cont_hab);
    media2 = media_filhos(hab, cont_hab);
    maior_salario = maior_sal(cont_hab);
    percentual = func_perc_mulheres(cont_hab);

    printf("*******************************************\n");
    printf("************ DADOS IMPORTANTES ************\n");
    printf("*******************************************\n");

    printf("1. Media de salario da populacao: R$ %.2f\n", media1);
    printf("2. Media do numero de filhos: %.2f\n", media2);
    printf("3. O maior salario: R$ %.2f\n", maior_salario);
    printf("4. Percentual de mulheres com salario superior a R$ 1.000,00 : %.2f %%\n", percentual);

    return 0;
}