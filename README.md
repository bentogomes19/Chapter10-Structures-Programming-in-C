# Chapter 10 - Structures Programming Logic in C 💻

.. Exercises from Fundamentals of Computer Programming [PT-BR] | C/C++ PASCAL JAVA

## Exercises [PT-BR]

### Prog 01

Faça um programa que realize o cadastro de contas bancárias com as seguintes informações: número
da conta, nome do cliente e saldo. O banco permitirá o cadastramento de apenas 15 contas e não poderá haver mais que uma conta com o mesmo número. Crie o menu de opções a seguir.
Menu de opções:
1. Cadastrar contas.
2. Visualizar todas as contas de determinado cliente.
3. Excluir a conta com menor saldo (supondo a não existência de saldos iguais).
4. sair.


<a href="/Solved Exercises/prog01/prog01.c">Prog01.c</a>

### Prog 02

Uma empresa prestadora de serviços armazena informações sobre os serviços prestados. sabe-se que a 
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
prestado.

Cada linha representa um dia do mês. Dessa maneira, considere a matriz com dimensão 30 × 3.
solicite o dia em que o serviço foi prestado e as demais informações.
lembre-se de que a empresa só pode prestar os serviços que já tenham sido cadastrados no vetor de
tipo de serviços.

Caso o usuário digite um código de tipo de serviço inválido, o programa deverá mostrar uma mensagem de erro.
Quando o usuário tentar cadastrar mais de três serviços prestados em um mesmo dia, também deverá
mostrar uma mensagem de erro.

Para a opção 3: o programa deverá receber o dia que se deseja consultar e mostrar os respectivos serviços prestados.

Para a opção 4: o programa deverá receber o valor mínimo e o valor máximo e mostrar os serviços
prestados que estiverem nesse intervalo.

Para a opção 5: o programa deverá mostrar todos os serviços prestados, conforme o exemplo a seguir.

DIA 01
        No do serviço  Valor do serviço  Código do serviço     Descrição        Código do cliente
                100     R$ 200,00               1               Pintura                 1
                150     R$ 100,00               3               Faxina                  5
DIA 02
        No do serviço  Valor do serviço  Código do serviço      Descrição       Código do cliente
                301     R$ 600,00               4               Reforma em geral        3
                280     R$ 352,00               1               Pintura                 2

<a href="/Solved Exercises/prog02/prog02.c">Prog02.c</a>

### Prog 03

Faça um programa que utilize os registros a seguir.
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
deverá ficar livre para uma nova inclusão.

<a href="/Solved Exercises/prog03/prog03.c">Prog03.c</a>


### Prog 04

Faça um programa que efetue reserva de passagens aéreas de determinada companhia. O programa
deverá ler os números dos aviões e o número de lugares disponíveis em cada um. Utilize um vetor de
quatro posições, no qual cada posição representa um avião, e outro vetor também de quatro posições
para armazenar os lugares disponíveis.
O programa deverá mostrar o seguinte menu de opções:
                1. Cadastrar o número dos aviões.
                2. Cadastrar o número de lugares disponíveis em cada avião.
                3. Reservar passagem.
                4. Consultar por avião.
                5. Consultar por passageiro.
                6. Finalizar.

Imagine que poderão ser registradas até 60 reservas e que cada uma deverá possuir o número do avião
e o nome do passageiro.
Para realizar a opção 1, deverá ser solicitado ao usuário o número dos quatro aviões disponíveis.

Para realizar a opção 2, deverá ser solicitado ao usuário o número de lugares disponíveis em cada avião
cadastrado na opção 1.

Para realizar a opção 3, deverá ser verificado se o número do avião digitado é válido. Posteriormente,
checar se, no avião escolhido, ainda existe lugar disponível. Caso exista, o programa deverá diminuir o
total de vagas e mostrar a mensagem Reserva confirmada. Caso contrário, deverá mostrar a mensagem
Voo lotado. Observe que não podem ser feitas mais de 60 reservas.

Para realizar a opção 4, deverá ser solicitado o número do avião desejado e, posteriormente, deverão
ser exibidas todas as suas reservas.

Para realizar a opção 5, deverá ser solicitado o nome do passageiro e, posteriormente, deverão ser exibidas todas as reservas feitas em seu nome.

A opção 6 encerra o programa.

<a href="/Solved Exercises/prog04/prog04.c">Prog04.c</a>

### Prog 05

