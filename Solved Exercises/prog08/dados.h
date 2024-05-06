#ifndef DADOS_H
#define DADOS_H

struct Professor
{
    int nr_registro;
    char nome[30];
    int cod_titulo;
    int total_horas;
    float total_geral;

}; struct Professor prof[14];


struct Titulo
{
    int cod_titulo;
    char desc[30];
    float valor_hora;
};  struct Titulo titulo[5];

int count = 0; // Contar o número de professores

#endif
