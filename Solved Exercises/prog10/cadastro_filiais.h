#ifndef CADASTRO_FILIAIS_H
#define CADASTRO_FILIAIS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "registros.h"
#include "menus.h"

void cadastro_filiais() // Rotina cadastros de filiais --> observando que não podem existir duas filiais com o mesmo número.
{
    int num_filial_usr, achou;
    char nome_filial_usr[30], resp;
    if(count_fil == 4)
    {
        filial_MAX();
        
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            menu_footer();
            do
            {
                achou = 0;
                printf("Filial %d --> Digite o número da filial: ", i+1);
                scanf("%d", &num_filial_usr);
                fflush(stdin);
                filial[i].num_filial = num_filial_usr;

                for(int j=0; j<4; j++) // Verificar se há filiais com o mesmo número
                { 
                    if(i != j && num_filial_usr == filial[j].num_filial)
                    {
                        achou = 1; // Siginifica que localizou uma filial com o mesmo código 
                    }
                }

                if(achou == 1)// a condição é acionada quando o código inserido pelo usuário coincidir com o código armazenado no sistema
                {
                    printf("\nJá existe uma filial com este número... Tente novamente...\n");
                    Sleep(2000); 
                    system("cls");
                    menu_footer();
                }

            } while(achou == 1);

            printf("Filial %d --> Digite o nome da filial: ", i+1);
            fgets(nome_filial_usr, 30, stdin);
            fflush(stdin);
            filial[i].num_filial = num_filial_usr;
            strcpy(filial[i].nome_filial, nome_filial_usr); 
            
            count_fil++;

            printf("\nDeseja continuar S/N?: ");
            resp = getchar();
            resp = toupper(resp);
            fflush(stdin);

            if(resp == 'N')
            {
                system("cls");
                break;
            }

            system("cls");
        }
        system("cls");
        menu_footer();
        /* VISUALIZAR AS FILIAIS CADASTRADAS NO PROGRAMA */
        for(int i=0; i<count_fil; i++)
        {
            printf("\t\t\t\t Filial >> %d | Nome >> %s\n", filial[i].num_filial, filial[i].nome_filial);
        }
        system("pause");
        system("cls");
    }
}

#endif