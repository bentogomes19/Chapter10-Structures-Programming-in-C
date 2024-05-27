/*First program in linux */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct estados
{
    char nome[40];     // Nome do estado
    int num_veiculo;   // Numero de veículos que circularam nesse estado (em 2012)
    int num_acidentes; // Número de acidentes de trânsito em 2012
};
struct estados estados[15];

float perc_carros[15];

void clear_buffer()
{
    int c = 0;
    while((c = getchar()) != '\n' && c != EOF);
}

void func_maiorAcidente()
{
    int maior;
    char maior_estado[40];
    for (int i = 0; i < 15; i++)
    {
        if (i == 0)
        {
            maior = estados[i].num_acidentes;
            strcpy(maior_estado, estados[i].nome);
        }
        if(estados[i].num_acidentes > maior)
        {
            maior = estados[i].num_acidentes;
            strcpy(maior_estado, estados[i].nome);
        }

    }

    printf("O estado do %s tem o maior indice de acidentes com %d acidentes no ano de 2012.\n", maior_estado, maior);
}

void func_menorAcidente(int count_estados)
{
    int menor;
    char menor_estado[40];
    for (int i = 0; i < count_estados; i++)
    {
        if (i == 0)
        {
            menor = estados[i].num_acidentes;
            strcpy(menor_estado, estados[i].nome);
        }
        if(estados[i].num_acidentes < menor)
        {
            menor = estados[i].num_acidentes;
            strcpy(menor_estado, estados[i].nome);
        }

    }

    printf("O estado do %s tem o menor indice de acidentes com %d acidentes no ano de 2012.\n", menor_estado, menor);
}

void func_percentual(int count_estados)
{

    float total_veiculos = 0;
    float perc;
    for (int i = 0; i < count_estados; i++)
    {
        total_veiculos += estados[i].num_veiculo;
    }
    for (int i = 0; i < count_estados; i++)
    {
        perc_carros[i] = (estados[i].num_veiculo / total_veiculos) * 100;
        printf("O percentual de veículos no estado %d é de %.2f %%.\n", i+1, perc_carros[i]);
    }

}

void func_mediaAcidentes(int count_estados)
{

    for (int i = 0; i < count_estados; i++)
    {
        double media = (double) estados[i].num_acidentes / estados[i].num_veiculo;
        printf("A média de acidentes no estado %d foi de %.2f\n", i+1, media);
    }
    
}

int main(void)
{
    float percentual;
    int count_estados = 0;
    char resp;
    printf("=======================================================\n");
    printf("######   PESQUISA SOBRE ACIDENTES DE TRANSITO   ###### \n");
    printf("=======================================================\n");
    printf("Será realizada uma pesquisa em 15 estados brasileiros...\n\n");
    for (int i = 0; i < 15; i++) // laço de repetição para a pesquisa nos 15 estados
    {
        printf("Digite o nome do estado: ");
        fgets(estados[i].nome, 40, stdin); // coleta dados em formato string (caracteres)
        estados[i].nome[strcspn(estados[i].nome, "\n")] = '\0';

        printf("Informe o numero de veiculos em 2012: ");
        scanf(" %d", &estados[i].num_veiculo);
        
        printf("Informe o numero de acidentes em 2012: ");
        scanf(" %d", &estados[i].num_acidentes);
        clear_buffer();

        count_estados ++;
        printf("Deseja continuar s/n ?: ");
        scanf(" %c", &resp);
        resp = toupper(resp);
        clear_buffer();

        if( resp == 'N')
        {
            break;
        }
    }
    func_maiorAcidente();
    func_menorAcidente(count_estados);
    printf("\n");
    func_percentual(count_estados);
    printf("\n");
    func_mediaAcidentes(count_estados);

    return 0;
}