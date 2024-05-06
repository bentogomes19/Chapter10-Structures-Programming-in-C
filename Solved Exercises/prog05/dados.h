#ifndef DADOS_H
#define DADOS_H

struct dados // Dados referente aos funcionários
{
    char nome[40];
    int nr_horas;
    char turno;
    char cat;
    float vlr_hora;
    float sal_ini;
    float aux;
    float sal_final;
};

struct dados func[18];
int count = 0; // Contador para quantidade de funcionários cadastrados
float sal_min = 550;

#endif