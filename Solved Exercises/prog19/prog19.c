#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define MAX 900
int c = 0;
/* VARIÁVEIS GLOBAIS */
struct medicos
{
    int cod_medico;    // codigo do medico
    char nome[40];     // nome do medico
    char endereco[60]; // endereco do medico
    float salario;     // salario do medico
};

struct pacientes
{
    int cod_paciente;  // codigo do paciente
    char nome[40];     // nome do paciente
    char endereco[60]; // endereco do paciente
    int idade;         // Idade do paciente
};

struct consultas
{
    int num_prontuario;   // numero do prontuario
    int data_consulta[3]; // data da consulta
    char diagnostico[60]; // diagnostico (ex: febre, dengue covid)
    int cod_medico;       // codigo do medico
    int cod_paciente;     // codigo do paciente
};

struct consultas consultas[MAX];
struct pacientes paciente[MAX];
struct medicos medico[MAX];

int count_pacientes = 0; // Contabiliza o numero de pacientes no sistema
int count_medicos = 0;   // Contabiliza o numero de medicos no sistema
int count_consultas = 0; // contabiliza o numero de consultas no sistema

void func_cadastrosMedPac(int op) // Função para o cadastro de pacientes e medicos
{
    bool achou;
    char resp;
    if (op == 1) // Cadastro medicos
    {
        if (count_medicos == MAX)
        {
            printf("O sistema atingiu o limite maximo de cadastros.\n Reinicie o programa.\n");
            system("pause");
            system("cls");
        }
        else
        {
            system("cls");
            printf("***************************\n");
            printf("##   CADASTRO MEDICOS   ##\n");
            printf("***************************\n");

            for (int i = count_medicos; i < MAX; i++)
            {
                do
                {
                    achou = false;
                    printf("Digite o codigo do medico: ");
                    scanf(" %d", &medico[i].cod_medico);
                    fflush(stdin);

                    for (int j = 0; j < count_medicos; j++)
                    {
                        if (i != j && medico[i].cod_medico == medico[j].cod_medico)
                        {
                            achou = true;
                        }
                    }
                    if (achou == true)
                    {
                        printf("Este codigo ja existe no sistema... Tente novamente\n");
                    }

                } while (achou == true);

                printf("Cod %d -> Digite o nome: ", medico[i].cod_medico);
                fgets(medico[i].nome, 40, stdin);
                medico[i].nome[strcspn(medico[i].nome, "\n")] = '\0';
                fflush(stdin);

                printf("Digite o endereco: ");
                fgets(medico[i].endereco, 60, stdin);
                medico[i].endereco[strcspn(medico[i].endereco, "\n")] = '\0';
                fflush(stdin);


                printf("Informe o salario (R$): ");
                scanf(" %f", &medico[i].salario);
                fflush(stdin);



                count_medicos++;
                printf("Medico cadastrado com sucesso...\n");

                printf("Deseja continuar s/n?: ");
                scanf(" %c", &resp);
                resp = toupper(resp);
                fflush(stdin);

                if (resp == 'N')
                {
                    system("cls");
                    break;
                }
                printf("\n\n");
            }
        }
    }
    if (op == 2) // cadastro pacientes
    {
        if (count_pacientes == MAX)
        {
            printf("O sistema atingiu o limite maximo de cadastros.\n Reinicie o programa.\n");
            system("pause");
            system("cls");
        }
        else
        {

            system("cls");
            printf("***************************\n");
            printf("##   CADASTRO PACIENTES  ##\n");
            printf("***************************\n");
            for (int i = count_pacientes; i < MAX; i++)
            {
                do
                {
                    achou = false;
                    printf("Digite o codigo do paciente: ");
                    scanf("%d", &paciente[i].cod_paciente);
                    fflush(stdin);

                    for (int j = 0; j < count_pacientes; j++)
                    {
                        if (i != j && paciente[i].cod_paciente == paciente[j].cod_paciente)
                        {
                            achou = true;
                        }
                    }
                    if (achou == true)
                    {
                        printf("Este codigo ja existe no sistema... Tente novamente\n");
                    }
                } while (achou == true);

                printf("Digite o nome do paciente: ");
                fgets(paciente[i].nome, 40, stdin);
                paciente[i].nome[strcspn(paciente[i].nome, "\n")] = '\0';
                fflush(stdin);



                printf("Digite o endereco: ");
                fgets(paciente[i].endereco, 60, stdin);
                paciente[i].endereco[strcspn(paciente[i].endereco, "\n")] = '\0';
                fflush(stdin);

                printf("Digite a idade: ");
                scanf("%d", &paciente[i].idade);
                fflush(stdin);


                count_pacientes++;
                printf("Paciente cadastrado com sucesso...\n");

                printf("Deseja continuar s/n?: ");
                scanf(" %c", &resp);
                resp = toupper(resp);
                fflush(stdin);

                
                if (resp == 'N')
                {
                    system("cls");
                    break;
                }
            }
        }
    }
}

