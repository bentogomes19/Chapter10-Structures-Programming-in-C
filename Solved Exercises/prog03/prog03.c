#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

/* 3. Faça um programa que utilize os registros a seguir.
CLIENTES        DOCUMENTOS
cod_cli          num_doc
nome            cod_cli
fone            data_venc
endereco        data_pag
                valor
                juros
                
sabe-se que um documento só pode ser cadastrado para um cliente que já exista. Considere que podem
existir, no máximo, 15 clientes e 30 documentos. Crie um vetor para clientes e outro para documentos. Crie
um menu para a realização de cada uma das operações especificadas a seguir.
a) Cadastrar clientes — não pode existir mais que um cliente com o mesmo código.
b) Cadastrar documentos — ao cadastrar um documento, se a data de pagamento for maior que a data de vencimento, calcular o campo ‘juros’ do registro documentos (5% sobre o valor original do documento).
c) Excluir clientes — um cliente só poderá ser excluído se não existir nenhum documento associado a ele.
d) Excluir documentos individuais — por meio de seu número. Caso o documento não exista, o programa deverá
mostrar a mensagem Documento não encontrado.
e) Excluir documentos por cliente — o programa deverá informar o código do cliente e excluir todos os seus
documentos. Caso o cliente não exista, deverá mostrar a mensagem Cliente não encontrado.
f) Excluir documentos por período — o programa deverá informar a data inicial e a data final e excluir todos os
documentos que possuam data de vencimento nesse período.
g) Alterar as informações sobre os clientes — só não pode ser alterado o código do cliente.
h) Mostrar o total de documentos de determinado cliente.
i) sair.
Quando forem excluídos clientes ou documentos, os vetores deverão ser reorganizados, ou seja, todas
as posições não preenchidas dos vetores deverão ficar no final. Exemplo: se for necessário excluir o número
8 do vetor a seguir, tanto o 9 quanto o 1 deverão ser movidos uma casa para a esquerda e a última posição
deverá ficar livre para uma nova inclusão. */


struct clientes // MAX 15 CLIENTES
{
    int cod_cliente;
    char nome[22], fone[30], endereco[60];
};

struct documentos // MAX 30 DOCUMENTOS
{
    int num_doc, cod_cliente, dia_ven, mes_ven, ano_ven, dia_pag, mes_pag, ano_pag;
    float valor, juros;
};

struct clientes client[15]; // Vetor para os clientes

struct documentos doc[30] = {0}; // Vetor para os documentos
int count = 0; // Contador de clientes
int count2 = 0; // Contador de Documentos
void cadastrar_client() // a) Cadastrar clientes — não pode existir mais que um cliente com o mesmo código.
{
    char resp_usr;
    int achou;
    int codigo, codigo_rep;
    printf("******   CADASTRAR CLIENTES   ******\n");
    printf("************************************\n");
    if(count == 15) 
    {
        printf("O sistema está lotado... Limite de 15 clientes...\n");
        Sleep(2000);
        system("cls");
        printf("Aguarde...\n");
        Sleep(1000);
        system("cls");
    }
    else
    {
        for( int i=0; i<15; i++) // Ler os dados dos 15 clientes
        {
            do
            {
                achou = 0;
                printf(" %d -> Digite o código do cliente > ", i+1); // CÓDIGO DO CLIENTE
                scanf("%d", &codigo);
                fflush(stdin);
                client[i].cod_cliente = codigo;

                for(int j=0; j<15; j++)
                {
                    if (i != j && codigo == client[j].cod_cliente) // verificando se há contas semelhantes
                    {
                        codigo_rep = client[j].cod_cliente;
                        printf("Nosso sistema já possui um cliente com o código que foi informado...\n");
                        printf("Código --> %d\n", codigo_rep);
                        achou = 1;
                    }
                }

            } while (achou != 0);

            printf("%d -> Digite o seu nome > ", i+1); // NOME DO CLIENTE
            fgets(client[i].nome, 22, stdin);
            fflush(stdin);

            printf("%d -> Digite o telefone >  ", i+1); // TELEFONE DE CONTATO DO CLIENTE
            fgets(client[i].fone, 30, stdin);
            fflush(stdin);

            printf("%d -> Digite o seu endereço > ", i+1); // ENDEREÇO DO CLIENTE
            fgets(client[i].endereco, 60, stdin);
            fflush(stdin);

            printf("\n\nConfira seus dados...\n");
            printf("Código do Cliente > %d\n", client[i].cod_cliente);
            printf("Nome > %s\n", client[i].nome);
            printf("Telefone > %s\n", client[i].fone);
            printf("Endereço > %s\n", client[i].endereco);
            count++; // Contador de Clientes

            printf("Deseja continuar: S/N? > ");
            scanf("%c", &resp_usr);
            resp_usr = toupper(resp_usr);
            fflush(stdin);

            if(resp_usr == 'N')
            {
                break;
            }

        }
        system("cls");
    }

}

