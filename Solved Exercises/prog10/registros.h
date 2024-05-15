#ifndef REGISTROS_H
#define REGISTROS_H
/* ESTRUTURAS E VARIÁVEIS GLOBAIS */

struct filial // Registro das filiais
{
    int num_filial; // O número da filial a ser cadastrar, não pode haver mais de duas filiais com o mesmo número
    char nome_filial[30]; // O nome da filial a ser cadastrada
};

struct Funcionario // Registro dos funcionários
{
    int num_filial; // O número da filial a ser cadastrar, não pode haver mais de duas filiais com o mesmo número
    int cod_funcionario; // O código do funcionário a ser cadastrado, não pode existir dois funcionários com o mesmo número
    char nome_funcionario[30]; // O nome do funcionário a ser cadastrado
    char cargo[30]; // O cargo do funcionário 
    float salario; // O salário do funcionário
};


struct filial filial[4]; // Estrutura das filiais, é permitido o cadastro de 4 filiais somente
struct Funcionario func[20] = {0}; // Os funcionários a serem cadastrados -> 4 Vendedores e 1 gerente por filial
/* Se cada filial deve possuir 5 funcionários logo serão 20 funcionários no total */

int count_func = 0; // contabiliza o número de funcionário já cadastrados 
int count_fil = 0; // Contabiliza o número de filiais cadastradas
int count_vend = 0; // Contabiliza o número de vendedores cadastrados
#endif