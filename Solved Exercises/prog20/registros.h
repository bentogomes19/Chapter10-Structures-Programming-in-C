#ifndef REGISTROS_H
#define REGISTROS_H

struct obra 
{
    int num_tombo; // Numero do tombo
    int num_exemplar; // Numero do exemplar
    int data_compra[3]; // Data da compra da obra
}; 

struct tombo
{
    int num_tombo; // Numero do tombo
    char nome_obra[50]; // nome da obra
    char nome_autor[50]; // nome do autor
    char nome_editora[30]; // nome da editora
    int cod_area; // codigo da area
};


struct obra obra[60];
struct tombo tombo[20];

int count_obras = 0; // contabiliza o numero de obras cadastradas no sistema
int count_tombos = 0; // contabiliza o numero de tombos cadastrados no sistema




#endif