void cadastro_doc() //  ao cadastrar um documento, se a data de pagamento for maior que a data de vencimento, calcular o campo ‘juros’ do registro documentos (5% sobre o valor original do documento).
{
    
    int codigo, achou, achou2, achou3, resp1;
    char resp_usr, resp_usr2;
    float juros;

    printf("Limite de cadastro > 30 documentos...\n\n");
    if(count2 > 30)
    {
        printf("O cadastro de documentos está cheio...\n");
    }
    if(count == 0)
    {
        system("cls");
        printf("Não há cadastros em nosso banco de dados...\n");
        Sleep(2000);
        system("cls");
    }
    else 
    {
        do
        {
            resp1 = 0;
            printf("******   CADASTRO DOCUMENTOS   ******\n");
            printf("*************************************\n\n");
            do
            {
                achou = 0; 
                printf("Digite o código do cliente > ");
                scanf("%d", &codigo);
                fflush(stdin);


                for(int i=0 ; i<15; i++)
                {
                    if (codigo == client[i].cod_cliente)
                    {
                        achou = 1; 
                        achou2 = i;
                    }
                }
                if(codigo == 0 || achou == 0)
                {
                    printf("O código informado não consta em nosso sistema.... Tente novamente...\n");
                    Sleep(1000);
                }

            } while (achou != 1 || codigo == 0);

            printf("Verifique seus dados\n\n");
            printf("Código do Cliente > %d\n", client[achou2].cod_cliente);
            printf("Nome > %s\n", client[achou2].nome);
            printf("Telefone > %s\n", client[achou2].fone);
            printf("Endereço > %s\n", client[achou2].endereco);
            system("pause");
            system("cls");
            fflush(stdin);

            for(int j=count2; j<30; j++) // CADASTRO DE DOCUMENTOS
            {
                printf("Cliente --> %d\n", client[achou2].cod_cliente);
                doc[j].cod_cliente = client[achou2].cod_cliente;
                do
                {
                    printf("Informe o número do documento: ");
                    scanf("%d", &doc[j].num_doc); // 12 13
                    achou3 = 0; // 0 - Documento não encontrado
                    fflush(stdin);

                    for(int k=0; k<count2; k++)
                    {
                        if(j != k && doc[k].num_doc == doc[j].num_doc)
                        {
                            achou3 = 1; // 1 - Documento encontrado com o mesmo código
                        }
                    }
                    if(achou3 == 1)
                    {
                        printf("Número do documento já existe em nosso sistema...\n");

                    }
                } while (achou3 == 1);

                printf("Doc %d -> Digite a data de pagamento: ", doc[j].num_doc);
                scanf("%d %d %d", &doc[j].dia_pag, &doc[j].mes_pag, &doc[j].ano_pag);
                fflush(stdin);

                printf("Doc %d -> Digite a data de vencimento: ", doc[j].num_doc);
                scanf("%d %d %d", &doc[j].dia_ven, &doc[j].mes_ven, &doc[j].ano_ven);
                fflush(stdin);

                printf("Doc %d -> Digite o valor do documento (R$): ", doc[j].num_doc);
                scanf("%f", &doc[j].valor);
                fflush(stdin);

                if(doc[j].ano_pag > doc[j].ano_ven) // Verificando ser o usário irá pagar os juros
                {
                    juros = 0.05 * doc[j].valor;
                }
                else
                {
                    if (doc[j].ano_pag == doc[j].ano_ven)
                    {
                        if(doc[j].mes_pag > doc[j].mes_ven)
                        {
                            juros = 0.05 * doc[j].valor;
                            doc[j].juros = juros;
                        }
                        else
                        {
                            if(doc[j].mes_pag == doc[j].mes_ven)
                            {
                                if(doc[j].dia_pag > doc[j].dia_ven)
                                {   
                                    juros = 0.05 * doc[j].valor;
                                    doc[j].juros = juros;
                                }
                                else
                                {
                                    juros = 0;
                                    doc[j].juros = juros;
                                }
                            }
                        }
                    }
                    else
                    {
                        juros = 0;
                    }
                }

                if(juros > 0)
                {
                    printf("Você irá pagar R$ %.2f de juros.\n", juros);
                }
                count2 ++;

                printf("\nDocumentos cadastrados\n\n");
                for(int i=0; i<count2; i++)
                {
                    printf("Docuemento: %d\n", doc[i].num_doc);
                }
                printf("Deseja inserir mais documentos S/N?: ");
                scanf("%c", &resp_usr);
                resp_usr = toupper(resp_usr);
                fflush(stdin);

                if(resp_usr == 'N')
                {
                    break;
                }
            }

            printf("Deseja inserir novos clientes S/N?: ");
            scanf("%c", &resp_usr2);
            resp_usr2 = toupper(resp_usr2);

            if(resp_usr2 == 'N')
            {
                resp1 = 1;
            }
            system("cls");
        } while (resp1 == 0);
        system("cls");
    }

}

