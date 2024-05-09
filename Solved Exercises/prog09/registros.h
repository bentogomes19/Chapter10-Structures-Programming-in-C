#ifndef REGISTROS_H
#define REGISTROS_H
/* CONTROLE AUTOMATIZADO DE ESTOQUE... DADOS DOS REGISTROS + VARIÁVEIS COMPLEMENTARES */
struct cliente
{
    int cod_cliente; // Código do Cliente
    char end[60]; // Endereço
    char fone[20]; // Telefone
};

struct nota
{
    int num_NF; // Número da nota fiscal
    int cod_cliente; // Código do Cliente
    float total_geral; // Total de notas em geral
};

struct itens_nota
{
    int num_NF; // Número da nota fiscal
    int cod_produto; // Código do Produto
    int qtd; // Quantidade de produtos
    float preco_venda; // Preço de venda do produto
};

struct produto
{
    int cod_produto; // Código do produto
    char desc[30]; // Descrição do produto (Computador, Leite, Madeira...)
    char unidade[20]; // Tipo de produto (Eletrodomestico, Fruta, Roupa e etc..)
    float preco_unit; // Preço Unitário dos produtos
    int qtd_estoque; // Quantidade de produtos armazenados no estoque
};

struct cliente cli[3]; // Cadastro de 3 Clientes
struct nota nota[5] = {0}; // -> Gravações de 5 notas fiscais
struct itens_nota itens_nota[10] = {0}; // -> Dois itens em cada nota fiscal portanto 10 itens;
struct produto product[6]; // Cadastros de até 6 produtos


int count1 = 0; // Contabiliza os clientes cadastrados
int count2 = 0; // Contabiliza os produtos
int count3 = 0; // Contabiliza as 5 notas fiscais
int count4 = 0; // Contabiliza os itens da nota fiscal


#endif