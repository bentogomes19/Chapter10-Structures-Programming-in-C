#include <stdio.h>
#include <stdlib.h>
#include "dados.h" // Struct Funcionarios
#include <windows.h>
#include <string.h>
#include <ctype.h>
int count = 0;

/*6. Uma empresa contratou 15 funcionários temporários. De acordo com o valor das vendas mensais, os
funcionários ganham pontos que determinarão seus salários ao fim de cada mês. sabe-se que eles trabalharão nos meses de novembro de 2011 a janeiro de 2012. Faça um programa que:
a) Cadastre os nomes dos funcionários e suas respectivas vendas mensais.
b) Calcule e mostre a pontuação geral de cada funcionário nos três meses. sabe-se que R$ 100,00 equivalem a
1 ponto.
c) Calcule e mostre a pontuação geral de todos os funcionários a cada mês.
d) Determine e mostre a maior pontuação atingida nos três meses, mostrando o nome do funcionário. Deverão
ser desconsiderados empates.
e) Determine e mostre o valor total vendido.*/

void pontuacao_geral() // Calcule e mostre a pontuação geral de cada funcionário nos três meses.
{
    for(int i=0; i<count; i++)
    {
        printf("Funcionário %s", func[i].nome);
        pts = func[i].vendas_nov / 100;
        printf("Pontos de novembro: %d\n", pts);
        pts = func[i].vendas_dez / 100;
        printf("Pontos de Dezembro: %d\n", pts);
        pts = func[i].vendas_jan / 100;
        printf("Pontos de Janeiro: %d\n", pts);
        pts = (func[i].vendas_nov / 100) + (func[i].vendas_dez / 100) + (func[i].vendas_jan / 100);
        printf("Pontuação geral: %d\n\n", pts);
    }
}

void pontuacao_mes() //Calcule e mostre a pontuação geral de todos os funcionários a cada mês.
{
    pts = 0;
    printf("Pontuação no mês de NOVEMBRO...\n");
    for(int i=0; i<count; i++)
    {
        pts += func[i].vendas_nov / 100;
    }
    printf("Pontuação: %d\n", pts);

    pts = 0;
    printf("Pontuação no mês de DEZEMBRO...\n");
    for(int i=0; i<count; i++)
    {
        pts += func[i].vendas_dez / 100;
    }
    printf("Pontuação: %d\n", pts);

    pts = 0;
    printf("Pontuação no mês de JANEIRO...\n");
    for(int i=0; i<count; i++)
    {
        pts += func[i].vendas_jan / 100;
    }
    printf("Pontuação: %d\n", pts);
}

void maior_pts() // Determine e mostre a maior pontuação atingida nos três meses, mostrando o nome do funcionário. 
{
    char maior_nome[30], mes[20];
    maior = 0;
    for(int i=0; i<count; i++)
    {
        if(func[i].vendas_nov / 100 > maior)
        {
            maior = func[i].vendas_nov / 100;
            strcpy(maior_nome, func[i].nome);
            strcpy(mes, vet[i]);
        }
        if(func[i].vendas_dez / 100 > maior)
        {
            maior = func[i].vendas_dez / 100;
            strcpy(maior_nome, func[i].nome);
            strcpy(mes, vet[i]);
        }
        if (func[i].vendas_jan / 100 > maior)
        {
            maior = func[i].vendas_jan / 100;
            strcpy(maior_nome, func[i].nome);
            strcpy(mes, vet[i]);
        }
    }
    printf("Funcionário %s com maior pontuação: %d\n", maior_nome, maior);
    printf("No mês de %s\n", mes);

}

void valor_total() // Mostrar o valor total 
{
    int vlr_total = 0;
    for(int i=0; i<count; i++)
    {
        vlr_total += func[i].vendas_dez + func[i].vendas_jan + func[i].vendas_nov;
    }
    printf("O valor total vendido é: R$ %d\n\n", vlr_total);
}


int main(void)
{
    int resp;
    for(int i=0; i<15; i++)
    {
        fflush(stdin);
        printf("Funcionário %d\n", i+1);
        printf("Digite o nome do funcionário: ");
        fgets(func[i].nome, 30, stdin);
        fflush(stdin);

        printf("Digite a quantidade de vendas no mês %s : ", vet[0]);
        scanf("%f", &func[i].vendas_nov);
        fflush(stdin);

        printf("Digite a quantidade de vendas no mês %s : ", vet[1]);
        scanf("%f", &func[i].vendas_dez);
        fflush(stdin);

        printf("Digite a quantidade de vendas no mês %s : ", vet[2]);
        scanf("%f", &func[i].vendas_jan);
        fflush(stdin);

        count++;
        printf("Deseja continuar S/N ?: ");
        resp = getchar();
        resp=toupper(resp);
        fflush(stdin);

        if(resp == 'N')
        {
            break;
        }
        else
        {
            system("cls");
        }

    }
    system("cls");
    pontuacao_geral();
    pontuacao_mes();
    maior_pts();
    valor_total();

    return 0;
}