#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Biblioteca para colocar um temporizador
#include <ctype.h>

/*1. Faça um programa que realize o cadastro de contas bancárias com as seguintes informações: número
da conta, nome do cliente e saldo. O banco permitirá o cadastramento de apenas 15 contas e não poderá haver mais que uma conta com o mesmo número. Crie o menu de opções a seguir.
Menu de opções:
1. Cadastrar contas.
2. Visualizar todas as contas de determinado cliente.
3. Excluir a conta com menor saldo (supondo a não existência de saldos iguais).
4. sair.*/


int soma_conta = 0;
char x[10] = {" "};
struct contas
{
	int n_conta;
	char nome[22];
	float saldo;
};
	struct contas dados[15];
void cadastrar() // Sub-rotina para cadastrar as contas - opção 01
{
	char resp_usr, resp_usr2;
	int conta = 0;

	printf("********************************\n");
	printf(">>>>>> CADASTRAR CONTAS <<<<<<<<\n");// Menu de cadastro 
	printf("********************************\n");

	if(soma_conta == 15) // Verificar se há 15 contas cadastradas, caso contrário, continuar com o processo
	{
		printf("Não é possível cadastrar mais contas em nosso sistema...\n");
	}
	else
	{

		for(int i=0; i<15; i++) // Looping para adicionar 15 contas 
		{
			printf("# %d # Digite um número de 4 dígitos para sua conta >> ", i+1);
			scanf("%d", &dados[i].n_conta);
			fflush(stdin);

			while (dados[i].n_conta < 1000 || dados[i].n_conta > 9999) // Verificação para o caso de o usuário digitar números superiores a 4 dígitos
			{
				printf("Número de conta inválido... Você deve inserir um número de 4 dígitos...\n");
				fflush(stdin);
				printf("# %d # Digite um número de 4 dígitos para sua conta >> ", i+1);
				scanf("%d", &dados[i].n_conta);
				fflush(stdin);
			}

			printf("Conta: %d >> Informe o seu nome: ", dados[i].n_conta);
			fgets(dados[i].nome, 22, stdin);
			fflush(stdin);

			printf("Conta: %d >> Cliente: %s >> Informe o saldo na conta (R$): ", dados[i].n_conta, dados[i].nome);
			scanf("%f", &dados[i].saldo);

			printf("\nVerifique seus dados\n\n");
			printf("Conta Cadastrada: %d >> Cliente: %s >> Saldo Atual: R$ %.2f\n\n", dados[i].n_conta, dados[i].nome, dados[i].saldo);
			fflush(stdin);
			soma_conta ++;

			printf("Deseja confirmar esta conta >> S - SIM | N - NÃO >> ");
			scanf(" %c", &resp_usr);
			resp_usr = toupper(resp_usr);
			fflush(stdin);

			if(resp_usr == 'N')
			{
				dados[i].n_conta = 1;
				dados[i].saldo = 1;
				strcpy(dados[i].nome, x);
				soma_conta --;
				printf("Conta excluída do banco de dados...\n\n");
			}

			for(int j=0; j<15; j++)
			{
				if(i != j && dados[i].n_conta == dados[j].n_conta)
				{
					printf("A conta a ser cadastrada possui o mesmo número que uma outra conta cadastrada...\n");
					printf("Não será possível cadastrar esta conta... Por favor, tente novamente mais tarde.\n");
					dados[i].n_conta = 1;
					break;
				}
			}

			printf("Deseja continuar S - SIM / N - NÃO >> ");
			scanf("%c", &resp_usr2);
			resp_usr2 = toupper(resp_usr2);

			if(resp_usr2 == 'N')
			{
				system("cls");
				break;
			}

			printf("\n\n");
		}
	}
}


void visualizar() // 02 - Visualizar uma conta 
{
	char nome_usr[22];
	int achou = 1;
	system("cls");
	printf("*****************************************************************\n");
	printf("****** VISUALIZAR TODAS AS CONTAS DE DETERMINADO CLIENTE   ******\n");
	printf("*****************************************************************\n");

	if(soma_conta == 0)
	{
		printf("NÃO HÁ CONTAS CADASTRADAS EM NOSSO SISTEMA...\n\n");
		Sleep(3000);
		system("cls");
	}
	else
	{
		fflush(stdin);
		printf("Digite o seu nome: ");
		fgets(nome_usr, 22, stdin);
		fflush(stdin);

		for(int i=0; i<soma_conta; i++)
		{
			if(dados[i].n_conta != 1 && (strcmp(dados[i].nome, nome_usr)==0))
			{
				achou = 0;
				printf("Conta >> #%d >> Cliente >> %s >> Saldo: R$ %.2f\n", dados[i].n_conta, dados[i].nome, dados[i].saldo);
			}
		}

		if(achou != 0)
		{
			printf("O nome informado não conta em nosso banco de dados...\n");
		}


		printf("\n\n");
		system("pause");
		system("cls");
	}

}

void excluir() // 03 - Excluir a conta com menor saldo
{

	float menor;
	int m_nconta;
	char menor_nome[22];
	printf("********************************************************\n");
	printf("********    Excluir a conta com menor saldo     ********\n");
	printf("********************************************************\n");

	if(soma_conta == 0)
	{
		printf("Não há contas cadastradas...\n");
		Sleep(3000);
		system("cls");
	}
	else 
	{	
		menor = dados[0].saldo;
		for(int i=0; i<soma_conta; i++)
		{
			if(i==0)
			{
				menor = dados[i].saldo;
				m_nconta = dados[i].n_conta;
				strcpy(menor_nome, dados[i].nome);
			}
			if(dados[i].saldo != 1 && dados[i].saldo < menor)
			{
				menor = dados[i].saldo;
				m_nconta = dados[i].n_conta;
				strcpy(menor_nome, dados[i].nome);
				printf("Conta a ser excluida --> # %d --> Cliente: %s\n", m_nconta, menor_nome);
				dados[i].n_conta = 1;

			}
		}
	}
}

int main() // Sub-Rotina principal
{
	int op;

	do
	{
		printf("***************************************************\n");
		printf("************   MENU DE OPÇÕES     *****************\n");
		printf("***** [01] - Cadastrar contas                   ***\n");
		printf("***** [02] - Visualizar uma conta               ***\n");
		printf("***** [03] - Excluir a conta com menor saldo    ***\n");
		printf("***** [04] - Sair                               ***\n");
		printf("***************************************************\n");
		printf(">>>>> Escolha uma opção: ");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			system("cls");
			cadastrar();
			break;
		case 2:
			system("cls");
			visualizar();
			break;
		case 3: 
			system("cls");
			excluir();
			break;
		case 4:
			break;
		default:
			system("cls");
			printf("Código inválido... Tente novamente...\n");
			Sleep(1000);
		}

	} while (op != 4);

	system("cls");
	system("pause");
	return 0;
}