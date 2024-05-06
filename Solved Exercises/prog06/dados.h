#ifndef DADOS_H
#define DADOS_H
// Variáveis globais...
struct funcionarios // Estrutura funcionários
{
    char nome[30]; // Nome do funcionário
    float vendas_nov; // Vendas feitas por ele em novembro de 2011
    float vendas_dez; // Vendas em Dezembro de 2011
    float vendas_jan; // Vendas em Janeiro de 2012
};

struct funcionarios func[15];
int pts;
int maior;
char vet[3][20] = {"Novembro", "Dezembro", "Janeiro"};

#endif