void func_ExcluirMedicos() // Função para excluir um medico --> Se existir alguma consulta realizada por este medico, ele nao pode ser excluido
{
    int cod_medico, posi;
    bool achou;
    if (count_medicos == 0)
    {
        printf("Nao ha medicos cadastrados no sistema...\n");
        system("pause");
        system("cls");
    }
    else
    {
        system("cls");
        printf("**************************\n");
        printf("###  EXCLUIR MEDICOS  ###\n");
        printf("**************************\n");

        do
        {
            achou = false;
            printf("Digite o codigo do medico: ");
            scanf(" %d", &cod_medico);

            for (int j = 0; j < count_medicos; j++)
            {
                if (cod_medico == medico[j].cod_medico)
                {
                    achou = true;
                }
            }
            if (achou == false)
            {
                printf("o codigo informado nao existe...\n");
            }
        } while (achou == false);

        for (int i = 0; i < count_medicos; i++)
        {
            if (cod_medico == medico[i].cod_medico)
            {
                posi = i;
            }
        }
        achou = false;
        for (int i = 0; i < count_pacientes; i++)
        {
            if (cod_medico == consultas[i].cod_medico)
            {
                achou = true;
            }
        }
        if (achou == true)
        {
            printf("Este medico possui uma consulta cadastrada...\n");
            system("pause");
            system("cls");
        }
        else
        {
            printf("Verificar dados...\n");
            printf("Medico\n");
            printf("Codigo -> %d\n", medico[posi].cod_medico);
            printf("Nome -> %s\n", medico[posi].nome);
            printf("Endereco -> %s\n", medico[posi].endereco);
            printf("Salario ->  R$ %f\n", medico[posi].salario);

            printf("Pressione qualquer tecla para continuar...\n");
            getchar();

            medico[posi].cod_medico = medico[posi + 1].cod_medico;
            strcpy(medico[posi + 1].nome, medico[posi].nome);
            strcpy(medico[posi + 1].endereco, medico[posi].endereco);
            medico[posi].salario = medico[posi + 1].salario;
            count_medicos--;
            printf("Medico excluido com sucesso...\n");

            system("pause");
            system("cls");
        }
    }
}

