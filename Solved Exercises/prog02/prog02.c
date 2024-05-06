#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
/*2. Uma empresa prestadora de serviços armazena informações sobre os serviços prestados. sabe-se que a
empresa pode realizar no máximo três serviços diariamente. É de interesse de sua direção manter um
histórico mensal (30 dias) sobre os serviços prestados.
A empresa realiza quatro tipos de serviços: 1) pintura; 2) jardinagem; 3) faxina e 4) reforma em geral.
Cada serviço realizado deve ser cadastrado com as seguintes informações: número do serviço, valor do serviço, código do serviço e código do cliente.
Cadastre os quatro tipos de serviços (código e descrição) que a empresa poderá realizar. Para isso, utilize um vetor de quatro posições.

O programa deverá mostrar o seguinte menu de opções:
1. Cadastrar os tipos de serviços.
2. Cadastrar os serviços prestados.
3. Mostrar os serviços prestados em determinado dia.
4. Mostrar os serviços prestados dentro de um intervalo de valor.
5. Mostrar um relatório geral (separado por dia), que exiba, inclusive, a descrição do tipo do serviço.
6. Finalizar.
Para a opção 1: deve-se cadastrar os tipos de serviços oferecidos pela empresa, com código e descrição.
Para a opção 2: deve-se considerar que deverão ser cadastrados os serviços prestados ao longo do mês.
Em cada dia podem ser cadastrados, no máximo, três serviços prestados.
Utilize uma matriz capaz de armazenar em cada posição todas as informações referentes a um serviço
prestado. Cada linha representa um dia do mês. Dessa maneira, considere a matriz com dimensão 30 × 3.
solicite o dia em que o serviço foi prestado e as demais informações.
lembre-se de que a empresa só pode prestar os serviços que já tenham sido cadastrados no vetor de
tipo de serviços.
Caso o usuário digite um código de tipo de serviço inválido, o programa deverá mostrar uma mensagem de erro.
Quando o usuário tentar cadastrar mais de três serviços prestados em um mesmo dia, também deverá
mostrar uma mensagem de erro.
Para a opção 3: o programa deverá receber o dia que se deseja consultar e mostrar os respectivos serviços prestados.
Para a opção 4: o programa deverá receber o valor mínimo e o valor máximo e mostrar os serviços
prestados que estiverem nesse intervalo.
Para a opção 5: o programa deverá mostrar todos os serviços prestados, conforme o exemplo a seguir.*/
struct servicos
{
    int cod;
    char nome[22];
};

struct servicos2
{
    int num, cod_serv, cod_cliente;
    float valor;
};

struct servicos tipos[3];
struct servicos2 serv[30][3];
int count = 0;

