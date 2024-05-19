#ifndef REGISTROS_H
#define REGISTROS_H
/*REGISTROS E VARIÁVEIS GLOBAIS */

struct vendedores // Estrutura de dados homogênea sobre os vendedores da loja
{
    int cod_vendedor; // Código do vendedor
    char nome[30]; // Nome do vendedor
    float soma_vendas; // A soma das vendas do vendedor(a) no em um determinado mes
    int qtd_vendas;
    
};

struct vendas // Estrutura de dados referente a uma venda a ser cadastrada no sistema
{
    int cod_vendedor; // Código do Vendedor
    char nome[30]; // nome do vendedor
    float valor_venda; // O valor de uma venda realizada por esse vendedor
    int mes_venda; // O mês em que o vendedor(a) efetuou a venda
};

struct vendedores vendedores[4];
struct vendas vendas[100];


int total_vendas[12] = {0}; // O total de vendas da empresa  realizadas em cada mes (ex: MES 1 --> 12 MES 2 --> 5 ...)
int cont_vendedores = 0; // Contabiliza o número de vendedores cadastrados no sistema
int cont_vendas = 0; // Contabiliza o número de vendas cadastradas no sistema

#endif