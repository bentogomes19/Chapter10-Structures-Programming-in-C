#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <windows.h>
#include <ctype.h>
#include "calcular_ht.h"

void cadastrofunc() // Cadastro dos funcionários
{
    char resp_usr;
    int cod;
    printf("Menu de Cadastro de Funcionários\n\n");

    if(count > 18)
    {
        printf("O sistema está lotado...Reinicie o programa...\n");
        Sleep(1000);
        system("cls");

    }
    else
    {   
        for(int i=0; i<18; i++)
        {
            fflush(stdin);
            printf("Digite o nome do funcionário: ");
            fgets(func[i].nome, 40, stdin);
            fflush(stdin);
            func[i].nome[strcspn(func[i].nome, "\n")] = '\0'; // Remove o caractere '\0'
            printf("Digite o número de horas trabalhadas do funcionário %s: ", func[i].nome);
            scanf(" %d", &func[i].nr_horas);
            fflush(stdin);

            do
            {
                cod = 0;
                printf("%s --> Digite o turno de trabalho M - MATUTINO |V - VESPERTINO | N - NOTURNO : ", func[i].nome);
                scanf(" %c", &func[i].turno);
                func[i].turno = toupper(func[i].turno);
                fflush(stdin);

                if(func[i].turno != 'M' && func[i].turno != 'V'  && func[i].turno != 'N')
                {
                    printf("Código inválido...Tente novamente...\n");
                    Sleep(500);
                    cod = 1;
                }

            } while (cod == 1);

            do
            {
                cod = 0;
                printf("%s --> Digite a categoria | O - Operário | G - Gerente : ", func[i].nome);
                scanf(" %c", &func[i].cat);
                func[i].cat = toupper(func[i].cat);
                fflush(stdin);

                if(func[i].cat != 'O' && func[i].cat != 'G')
                {
                    printf("Código inválido...Tente novamente...\n");
                    Sleep(500);
                    cod = 1;
                }
            } while (cod == 1);

            count ++;
            printf("Cadastro realizado com sucesso...\n");
            Sleep(800);
            system("cls");
            
            printf("Deseja continuar? S/N: ");
            scanf("%c", &resp_usr);
            resp_usr=toupper(resp_usr);

            if(resp_usr == 'N')
            {
                system("cls");
                break;

            }
        

        }
    }
}
