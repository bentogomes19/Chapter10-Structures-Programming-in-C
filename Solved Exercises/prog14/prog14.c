#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/*3. Foi realizada uma pesquisa sobre algumas características físicas de 50 habitantes de certa região. De cada
habitante foram coletados os seguintes dados: sexo, altura, idade e cor dos olhos (A – azuis; V – verdes; ou
C – castanhos).
Faça um programa que leia esses dados, armazene-os em um registro do tipo vetor e determine:

■■ a média de idade das pessoas com olhos castanhos e altura superior a 1,60 m;
■■ a maior idade entre os habitantes;
■■ a quantidade de indivíduos do sexo feminino com idade entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 1,70 m;
■■ o percentual de homens. */
struct habitantes
{
    char sexo;
    char cor_olhos;
    float altura;
    int idade;
};
struct habitantes hab[50];

void func_sexo(int i)
{
    do
    {
        printf("Habitante 👽 %d -> Digite o seu sexo (M ou F):  ", i + 1);
        scanf("%c", &hab[i].sexo);
        fflush(stdin);
        hab[i].sexo = toupper(hab[i].sexo);

        if (hab[i].sexo != 'F' && hab[i].sexo != 'M')
        {
            printf("Código inválido... Tente novamente...\n");
        }

    } while (hab[i].sexo != 'F' && hab[i].sexo != 'M');
}

void func_corOlhos(int i)
{
    do
    {
        printf("[A] - AZUIS\n");
        printf("[V] - VERDES\n");
        printf("[C] - CASTANHOS\n");
        printf("Habitante 👽 %d -> Digite a cor dos olhos: ", i + 1);
        scanf("%c", &hab[i].cor_olhos);
        hab[i].cor_olhos = toupper(hab[i].cor_olhos);
        fflush(stdin);

        if (hab[i].cor_olhos != 'A' && hab[i].cor_olhos != 'V' && hab[i].cor_olhos != 'C')
        {
            printf("Código inválido... Tente novamente...\n");
        }
    } while (hab[i].cor_olhos != 'A' && hab[i].cor_olhos != 'V' && hab[i].cor_olhos != 'C');
}

float func_media(int cont_hab) // Calcular a media de idade
{

    float media_hab, cont1 = 0, soma_id = 0;

    for (int i = 0; i < cont_hab; i++)
    {
        if (hab[i].cor_olhos == 'C' && hab[i].altura > 1.60)
        {
            soma_id += hab[i].idade;
            cont1++;
        }
    }

    if (cont1 > 0)
    {

        return media_hab = soma_id / cont1;
    }
    else
    {
        return media_hab = 0;
    }
}

int func_maior_id(int cont_hab) // Calcular a maior idade entre os habitantes
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

int func_qtdIndividuos(int cont_hab) // Calcula a quantidade de individuos
{
    int qtd = 0;

    for (int i = 0; i < cont_hab; i++)
    {
        if ((hab[i].sexo == 'F' && (hab[i].idade >= 20 && hab[i].idade <= 45)) || (hab[i].cor_olhos == 'V' && hab[i].altura <= 1.70))
        {
            qtd++;
        }
    }
    return qtd;
}

float func_percHomens(int cont_hab) // Calcular o percentual de homens
{
    float soma_homens = 0, perc;
    for (int i = 0; i < cont_hab; i++)
    {
        if (hab[i].sexo == 'M')
        {
            soma_homens++;
        }
    }
    return perc = (soma_homens / cont_hab) * 100;
}

int main(void)
{
    float media;
    float perc_homens;
    int maior_idade, qtd_individuos;
    char resp;
    int i;
    int cont_hab = 0;
    printf("************************************************\n");
    printf("********* PESQUISA IBGE - CAMPO GRANDE *********\n");
    printf("************************************************\n");
    printf("Pesquisa sobre as características fisicas de 50 habitantes da região\n\n");
    for (i = 0; i < 50; i++)
    {
        func_sexo(i);

        printf("Habitante 👽 %d -> Digite a sua altura (m): ", i + 1);
        scanf("%f", &hab[i].altura);
        fflush(stdin);

        printf("Habitante 👽 %d -> Digite a sua idade: ", i + 1);
        scanf("%d", &hab[i].idade);
        fflush(stdin);

        func_corOlhos(i); // Função para inserir a cor dos olhos
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
    printf("\n\n");
    media = func_media(cont_hab);
    maior_idade = func_maior_id(cont_hab);
    qtd_individuos = func_qtdIndividuos(cont_hab);
    perc_homens = func_percHomens(cont_hab);

    printf("❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌\n");
    printf("********* ANÁLISE DOS DADOS *********\n");
    printf("❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌\n");
    if (media == 0)
    {
        printf("Não houve pessoas com olhos castanhos e altura superior a 1.60 no sistema\n");
    }
    else
    {
        printf("a média de idade das pessoas com olhos castanhos e altura superior a 1,60 m: %.2f\n", media);
    }

    printf("A maior idade registrada entre os habitantes foi de: %d\n", maior_idade);
    printf("indivíduos do sexo feminino com idade entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 1,70 m: %d\n", qtd_individuos);
    printf("O percentual de homens na regiao é de: %.2f\n", perc_homens);

    return 0;
}