void func_marcarConsultas()
{
    bool achou;
    int cod_medico, cod_paciente;
    if (count_medicos == 0 || count_pacientes == 0)
    {
        printf("Nao ha medicos cadastrados no sistema...\n [01] - Cadastrar Medicos [02] - Cadastrar Paciente\n");
        system("pause");
        system("cls");
    }
    else
    {
        int dia, mes, ano;
        system("cls");
        printf("**************************\n");
        printf("###  MARCAR CONSULTAS  ###\n");
        printf("**************************\n");

        for (int i = count_consultas; i < MAX; i++)
        {
            do
            {
                achou = false;
                printf("Informe o numero do prontuario: ");
                scanf("%d", &consultas[i].num_prontuario);
                fflush(stdin);

                for (int j = 0; j < count_consultas; j++)
                {
                    if (i != j && consultas[i].num_prontuario == consultas[j].num_prontuario)
                    {
                        achou = true;
                        break;
                    }
                }

                if (achou == true)
                {
                    printf("Este prontuario ja existe em nosso sistema...Tente novamente\n");
                }

            } while (achou == true);

            printf("# %d ## Informe a data da consulta: ", consultas[i].num_prontuario);
            scanf("%d %d %d", &dia, &mes, &ano);
            fflush(stdin);
            consultas[i].data_consulta[0] = dia;
            consultas[i].data_consulta[1] = mes;
            consultas[i].data_consulta[2] = ano;

            printf("# %d ## Informe o diagnostico: ", consultas[i].num_prontuario);
            fgets(consultas[i].diagnostico, 60, stdin);
            consultas[i].diagnostico[strcspn(consultas[i].diagnostico, "\n")] = '\0';
            fflush(stdin);

            do
            {
                achou = false;

                printf("# %d ## Digite o codigo do medico: ", consultas[i].num_prontuario);
                scanf("%d", &cod_medico);
                fflush(stdin);

                for (int j = 0; j < count_medicos; j++)
                {
                    if (cod_medico == medico[j].cod_medico)
                    {
                        achou = true;
                        break;
                    }
                }
                if (achou == false)
                {
                    printf("Medico nao encontrado...\n");
                }

            } while (achou == false);
            consultas[i].cod_medico = cod_medico;

            do
            {
                achou = false;

                printf("# %d ## Digite o codigo do paciente: ", consultas[i].num_prontuario);
                scanf("%d", &cod_paciente);
                fflush(stdin);

                for (int j = 0; j < count_pacientes; j++)
                {
                    if (cod_paciente == paciente[j].cod_paciente)
                    {
                        achou = true;
                        break;
                    }
                }
                if (achou == false)
                {
                    printf("Paciente nao encontrado...\n");
                }

            } while (achou == false);
            consultas[i].cod_paciente = cod_paciente;


            count_consultas++;
            printf("Data da consulta: ");
            for (int k = 0; k < 3; k++)
            {
                printf(" %d - ", consultas[i].data_consulta[k]);
            }
            printf("\n");
            system("pause");
            printf("Consulta marcada com sucesso...");
            Sleep(1200);
            break;
        }
    }
}

void func_mostrarConsultas()
{
    char nome_medico[400], nome_paciente[40];
    int dia, mes, ano, posi;
    bool achou;
    if (count_consultas == 0)
    {
        printf("Nao ha consultas cadastradas...\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Digite uma data: ");
        scanf("%d %d %d", &dia, &mes, &ano);
        fflush(stdin);

        achou = false;
        for (int i = 0; i < count_consultas; i++)
        {
            if (dia == consultas[i].data_consulta[0] && mes == consultas[i].data_consulta[1] && ano == consultas[i].data_consulta[2])
            {
                achou = true;
                printf("Consulta = %d\n", consultas[i].num_prontuario);
                printf("Diagnostico = %s\n", consultas[i].diagnostico);
                for (int j = 0; j < count_medicos; j++)
                {
                    if (consultas[i].cod_medico == medico[j].cod_medico)
                    {
                        strcpy(nome_medico, medico[j].nome);
                        printf("Medico: %s\n", nome_medico);
                    }
                }
                for (int k = 0; k < count_pacientes; k++)
                {
                    if (consultas[i].cod_paciente == paciente[k].cod_paciente)
                    {
                        strcpy(nome_paciente, paciente[k].nome);
                        printf("Paciente: %s\n", nome_paciente);
                    }
                }
            }
        }
        if (achou == false)
        {
            printf("Nao ha consultas cadastradas neste dia\n");
            system("pause");
            system("cls");
        }

        printf("\n");
        system("pause");
        system("cls");
    }
}

int main(void)
{
    int op;
    do
    {
        system("cls");
        printf("****************************************\n");
        printf("## CADASTROS DE PACIENTES E MEDICOS ##  \n");
        printf("****************************************\n");
        printf("[01] - Medicos\n");
        printf("[02] - Pacientes\n");
        printf("[03] - Excluir Medicos\n");
        printf("[04] - Marcar Consulta\n");
        printf("[05] - Mostrar Consultas\n");
        printf("[06] - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        case 2:
            func_cadastrosMedPac(op);
            break;
        case 3:
            func_ExcluirMedicos();
            break;
        case 4:
            func_marcarConsultas();
            break;
        case 5:
            func_mostrarConsultas();
            break;
        case 6:
            break;
        default:
            printf("Codigo invalido... Tente novamente...\n");
            system("pause");
            system("cls");
            break;
        }
    } while (op != 6);

    return 0;
}
