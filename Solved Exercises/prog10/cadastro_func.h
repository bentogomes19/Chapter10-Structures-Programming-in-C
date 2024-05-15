#ifndef CADASTROS_FUNC_H
#define CADASTROS_FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

#include "registros.h"
#include "menus.h"

void cadastro_func()
{
    float salario_usr;
    int cod_func_usr, filial_usr, achou, count1, count2;
    char nome_func_usr[30], cargo_usr[30], resp;

    if(count_fil == 0)
    {
        FUNC_0();
    }
    else if(count_func == 5)
    {
        FUNC_MAX();
    }
    else
    {
        
        for(int i=0; i<20; i++)
        {
            menu_footer2();
            do // Código do usuário 
            {
                achou = 0;
                printf("Digite o código do funcionário: ");
                scanf("%d", &cod_func_usr);
                fflush(stdin);

                for(int j=0; j<5; j++)
                {
                    if(cod_func_usr == func[j].cod_funcionario)
                    {
                        achou = 1;
                    }
                }
                if(achou == 1)
                {
                    printf("\nJá existe um funcionário com este número... Tente novamente...\n");
                    Sleep(2000);
                    system("cls");
                    menu_footer2();
                }
            } while (achou == 1);
            func[i].cod_funcionario = cod_func_usr;

            printf("Digite o nome do funcionário: ");
            fgets(nome_func_usr, 30, stdin);
            fflush(stdin);
            nome_func_usr[strcspn(nome_func_usr, "\n")] = '\0';
            strcpy(func[i].nome_funcionario, nome_func_usr);

            do
            {
                achou = 0;
                printf("Funcionário: %s >> Informe a filial: ", nome_func_usr);
                scanf("%d", &filial_usr);
                fflush(stdin);

                for(int k=0; k<count_fil; k++)
                {
                    if(filial_usr == filial[k].num_filial)
                    {
                        achou = 1; // Filial Encontrada
                    }
                }

                if(achou == 0) 
                {
                    printf("Filial não encontrada...\n");
                }

            } while (achou == 0);
            func[i].num_filial = filial_usr;
            count1 = 0;
            do
            {
                printf("Funcionário %s >> Digite o cargo (GERENTE OU VENDEDOR): ", nome_func_usr);
                fgets(cargo_usr, 30, stdin);
                fflush(stdin);
                cargo_usr[strcspn(cargo_usr, "\n")] = '\0';
                strcpy(func[i].cargo, cargo_usr);

                int posi, posi1;
                if(strcmp(cargo_usr, "gerente")==0) // Se o usuário for um gerente...
                {
                    count1 = 0;
                    for(int j=0; j<5; j++) // Verificar se na filial em que foi cadastrado possui mais de um gerente
                    {
                        if((strcmp(cargo_usr, func[j].cargo)==0) && func[j].num_filial == filial_usr)
                        {
                            count1 ++;
                            posi = j;
                        }
                    }
                    if(count1 == 2 && func[posi].num_filial == filial_usr)  // caso se confirmar mais de um gerente não permitir
                    {
                        printf("A filial já possui um gerente... Tente novamente...\n");
                        Sleep(1700);
                    }
                    else
                    {
                        count1 = 0;
                    }
                }
                if(strcmp(cargo_usr, "vendedor")==0)
                {
                    count1= 0;
                    for(int j=0; j<5; j++)
                    {
                        if((strcmp(cargo_usr, func[j].cargo)==0) && func[j].num_filial == filial_usr)
                        {
                            count1 ++;
                            posi1 = j;
                        }
                    }
                    if(count1 == 5 && func[posi1].num_filial == filial_usr)
                    {
                        printf("A filial já possui quatro vendedores... Tente novamente...\n");
                        Sleep(1700);
                    }
                    else
                    {
                        count1 = 0;
                    }
                }

            } while (count1 == 2 || count1 == 5);

            printf("Funcionário %s >> Informe o salário (R$): ", nome_func_usr);
            scanf("%f", &salario_usr);
            fflush(stdin);
            func[i].salario = salario_usr;

            printf("Deseja continuar S/N?: ");
            resp = getchar();
            resp=toupper(resp);
            fflush(stdin);


            if(resp == 'N')
            {
                system("cls");
                break;
            }

            count_func++;
            system("cls");
        }
        for(int j=0; j<count_func; j++)
        {       
            printf("Funcionário Nome: %s\n", func[j].nome_funcionario);
            printf("Funcionário Cargo: %s\n", func[j].cargo);
            printf("Funcionário Salário:  R$ %.2f\n", func[j].salario);
            printf("Funcionário Código: %d\n\n", func[j].cod_funcionario);
        }
        system("pause");
        system("cls");
    }
    
}


#endif