void tipos_servicos() // 01- Cadastrar os tipos de serviços
{
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<3; j++)
        {
            serv[i][j].num = 0;
            serv[i][j].cod_serv = 0;
            serv[i][j].cod_cliente = 0;
            serv[i][j].valor = 0;
        }
    }
    char resp;
    char nome_cod[22];

    printf(">>>>>>>  Cadastrar os tipos de serviços   <<<<<<<\n");
    if(count == 3)
    {
        system("cls");
        printf("Cadastro de tipos de serviços lotado.\n");
        Sleep(2000);
        printf("Reiniciando o sistema...\n");
        Sleep(1000);
        system("cls");
        count = 0;
        printf(">>>>>>>  Cadastrar os tipos de serviços   <<<<<<<\n");
    }
    if (count >= 0 && count <= 2)
    { 
        int i = 0;
           do
           {
                int k = 0;
                printf("\nServiços restantes >> %d/%d\n", count, 3);
                printf("\n\n>>>> Descrição dos serviços <<<<\n");
                printf("#%d# Digite o código do serviço a ser cadastrado >> ", i+1);
                scanf("%d", &tipos[i].cod);
                fflush(stdin);

                for(int j=0; j<3; j++)
                {
                    if(i != j && tipos[i].cod == tipos[j].cod)
                    {
                        system("cls");
                        printf("\n\nJá existe um tipo de serviço cadastrado com esse código\n");
                        printf("Tente novamente...\n");
                        i--;
                        k = 1;
                        Sleep(1000);
                        break;
                    }
                }  

                if(k == 0)
                {
                    printf("\n\n>>>> Descrição dos serviços <<<<\n");
                    printf("[01] Pintura\n");
                    printf("[02] Jardinagem\n");
                    printf("[03] Faxina\n");
                    printf("[04] Reforma em geral\n");
                    printf("> %d | Digite a descrição do tipo de serviço com esse código: ", i+1);
                    fgets(nome_cod, 22, stdin);
                    fflush(stdin);
                    strcpy(tipos[i].nome, nome_cod);

                    printf("Confirme seus dados: Código: %d --> Descrição: %s\n", tipos[i].cod, nome_cod);
                    system("pause");
                    fflush(stdin);
                    count++;
                    system("cls");
                    printf("Deseja continuar realizar os cadastros -> S/N ?: ");
                    scanf("%c", &resp);
                    resp = toupper(resp);

                    if(resp == 'N')
                    {
                        printf("Serviços cadastrados\n");

                        for(int i=0; i<count; i++)
                        {   
                            printf("Código: %d --> Serviço: %s\n", tipos[i].cod, tipos[i].nome);
                        }

                        system("pause");
                        system("cls");
                        break;
                    }
                }
                i++;

                if(count == 3)
                {
                    system("cls");
                    printf("Serviços cadastrados\n");
                    for(int i=0; i<count; i++)
                    {
                        printf("Código: %d --> Serviço: %s\n", tipos[i].cod, tipos[i].nome);
                    }
                    system("pause");
                    printf("Cadastro de tipos de serviços lotado.\n");
                    Sleep(1000);
                    system("cls");
                    break;
                }

           } while (count < 4);
    }
} 

void servicos_prestados() // 02 - Cadastrar os serviços prestados
{
    printf(">>>> Serviços Prestados <<<<<\n");

    for(int i=0; i<count; i++)
    {
        printf("Código: %d --> Serviço: %s\n", tipos[i].cod, tipos[i].nome);
    }
    int dia_usr;
    int m;
    int codigo_serv, valida, num_serv, codigo_cliente;
    float valor_serv;

        printf("Digite o dia em que deseja cadastrar o serviço prestado: ");
        scanf("%d", &dia_usr);
        m = 0;
        for(int j=0; j<3; j++)
        {
            if (serv[dia_usr][j].num == 0)
            {
                m = j;
            }
        }
        if(m == 0)
        {
            printf("Todos os serviços prestados neste dia já foram cadastrados...\n");
        }
        else
        {
            printf("Digite o código do serviço a ser cadastrado: ");
            scanf(" %d", &codigo_serv);
            valida = 0;
            for(int i=0; i<count; i++)
            {
                if(tipos[i].cod == codigo_serv)
                {
                    valida = 1;
                }
            }
            if(valida == 0)
            {
                printf("Código de serviço inválido...\n");
            }
            else
            {
                printf("Digite o número do serviço: ");
                scanf(" %d", &num_serv);

                printf("Digite o valor do serviço (R$): ");
                scanf(" %f", &valor_serv);

                printf("Digite o código do cliente: ");
                scanf(" %d", &codigo_cliente);

                serv[dia_usr][m].num = num_serv;
                serv[dia_usr][m].valor = valor_serv;
                serv[dia_usr][m].cod_serv = codigo_serv;
                serv[dia_usr][m].cod_cliente = codigo_cliente;
                printf("Serviço prestado cadastrado com sucesso..\n");
                system("pause");
            }
        }
} 