void excluir_clientes() //  um cliente só poderá ser excluído se não existir nenhum documento associado a ele.
{

    int cod_usr, achou, achou2;

    printf(">>>> EXCLUIR CLIENTE <<<<<\n");
    printf("-----------------------------\n");
    printf("Digite o código do cliente: ");
    scanf("%d", &cod_usr);
    achou = 0; // Encontrou um documento associado a ele
    achou2 = 0; // Encontrou o código do cliente
    for(int i=0; i<count; i++)
    {
        if(cod_usr == client[i].cod_cliente)
        {
            achou2 = 1; // Código do cliente encontrado
            if(doc[i].num_doc == doc[i+1].num_doc)
            {
                achou = 1; // Não localizou documentos associados a este cliente
                count --;
                client[i].cod_cliente = client[i+1].cod_cliente;
                strcpy(client[i].endereco, client[i+1].endereco);
                strcpy(client[i].fone, client[i+1].fone);
                strcpy(client[i].nome, client[i+1].nome);
            }
        }
    }
    if(achou2 == 1)
    {
        printf("Código do cliente: #%d\n", cod_usr);
        if(achou == 1) // Não encontrou documentos associados a este cliente localizado
        {
            printf("Não há documentos associados a este cliente...\n");
            Sleep(2000);
            system("cls");
            printf("Conta a ser excluida...\n");
            Sleep(2000);
            system("cls");
        }
        else // Encontrou documentos associados a este cliente...
        {
            printf("Não é possível excluir o cliente... Há documentos associados a ele...\n\n");
            Sleep(2000);
            system("cls");
        }
    }
    else 
    {
        system("cls");
        printf("Código não encontrado..\n");
        Sleep(2000);
        system("cls");
    }
    
}

void excluir_docs1() // por meio de seu número. Caso o documento não exista, o programa deverá mostrar a mensagem Documento não encontrado.
{
    int num_doc_usr, achou;

    printf(">>>>> EXCLUIR DOCUMENTOS INDIVIDUAIS <<<<<\n");
    printf("******************************************\n");

    printf("Digite o número de seu documento: ");
    scanf("%d", &num_doc_usr);
    if(count2 == 0) // Se não tiver documentos cadastrados 
    {
        printf("Nosso sistema não encontrou documentos em nosso banco de dados...\n");
        Sleep(2000);
        system("cls");
    }
    else
    {
        achou = 0; // Documento não encontrado
        for(int i=0; i<count2; i++) // Count2 -> Quantidade de documentos cadastrados
        {
            if(num_doc_usr == doc[i].num_doc)
            {
                achou = 1; // Documento Encontrado
                doc[i].num_doc = doc[i+1].num_doc;
                doc[i].cod_cliente = doc[i+1].cod_cliente;
                doc[i].dia_pag = doc[i+1].dia_pag;
                doc[i].mes_pag = doc[i+1].mes_pag;
                doc[i].ano_pag = doc[i+1].ano_pag;
                doc[i].dia_ven = doc[i+1].dia_ven;
                doc[i].mes_ven = doc[i+1].mes_ven;
                doc[i].ano_ven = doc[i+1].ano_ven;
                doc[i].valor = doc[i+1].valor;
                doc[i].juros = doc[i+1].juros;
                count2 --;
            }
        }

        if(achou == 1)
        {
            printf("Docuemnto localizado...\n");
            Sleep(2000);
            printf("Aguarde...\n");
            Sleep(2000);
            system("cls");
            printf("Documento excluído com sucesso...\n");
            Sleep(2000);
            system("cls");

        }
        else 
        {
            printf("Documento não encontrado...\n");
            Sleep(2000);
            system("cls");
        }
    }
}

