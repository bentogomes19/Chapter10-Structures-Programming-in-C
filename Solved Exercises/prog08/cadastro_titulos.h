#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrar_titulos()
{
    printf("Cadastrar Títulos...\n");
    for(int i=0; i<5; i++)
    {
        printf("Digite o código do título: ");
        scanf("%d", &titulo[i].cod_titulo);
        fflush(stdin);
    
        printf("Digite a descrição do título: ");
        fgets(titulo[i].desc, 30, stdin);
        titulo[i].desc[strcspn(titulo[i].desc, "\n")] = '\0';
        fflush(stdin);

        printf("Digite o valor da hora/aula (R$): ");
        scanf("%f", &titulo[i].valor_hora);
        fflush(stdin);

    }
    system("cls");
    printf("Códigos cadastrados\n");
    for(int i=0; i<5; i++)
    {
        printf("%d \t %s \t R$ %.2f\n", titulo[i].cod_titulo, titulo[i].desc, titulo[i].valor_hora);
    }

}