Uma empresa possui 18 funcionários, sobre os quais se tem estas informações: nome, número de horas
trabalhadas no mês, turno de trabalho (pode ser M — matutino; V — vespertino; ou N — noturno),
categoria (pode ser O — operário; ou G — gerente) e valor da hora trabalhada. sabendo-se que essa
empresa deseja informatizar sua folha de pagamento, faça um programa que leia o nome, o número de
horas trabalhadas no mês, o turno e a categoria dos funcionários, não permitindo que sejam informados turnos e categorias inexistentes. O programa deverá calcular o valor da hora trabalhada, conforme
a tabela a seguir, adotando o valor de R$ 550,00 para o salário-mínimo.

        Categoria         Turno                 Valor da hora trabalhada
        G                   N                      18% do salário-mínimo
        G                 M ou V                   15% do salário-mínimo
        O                   N                       13% do salário-mínimo
        O                 M ou V                    10% do salário-mínimo

O programa deverá calcular o salário inicial dos funcionários, com base no valor da hora e no número
de horas trabalhadas. Todos recebem um auxílio-alimentação, de acordo com o seu salário inicial, conforme a tabela a seguir.

        Salário inicial                 Auxílio-alimentação
         R$ 550,00                     20% do salário inicial
         R$ 550,00 e R$ 800,00         15% do salário inicial
         R$ 800,00                     5% do salário inicial

O programa deverá mostrar o nome, o número de horas trabalhadas, o valor da hora trabalhada, o
salário inicial, o auxílio-alimentação e o salário final (salário inicial + auxílio-alimentação) de todos os funcionários. Ele deverá apresentar o seguinte menu de opções:
        1. Cadastrar funcionários.
        2. Mostrar folha de pagamento.
        3. sair...

<a href="/Solved Exercises/prog05/prog05.c">Prog05.c</a>

### Prog 06

Uma empresa contratou 15 funcionários temporários. De acordo com o valor das vendas mensais, os
funcionários ganham pontos que determinarão seus salários ao fim de cada mês. sabe-se que eles trabalharão nos meses de novembro de 2011 a janeiro de 2012. Faça um programa que:
a) Cadastre os nomes dos funcionários e suas respectivas vendas mensais.

b) Calcule e mostre a pontuação geral de cada funcionário nos três meses. sabe-se que R$ 100,00 equivalem a
1 ponto.

c) Calcule e mostre a pontuação geral de todos os funcionários a cada mês.

d) Determine e mostre a maior pontuação atingida nos três meses, mostrando o nome do funcionário. Deverão
ser desconsiderados empates.

e) Determine e mostre o valor total vendido.

<a href="/Solved Exercises/prog06/prog06.c">Prog06.c</a>


### Prog 07


Crie um programa para ler o código, o sexo (M — masculino; F — feminino) e o número de horas-
-aula ministradas pelos professores de uma escola durante um mês. sabe-se que um professor ganha
R$ 60,50 hora-aula e que a escola possui dez professores. Após a leitura, o programa deverá mostrar:

a) Uma listagem contendo o código, o salário bruto, o desconto e o salário líquido de todos o professores.

b) A média aritmética dos salários brutos dos professores do sexo masculino.

c) A média aritmética dos salários brutos dos professores do sexo feminino.

Os descontos devem ser assim calculados:

        Sexo            Até 70 horas/aula ao mês            Mais que 70 horas/aula ao mês
        Masculino               10%                                     8%
        Feminino                7%                                      5% 

<a href="/Solved Exercises/prog07/prog07.c">Prog07.c</a>

### Prog 08

Veja os campos de alguns registros:
Professor (número de registro, nome, cod_título, total h/a semanal)
Título (cod_título, descrição, valor hora/aula)
Elabore um programa que:

■■ Crie uma rotina para cadastrar os títulos. sabe-se que nessa escola existem cinco títulos.

■■ Crie uma rotina para cadastrar os professores. sabe-se que nessa escola trabalham 14 professores,
e cada um deve estar associado a um título previamente cadastrado.


■■ Crie uma rotina para mostrar a relação de professores, conforme o layout a seguir.

        No do registro      Nome                Título (descrição)      Valor hora/ aula        Total H/A       Total geral
        111                 João da Silva       Mestre                      R$ 60,50               10          R$ 605,00
        113                 Maria Oliveira      Especialista                R$ 40,00               8           R$ 320,00

<a href="/Solved Exercises/prog08/prog08.c">Prog08.c</a>