void excluir_docs2() //  o programa deverá informar o código do cliente e excluir todos os seus documentos. Caso o cliente não exista, deverá mostrar a mensagem Cliente não encontrado.
{
    int cod_cliente_usr, achou, achou2;
    char nome_cli[22], fone_cli[30], end_cli[60];

    printf(">>>>>> EXCLUIR DOCUMENTOS POR CLIENTE <<<<<<\n");
    printf("********************************************\n");

    printf("Digite o código do cliente: ");
    scanf("%d", &cod_cliente_usr);

    achou = 0; // Cliente não encontrado...
    for(int i=0; i<count; i++)
    {
        if(cod_cliente_usr == client[i].cod_cliente)
        {
            achou = 1; // Cliente Encontrado...
            strcpy(nome_cli, client[i].nome);
            strcpy(fone_cli, client[i].fone);
            strcpy(end_cli, client[i].endereco);
        }
    }
    if(achou == 1)
    {
        printf("Cliente --> %d\n", cod_cliente_usr);
        printf("Nome: %s", nome_cli);
        printf("Telefone: %s", fone_cli);
        printf("Endereço: %s",end_cli);
        system("pause");
        achou2 = 0;
        for(int i=0; i<count2; i++)
        {
            if(cod_cliente_usr == doc[i].cod_cliente)
            {
                achou2 = 1;
                doc[i].num_doc = doc[i+1].num_doc;
                doc[i].cod_cliente = doc[i+1].cod_cliente;
                doc[i].dia_pag = doc[i+1].dia_pag;
                doc[i].mes_pag = doc[i+1].mes_pag;
                doc[i].ano_pag = doc[i+1].ano_pag;
                doc[i].dia_ven = doc[i+1].dia_ven;
                doc[i].mes_ven = doc[i+1].mes_ven;
                doc[i].ano_ven = doc[i+1].ano_ven;
                doc[i].valor = doc[i+1].valor;
                doc[i].juros = doc[i+1].juros;
                count2 --;
            }
        }
        if(achou2 == 1)
        {
            system("cls");
            printf("Documentos excluidos com sucesso...\n");
            Sleep(2000);
            system("cls");
        }
        else
        {
            Sleep(2000);
            system("cls");
            printf("Documento não localizado...\n");
            Sleep(2000);
            system("cls");
        }
    }
    else
    {
        system("cls");
        printf("Cliente não encontrado...\n");
        Sleep(2000);
        system("cls");
    }

}

