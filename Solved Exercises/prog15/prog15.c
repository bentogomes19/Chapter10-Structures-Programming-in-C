#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*4. Foi realizada uma pesquisa entre 20 habitantes de uma cidade. De cada habitante foram coletados estes dados:
idade, sexo, renda familiar e número de filhos. Faça um programa que leia esses dados, armazenando-os em
um vetor, calcule e mostre a média de salário entre os habitantes,
a menor e a maior idade do grupo e
 a quantidade de mulheres com mais de dois filhos e com renda familiar inferior a R$ 600,00.*/
struct habitantes
{
    int idade;
    char sexo;
    float renda_hab;
    int n_filhos;
};
struct habitantes hab[50];

float func_mediaSal(int cont_hab)
{
    float media;
    float rendas = 0;
    for (int i = 0; i < cont_hab; i++)
    {
        rendas += hab[i].renda_hab;
    }

    return media = rendas / cont_hab;
}

int func_maiorID(int cont_hab)
{
    int maior;
    for (int i = 0; i < cont_hab; i++)
    {
        if (i == 0)
        {
            maior = hab[i].idade;
        }
        if (hab[i].idade > maior)
        {
            maior = hab[i].idade;
        }
    }
    return maior;
}

int func_menorID(int cont_hab)
{
    int menor;

    for (int i = 0; i < cont_hab; i++)
    {
        if (i == 0)
        {
            menor = hab[i].idade;
        }
        if (hab[i].idade < menor)
        {
            menor = hab[i].idade;
        }
    }

    return menor;
}

int func_qtdmulher(int cont_hab)
{
    int qtd_mulher = 0;
    for (int i = 0; i < cont_hab; i++)
    {
        if (hab[i].sexo == 'F' && hab[i].n_filhos > 2 && hab[i].renda_hab < 600)
        {
            qtd_mulher++;
        }
    }

    return qtd_mulher;
}

int main(void)
{
    float media_sal;
    int menor_id, maior_id, qtd_mulheres;
    char resp;
    int i, cont_hab = 0;

    for (i = 0; i < 50; i++)
    {
        printf("Habitante %d -> Digite a sua idade: ", i + 1);
        scanf("%d", &hab[i].idade);
        fflush(stdin);

        do
        {
            printf("Habitante %d -> Digite o seu sexo (M - MASCULINO | F - FEMININO): ", i + 1);
            scanf("%c", &hab[i].sexo);
            hab[i].sexo = toupper(hab[i].sexo);
            fflush(stdin);

            if (hab[i].sexo != 'M' && hab[i].sexo != 'F')
            {
                printf("Código invalido... Tente novamente...\n");
            }

        } while (hab[i].sexo != 'M' && hab[i].sexo != 'F');

        printf("Habitante %d -> Digite sua renda familiar (R$): ", i + 1);
        scanf("%f", &hab[i].renda_hab);
        fflush(stdin);

        printf("Habitante %d -> Digite o numero de filhos: ", i + 1);
        scanf("%d", &hab[i].n_filhos);
        fflush(stdin);
        cont_hab++;

        printf("Deseja continuar s/n?: ");
        resp = getchar();
        resp = toupper(resp);
        fflush(stdin);

        if (resp == 'N')
        {
            break;
        }
        printf("\n");
    }

    media_sal = func_mediaSal(cont_hab);
    maior_id = func_maiorID(cont_hab);
    menor_id = func_menorID(cont_hab);
    qtd_mulheres = func_qtdmulher(cont_hab);

    printf("A media de salarios entre os habitantes: %.2f\n", media_sal);
    printf("A maior idade: %d\n", maior_id);
    printf("A menor idade: %d\n", menor_id);
    printf("A quantidade de mulheres com mais de dois filhos e com renda menor que R$ 600: %d\n", qtd_mulheres);

    return 0;
}