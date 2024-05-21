# Chapter 10 - Structures Programming Logic in C 💻

.. Exercises from Fundamentals of Computer Programming [PT-BR] | C/C++ PASCAL JAVA

## Exercises [PT-BR]

### Prog 01
<hr >

Faça um programa que realize o cadastro de contas bancárias com as seguintes informações: número
da conta, nome do cliente e saldo. O banco permitirá o cadastramento de apenas 15 contas e não poderá haver mais que uma conta com o mesmo número. Crie o menu de opções a seguir.
Menu de opções:
1. Cadastrar contas.
2. Visualizar todas as contas de determinado cliente.
3. Excluir a conta com menor saldo (supondo a não existência de saldos iguais).
4. sair.


<a href="/Solved Exercises/prog01/prog01.c">Prog01.c</a>

### Prog 02
<hr >

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
<hr >

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
<hr >

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
<hr >

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
<hr >

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
<hr >

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
<hr >

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

### Prog 09
<hr >

9. Crie um pequeno sistema para controle automatizado de estoque com os seguintes registros:

        Clientes          Notas               Itens_notas                Produtos
        Cod_cliente     Numero_NF               Numero_NF               Cod_produto
        Endereco        Cod_cliente             Cod_produto              Descricao
        Telefone        Total_geral             Quantidade                Unidade
                                                Preco_venda            Preco_unitario
                                                                       Qtdade_estoque


O sistema deverá conter os seguintes módulos: CADASTROs, MOVIMENTAÇÕES, CONsUlTAS,
além de uma opção para sAÍDA. 
 
 1. O módulo CADAsTROs deverá fazer a manutenção das informações sobre clientes e produtos (seis
produtos e três clientes):

a) Manutenção de ClIENTEs — inclusão, tomando cuidado para não cadastrar dois clientes com o mesmo
código; alteração, o único campo que não pode ser alterado é o código; exclusão, tomando cuidado para não
permitir a exclusão de clientes que possuam nota fiscal.

b) Manutenção de PRODUTOs — inclusão, tomando cuidado para não cadastrar dois produtos com o mesmo
código; alteração, o único campo que não pode ser alterado é o código; exclusão, tomando cuidado para não
permitir a exclusão de produtos pertencentes a alguma nota fiscal. 

2. O módulo MOVIMENTAÇÕEs deverá permitir a digitação de notas fiscais de saída, de acordo com as especificações a seguir, supondo que poderão ser gravadas até cinco notas fiscais contendo dois itens em cada uma: 

a) Não cadastrar duas notas com o mesmo número.

b) Uma nota só pode ser emitida a um cliente que já exista.

c) Todos os produtos da nota devem estar previamente cadastrados; caso contrário, emitir mensagem de erro.

d) Não cadastrar duas vezes um produto na mesma nota.

e) Quando um produto for confirmado, baixar sua quantidade em estoque e gravar um registro em ITENs_NOTAs.

3. O módulo CONsUlTAs deverá permitir as consultas descritas a seguir:

a) Todos os produtos com preços entre dois valores digitados pelo usuário.

b) Todas as notas e os itens da nota de um cliente escolhido pelo usuário.

c) Todas as notas e os itens da nota com total geral superior a um valor escolhido pelo usuário.

<a href="/Solved Exercises/prog09/prog09.c">Prog09.c</a>

### Prog 10
<hr>

10. Uma empresa do ramo de material esportivo deseja ter um controle automatizado dos funcionários
que trabalham em cada uma de suas filiais. sabe-se que essa empresa possui quatro filiais com quatro
vendedores e um gerente em cada uma delas. Todos devem ser cadastrados como funcionários.

Faça um programa que realize esse controle, com as seguintes rotinas:

a) Cadastrar filial, observando que não podem existir duas filiais com o mesmo número.

b) Cadastrar funcionário, observando que: 
    1) não podem existir dois funcionários com o mesmo número; 
    2) cada funcionário deve ser cadastrado em uma filial;
    3) cada filial pode ter apenas um gerente e no máximo quatro vendedores;

c) Criar uma consulta a todas as filiais, mostrando o nome do gerente e dos vendedores, o valor total gasto com
pagamento de salários por filial e o valor gasto com pagamento de salário geral.

<a href="/Solved Exercises/prog10/prog10.c">Prog10.c</a>

### Prog 11
<hr>