void excluir_docs3() // o programa deverá informar a data inicial e a data final e excluir todos os documentos que possuam data de vencimento nesse período.
{
    int dia_ini, mes_ini, ano_ini, dia_final, mes_final, ano_final, achou;

    printf(">>> EXCLUIR DOCUMENTOS POR PERIODO <<<\n");
    printf("**************************************\n");

    printf("Digite a data inicial: ");
    scanf("%d %d %d", &dia_ini, &mes_ini, &ano_ini);

    printf("Digite a data final: ");
    scanf("%d %d %d", &dia_final, &mes_final, &ano_final);
    achou = 0;
    for(int i=0; i<count2; i++)
    {
        if(doc[i].ano_ven < ano_final && doc[i].ano_ven > ano_ini)
        {
            achou = 1;
        }
        else 
        {
            if(doc[i].ano_ven == ano_ini && doc[i].ano_ven == ano_final)
            {
                if(doc[i].mes_ven > mes_ini && doc[i].mes_ven < mes_final)
                {
                    achou = 1;
                }
                else
                {
                    if(doc[i].mes_ven == mes_ini && doc[i].mes_ven == mes_final)
                    {
                        if(doc[i].dia_ven > dia_ini && doc[i].dia_ven < dia_final)
                        {
                            achou = 1;
                        }
                    }
                }
            }
        }
    }

    if(achou == 1)
    {
        for(int i=0; i<count2; i++)
        {
            doc[i].num_doc = doc[i+1].num_doc;
            doc[i].cod_cliente = doc[i+1].cod_cliente;
            doc[i].dia_pag = doc[i+1].dia_pag;
            doc[i].mes_pag = doc[i+1].mes_pag;
            doc[i].ano_pag = doc[i+1].ano_pag;
            doc[i].dia_ven = doc[i+1].dia_ven;
            doc[i].mes_ven = doc[i+1].mes_ven;
            doc[i].ano_ven = doc[i+1].ano_ven;
            doc[i].valor = doc[i+1].valor;
            doc[i].juros = doc[i+1].juros;
            count2 --;
        }
        system("cls");
        printf("Documento Excluido com sucesso...\n");
        Sleep(2000);
        system("cls");
    }
    else 
    {
        system("cls");
        printf("Não foi encontrado documentos em que a data de vencimento esteja neste período...\n");
        Sleep(2000);
        system("cls");
    }

}


void alterar_info() //só não pode ser alterado o código do cliente
{
    char nome_usr[22], tel_usr[30], end_usr[60];
    int op, cod_usr, achou;

    do
    {
        printf(">>>>  ALTERAR AS INFORNAÇÕES SOBRE OS CLIENTES  <<<<\n");
        printf("****************************************************\n");

        printf("[01] - Alterar o nome do cliente\n");
        printf("[02] - Alterar o número de telefone\n");
        printf("[03] - Alterar o endereço\n");
        printf("[04] - Sair\n ");
        printf("Escolha uma opção...  ");
        scanf("%d", &op);
        if(op != 4)
        {
            printf("Digite o código do cliente... ");
            scanf("%d", &cod_usr);
        }

        for(int i=0; i<count; i++) //Verificar dados
        {
            if(cod_usr == client[i].cod_cliente)
            {
                printf("Cliente: %d\n", client[i].cod_cliente);
                printf("Nome: %s", client[i].nome);
                printf("Telefone: %s", client[i].fone);
                printf("Endereço: %s", client[i].endereco);
                system("pause");
            }
        }

        if(op < 1 || op > 4)
        {
            system("cls");
            printf("Código inválido... Tente novamente\n");
            Sleep(1000);
            system("cls");
        }

        if(op == 1) // Alterar o nome do cliente
        {
            achou = 0;
            for(int i =0; i<count; i++)
            {
                if(cod_usr == client[i].cod_cliente)
                {
                    achou = 1;
                }
            }
            if(achou == 1)
            {
                system("cls");
                printf("Cliente localizado...\n");
                Sleep(1000);
                fflush(stdin);
                printf("Digite um nome para o cliente #%d: ", cod_usr);
                fgets(nome_usr, 22, stdin);
                fflush(stdin);

                for(int i=0; i<count; i++)
                {
                    if(cod_usr == client[i].cod_cliente)
                    {
                        strcpy(client[i].nome, nome_usr);
                    }
                }

            }
            else
            {
                system("cls");
                printf("Cliente não encontrado... Tente novamente...\n");
                Sleep(2000);
                system("cls");
            }
        }

        if(op == 2) // Alterar o número de telefone
        {
            achou = 0;
            for(int i =0; i<count; i++)
            {
                if(cod_usr == client[i].cod_cliente)
                {
                    achou = 1;
                }
            }
            if(achou == 1)
            {
                system("cls");
                printf("Cliente localizado...\n");
                Sleep(1000);
                fflush(stdin);
                printf("Digite o telefone para o cliente #%d: ", cod_usr);
                fgets(tel_usr, 30, stdin);
                fflush(stdin);

                for(int i=0; i<count; i++)
                {
                    if(cod_usr == client[i].cod_cliente)
                    {
                        strcpy(client[i].fone, tel_usr);
                    }
                }
                system("cls");
                printf("Dados alterados com sucesso...\n");
                Sleep(2000);
                system("cls");

            }
            else
            {
                system("cls");
                printf("Cliente não encontrado... Tente novamente...\n");
                Sleep(2000);
                system("cls");
            }


        }

        if (op == 3) // Alterar o endereço
        {
            achou = 0;
            for(int i =0; i<count; i++)
            {
                if(cod_usr == client[i].cod_cliente)
                {
                    achou = 1;
                }
            }
            if(achou == 1)
            {
                system("cls");
                printf("Cliente localizado...\n");
                Sleep(1000);
                fflush(stdin);
                printf("Digite um novo endereço para o cliente #%d: ", cod_usr);
                fgets(end_usr, 60, stdin);
                fflush(stdin);

                for(int i=0; i<count; i++)
                {
                    if(cod_usr == client[i].cod_cliente)
                    {
                        strcpy(client[i].endereco, end_usr);
                    }
                }
                system("cls");
                printf("Dados alterados com sucesso...\n");
                Sleep(2000);
                system("cls");

            }
            else
            {
                system("cls");
                printf("Cliente não encontrado... Tente novamente...\n");
                Sleep(2000);
                system("cls");
            }
        }

    } while (op != 4);

    if(op == 4)
    {
        system("cls");
        printf("Encerrando...");
        Sleep(1000);
        system("cls");
    }
    
}