void mostrar_servicos() // 03 - Mostrar os serviços prestados em determinado dia.
{
    int data;
    int achou = 0;
    printf(">>> Mostrar os serviços prestados em determinado dia <<<\n");
    printf("Digite um dia: ");
    scanf("%d", &data);

    for(int i=0; i<30; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(serv[data][j].cod_serv == serv[i][j].cod_serv && serv[i][j].cod_serv != 0)
            {
                printf("\nServiço #%d\n\n", i+1);
                printf("Serviço código: %d\n", serv[data][j].cod_serv);
                printf("Código do cliente: %d\n", serv[data][j].cod_cliente);
                printf("Número do Serviço: %d\n", serv[data][j].num);
                printf("Valor do serviço: %.2f\n", serv[data][j].valor);
                achou = 1;
            }
        }
    }
    if(achou == 0)
    {
        printf("Não houve serviços prestados neste dia...\n");
        system("pause");
    }

}

void mostrar_servicos2() // 04 - Mostrar os serviços prestados dentro de um intervalo de valor.
{
    int achou = 0;
    float vlr_minimo, vlr_maximo;
    printf(">>> Mostrar os serviços prestados dentro de um intervalo de valor <<<\n\n");

    printf(">>> Digite o valor mínimo: ");
    scanf("%f", &vlr_minimo);

    printf(">>> Digite o valor mínimo: ");
    scanf("%f", &vlr_maximo);

    for(int i=0; i<30; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(serv[i][j].valor >= vlr_minimo && serv[i][j].valor <= vlr_maximo)
            {
                printf("\nServiço #%d\n\n", i+1);
                printf("Serviço código: %d\n", serv[i][j].cod_serv);
                printf("Código do cliente: %d\n", serv[i][j].cod_cliente);
                printf("Número do Serviço: %d\n", serv[i][j].num);
                printf("Valor do serviço: %.2f\n", serv[i][j].valor);
                achou = 1;
            }
        }
    }
    if(achou == 0)
    {
        printf("Não há serviços nesta faixa de preço...\n");
        system("pause");
    }
} 

void relatorio() // 05 - Mostrar um relatório geral, mostrar a descrição do tipo do serviço.
{
    printf("*********************************************\n");
    printf("**              RELATÓRIO GERAL            **\n");
    printf("*********************************************\n");
    int achou = 0;
    if(count == 0)
    {
        printf("Não há serviços gravados no sistema...\n");;
    }
    else
    {
         for(int i=0; i<30; i++)
        {
            printf("Dia #%d\n", i+1);
            printf("Num do Serviço\tValor do Serviço\tCódigo do serviço\tDescrição\tCódigo do Cliente\n");
            for(int j=0; j<3; j++)
            {
                if(serv[i][j].cod_serv != 0)
                {
                    printf("%d\t R$ %.2f\t %d\n", serv[i][j].num, serv[i][j].valor, serv[i][j].cod_serv);
                    achou = 1;
                }
            }
        }
    }

}

int main() 
{   
    int op;

    do
    {
        printf("********  Menu de Opções  **********\n");
        printf(" [01] - Cadastrar os tipos de serviços\n");
        printf(" [02] - Cadastrar os serviços prestados\n");
        printf(" [03] - Mostrar os serviços prestados em um determinado dia\n");
        printf(" [04] - Mostrar os serviços prestados dentro de um intervalo de valor\n");
        printf(" [05] - Relatório Geral\n");
        printf(" [06] - Sair\n ");
        printf("Escolha uma opção >> ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            tipos_servicos();
            break;
        case 2:
            system("cls");
            servicos_prestados();
            break;
        case 3:
            system("cls");
            mostrar_servicos();
            break;
        case 4:
            system("cls");
            mostrar_servicos2();
            break;
        case 5:
            system("cls");
            relatorio();
            break;
        case 6:
            system("cls");
            break;

        default:
            system("cls");
            printf("Código inválido... Tente novamente...\n");
            Sleep(1000);
        }
        
    } while (op != 6);
    
    return 0;
}