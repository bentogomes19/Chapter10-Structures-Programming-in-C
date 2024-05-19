#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* BIBLIOTECAS COM FUNÇÕES E OS REGISTROS */
#include "registros.h"
#include "menus.h"
#include "cadastrar_disciplinas.h"
#include "cadastrar_alunos.h"
#include "matricula.h"
#include "lancamento.h"
#include "reprovados.h"
/*11. Crie um controle de matrícula anual de alunos em uma escola. sabe-se que nessa escola é permitida a
matrícula por disciplinas (o aluno monta seu horário). Esse controle deverá armazenar as informações
pertinentes apenas a um ano. A escola oferece, a cada ano, seis disciplinas; sabe-se que existem dez
alunos e que cada um pode matricular-se em, no máximo, três disciplinas a cada ano.

As informações devem estar estruturadas conforme os registros a seguir:
■■ Aluno (código do aluno, nome do aluno, série).

■■ Matrícula (código do aluno, código da disciplina, total de faltas, nota final).

■■ Disciplina (código da disciplina, descrição, carga horária).
O programa deverá seguir estas especificações:

■■ Cadastrar todas as disciplinas que poderão ser oferecidas no ano (não devem ser permitidas duas
disciplinas com o mesmo código).

■■ Cadastrar alunos (não devem ser permitidos dois alunos com o mesmo código e os valores válidos
para a série vão de 5 a 9).

■■ Realizar a matrícula do aluno (nesse momento, o aluno está apenas se inscrevendo na disciplina
que ainda não foi cursada. Dessa maneira, os campos ‘total de faltas’ e ‘nota final’ não deverão ser
preenchidos).

■■ lançamento dos resultados finais (a secretaria, ao final do ano letivo, informa o código do aluno
e o código da disciplina e preenche os campos ‘total de faltas’ e ‘nota final’ que estavam vazios).

■■ Criar uma consulta a todos os alunos reprovados nas disciplinas (a reprovação ocorrerá se a nota
for menor que 7 ou se o total de faltas ultrapassar 25% da carga horária da disciplina).

■■ Criar uma rotina que mostre o nome das disciplinas cursadas por determinado aluno, junto com o
total de faltas, a nota final e o resultado (aprovado ou reprovado).

*/
int main(void)
{   

    int op;
    do
    {
        menu_principal();
        printf("Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            cadastrar_disciplinas();
            break;
        case 2:
            system("cls");
            cadastrar_alunos();
            break;
        case 3:
            system("cls");
            matricula1();
            break;
        case 4:
            system("cls");
            lancamento();
            break;
        case 5:
            system("cls");
            reprovados();
            break;
        case 6:
            break;

        default:
            codigo_invalido(); // MENUS.H
            break;
        }

    } while (op != 7);


    return 0;
}