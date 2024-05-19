#ifndef REGISTROS_H
#define REGISTROS_H

#include <stdio.h>

/* REGISTROS DO PROGRAMA */
struct alunos // Informações referente aos alunos da escola
{
    int cod_aluno; // O código do aluno 
    char nome_aluno[30]; // Nome do aluno
    int serie; // A série em que o aluno estuda
};

struct Matricula // Informações referente a matrícula, sabe-se que cada aluno pode se matricular em, no máximo, 3 disciplinas a cada ano
{
    int cod_aluno; // Código do aluno
    int cod_disciplina; // Código da disciplina
    int total_faltas; // Total de Faltas que o aluno possui
    float nota_final; /// A nota final do aluno
};

struct Disciplina // Informações sobre a disciplina
{
    int cod_disciplina; // Código da Disciplina
    char desc[30]; // Descrição da disciplina ---> Ex: (Matemática, Portugues, História, ingles...)
    int carga_horaria; // A carga horária da disciplina
};

struct alunos alunos[10]; //Estrutura dos alunos
struct Matricula matricula[30]; // Informações referente a matrícula, sabe-se que cada aluno pode se matricular em, no máximo, 3 disciplinas a cada ano
struct Disciplina disciplina[6]; // Informações sobre a disciplina

/* VARIÁVEIS GLOBAIS */

int cont_discp = 0; // Contabiliza as disciplinas cadastradas no sistema, podemos cadastrar até 6 disciplinas 
int cont_alunos = 0; // Contabiliza os alunos cadastrados no sistema, podemos cadastrar até 10 alunos 
int cont_mat = 0; // Contabiliza as quantidade de matriculas no sistema
// int reprovado = 0; // Contabiliza os alunos reprovados no sistema media inferior a 7 e quantidade de faltas superior a 25% da carga horária da disciplina
#endif