void total_docs() // Mostrar o total de documentos de determinado cliente
{
    int cod_usr, achou, pos;

    printf(">>>>  MOSTRAR DOCUMENTOS  <<<<<\n");
    printf("*******************************\n");

    printf("Digite o código do cliente: ");
    scanf("%d", &cod_usr);

    achou = 0;
    for (int i=0; i<count; i++)
    {
        if(cod_usr == client[i].cod_cliente)
        {
            achou = 1;
            pos = i;
        }
    }
    if(achou == 1)
    {
        for(int j=0; j<count2; j++)
        {
            if(client[pos].cod_cliente == doc[j].cod_cliente)
            {
                printf("Documento: %d\n", doc[j].num_doc);
                printf("Data de pagamento: %d %d %d\n", doc[j].dia_pag, doc[j].mes_pag, doc[j].ano_pag);
                printf("Data do vencimento: %d %d %d\n", doc[j].dia_ven, doc[j].mes_ven, doc[j].ano_ven);
                printf("Pagamento: R$ %f", doc[j].valor);
            }
        }
        system("pause");
    }
    else
    {
        system("cls");
        printf("Cliente não encontrado em nosso banco de dados...\n");
        Sleep(2000);
        system("cls");
    }

}

int main()
{   
    // setlocale(LC_ALL, "Portuguese");
    int op;

    do
    {
        printf("************  MENU DE OPÇÕES  ************\n");
        printf(" [01] - Cadastrar Clientes...\n");
        printf(" [02] - Cadastrar Documentos...\n");
        printf(" [03] - Excluir Clientes...\n");
        printf(" [04] - Excluir documentos individuais...\n");
        printf(" [05] - Excluir documentos por clientes...\n");
        printf(" [06] - Excluir documentos por período...\n");
        printf(" [07] - Alterar informações sobre os clientes...\n");
        printf(" [08] - Mostrar o total de documentos de determinado cliente...\n");
        printf(" [09] - Sair...\n");
        printf("Escolha uma opção...  ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            cadastrar_client();
            break;
        case 2:
            system("cls");
            cadastro_doc();
            break;
        case 3:
            system("cls");
            excluir_clientes();
            break;
        case 4:
            system("cls");
            excluir_docs1();
            break;
        case 5:
            system("cls");
            excluir_docs2();
            break;
        case 6:
            system("cls");
            excluir_docs3();
            break;
        case 7:
            system("cls");
            alterar_info();  
            break;
        case 8:
            system("cls");
            total_docs();
            break;
        case 9:
            break;

        default:
            system("cls");
            printf("Código inválido.... tente novamente\n");
            system("pause");
            break;
        }

    } while (op != 9);

    return 0;
}