11. Crie um controle de matrícula anual de alunos em uma escola. sabe-se que nessa escola é permitida a
matrícula por disciplinas (o aluno monta seu horário). Esse controle deverá armazenar as informações
pertinentes apenas a um ano. A escola oferece, a cada ano, seis disciplinas; sabe-se que existem dez
alunos e que cada um pode matricular-se em, no máximo, três disciplinas a cada ano.

As informações devem estar estruturadas conforme os registros a seguir:
■■ Aluno (código do aluno, nome do aluno, série).

■■ Matrícula (código do aluno, código da disciplina, total de faltas, nota final).

■■ Disciplina (código da disciplina, descrição, carga horária).
O programa deverá seguir estas especificações:

■■ Cadastrar todas as disciplinas que poderão ser oferecidas no ano (não devem ser permitidas duas
disciplinas com o mesmo código).

■■ Cadastrar alunos (não devem ser permitidos dois alunos com o mesmo código e os valores válidos
para a série vão de 5 a 9).

■■ Realizar a matrícula do aluno (nesse momento, o aluno está apenas se inscrevendo na disciplina
que ainda não foi cursada. Dessa maneira, os campos ‘total de faltas’ e ‘nota final’ não deverão ser
preenchidos).

■■ lançamento dos resultados finais (a secretaria, ao final do ano letivo, informa o código do aluno
e o código da disciplina e preenche os campos ‘total de faltas’ e ‘nota final’ que estavam vazios).

■■ Criar uma consulta a todos os alunos reprovados nas disciplinas (a reprovação ocorrerá se a nota
for menor que 7 ou se o total de faltas ultrapassar 25% da carga horária da disciplina).

■■ Criar uma rotina que mostre o nome das disciplinas cursadas por determinado aluno, junto com o
total de faltas, a nota final e o resultado (aprovado ou reprovado).

<a href="/Solved Exercises/prog11/prog11.c">Prog11.c</a>

## Exercícios Propostos 


### Prog 12

<hr>

1. Uma empresa deseja controlar as vendas realizadas por seus vendedores a cada mês, durante um ano inteiro.
sabe-se que nessa empresa existem quatro vendedores.
É importante que esse controle seja automatizado, porque muitas consultas devem ser respondidas
imediatamente. O gerente necessita de um meio para cadastrar as vendas de todos os vendedores e,
depois, precisa ver um menu contendo as seguintes opções:

1. Cadastrar vendedor.

2. Cadastrar venda.

3. Consultar as vendas de um funcionário em determinado mês.

4. Consultar o total das vendas de determinado vendedor.

5. Mostrar o número do vendedor que mais vendeu em determinado mês.

6. Mostrar o número do mês com mais vendas.

7. Finalizar o programa.

Na opção 1: devem ser cadastrados vendedores, e não pode haver dois vendedores com o mesmo có-
digo.

Na opção 2: devem ser cadastradas vendas, informado o código do vendedor e o mês das vendas, mas
não podem existir duas vendas para o mesmo vendedor no mesmo mês.

Na opção 3: deve ser informado o número do vendedor e o número do mês que se deseja consultar,
para, então, descobrir e mostrar esse valor.

Na opção 4: deve ser informado o número do vendedor desejado, calculado e mostrado o total de suas
vendas.

Na opção 5: deve ser informado o número do mês que se deseja pesquisar, para então descobrir e mostrar o número do vendedor que mais vendeu nesse mês.

Na opção 6: deve ser descoberto e mostrado o mês com maior venda.

Na opção 7: o programa termina.

<a href="/Solved Exercises/prog12/prog12.c">Prog12.c</a>

### Prog 13
<hr>

2. A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre salário,
idade e número de filhos. Faça um programa que leia esses dados de 20 pessoas, calcule e mostre:

■■ a média de salário da população;

■■ a média do número de filhos;

■■ o maior salário;

■■ o percentual de mulheres com salário superior a R$ 1.000,00.

<a href="/Solved Exercises/prog13/prog13.c">Prog13.c</a>

### Prog 14
<hr>

3. Foi realizada uma pesquisa sobre algumas características físicas de 50 habitantes de certa região. De cada
habitante foram coletados os seguintes dados: sexo, altura, idade e cor dos olhos (A – azuis; V – verdes; ou
C – castanhos).
Faça um programa que leia esses dados, armazene-os em um registro do tipo vetor e determine:

■■ a média de idade das pessoas com olhos castanhos e altura superior a 1,60 m;

■■ a maior idade entre os habitantes;

■■ a quantidade de indivíduos do sexo feminino com idade entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 1,70 m;

■■ o percentual de homens.

<a href="/Solved Exercises/prog14/prog14.c">Prog14.c</a>
