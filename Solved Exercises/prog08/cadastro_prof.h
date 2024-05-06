#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

void cadastrar_prof()
{
    int achou;
    int codigo;
    float valor_hora;
    char desc[30], resp;
    printf("Cadastro de Professores...\n");
    for(int i=0; i<14; i++)
    {
        printf("\nProfessor %d > Digite o seu número de registro: ", i+1);
        scanf("%d", &prof[i].nr_registro);
        fflush(stdin);

        printf("\nProfessor %d > Digite o seu nome: ", i+1);
        fgets(prof[i].nome, 30, stdin);
        prof[i].nome[strcspn(prof[i].nome, "\n")] = '\0';
        fflush(stdin);

        printf("\nProfessor %d > Digite o total de horas/aulas semanais: ", i+1);
        scanf("%d", &prof[i].total_horas);
        fflush(stdin);

        do
        {
            achou = 0;
            printf("\nProfessor %d > Informe o código do título: ", i+1); // Título descrição
            scanf("%d", &prof[i].cod_titulo);
            codigo = prof[i].cod_titulo;
            fflush(stdin);

            for(int i=0; i<5; i++)
            {
                if(codigo == titulo[i].cod_titulo)
                {
                    achou = 1;
                    codigo = titulo[i].cod_titulo;
                    strcpy(desc, titulo[i].desc);
                    valor_hora = titulo[i].valor_hora;
                    break;
                }
            }
            if(achou == 1)
            {
                printf("\nTítulo: %d\n", codigo);
                printf("Descrição: %s\n", desc);
                printf("Valor da Hora/aula: R$ %.2f\n", valor_hora);
            }
            else
            {
                printf("Código inválido...Tente novamente...\n");
                Sleep(1000);
            }

        } while (achou == 0);
        count++;

        printf("\nDeseja continuar inserindo mais dados S/N?: ");
        resp = getchar();
        resp = toupper(resp);

        if(resp == 'N')
        {
            break;
        }
    }
}