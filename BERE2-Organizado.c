//Inclusao de Bibliotecas
//Inclusao de Biblioteca adequada ao Projeto Mensal
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos das funções
void menuPrincipal(void);
void menuCategoria(int categoria);
void menuPagamento(void);
void PagamentoDinheiro(void);
void PagamentoCartao(void);
void abrirCaixa(float valorInicial);
void fecharCaixa(void);
float calcularDesconto(float total);

// Variáveis para controlar os totais
float TotalCarrinho = 0;
float Totalcategoria[3] = {0, 0, 0};
int caixaAberto = 0;

// Valor inicial do caixa
float valorInicialDoCaixa = 0;

// Matriz de produtos e preços
char produtos[3][7][25] = {
    {"Detergente", "Sabao em Po (1kg)", "Esponja", "Amaciante(1Lt)", "Bucha de Pia (kit com 3)", "Desinfetante (1lt)", "Sabao em Barra"},
    {"Cafe", "Leite (cx)", "Arroz (1kg)", "Feijao Preto (1kg)", "Acucar", "Sal (1kg)", "Farinha de Trigo (1kg)"},
    {"Pao de forma", "Pao Integral", "Pao Frances (un)", "Sonho", "Biscoito", "Pao Doce (un)", "Salgado (un)"}};

float precos[3][7] = {
    {1.99, 8.99, 0, 15.00, 4.99, 7.99, 1.00},
    {19.99, 5.90, 4.50, 8.00, 5.00, 2.00, 5.00},
    {9.50, 0, 1.90, 8.50, 12.50, 2.50, 17.50}};

// Função principal
int main(void)
{
    abrirCaixa(50); // Abre o caixa com um valor inicial de R$200
    menuPrincipal(); // Inicializa o programa com o menu principal
    fecharCaixa();   // Fecha o caixa ao sair do programa
    return 0;
}

// Função para abrir o caixa com um valor inicial
void abrirCaixa(float valorInicial)
{
    valorInicialDoCaixa = valorInicial;
    caixaAberto = 1;
    TotalCarrinho = 0; // Zera o total do carrinho ao abrir o caixa
    printf("\n|===========================|==========================|\n");
    printf("\n| Caixa aberto.             | Valor inicial: R$%.2f   |\n", valorInicialDoCaixa);
}

// Função para fechar o caixa
void fecharCaixa(void)
{
    caixaAberto = 0;
    printf("\n |====================================|\n");
    printf("\n |       Fechando o caixa...          |\n");
    printf("\n |====================================|\n");
    printf("\n |Total de vendas do dia: R$%.2f      |\n", TotalCarrinho - valorInicialDoCaixa);
    printf("\n |Total de dinheiro no caixa: R$%.2f  |\n", TotalCarrinho);
    printf("\n |Caixa fechado. Até logo!            |\n");
}

// Função para exibir o menu principal
void menuPrincipal(void)
{
    if (!caixaAberto)
    {
        printf("\n|============================================|\n");
        printf("\n|O caixa está fechado. Não é possível operar.|\n");
        printf("\n|============================================|\n");

        return;
    }

    int opcao;
    do
    {
        // Exibe o cabeçalho e as opções do menu principal
        printf("\n|===========================|==========================|\n");
        printf("\n|   Mercearia da Dona Bere  | Total no carrinho: R$%.2f|\n", TotalCarrinho);
        printf("\n|   1. Material de Limpeza  |                          |\n");
        printf("\n|   2. Venda de Alimentos   |                          |\n");
        printf("\n|   3. Padaria              |                          |\n");
        printf("\n|   4. Pagamento            |                          |\n");
        printf("\n|   5. Sair                 |                          |\n");
        printf("\n|===========================|==========================|\n");
        scanf("%d", &opcao); // Lê a escolha do usuário

        // Executa a opção escolhida
        switch (opcao)
        {
        case 1:
            menuCategoria(1);
            break;
        case 2:
            menuCategoria(2);
            break;
        case 3:
            menuCategoria(3);
            break;
        case 4:
            menuPagamento();
            break;
        case 5:
            printf("\n |---------------------|\n");
            printf("\n |Fechando o caixa...  |\n");
            printf("\n |---------------------|\n");
            break;
        default:
            printf("\n  Opção inválida! \n");
            break;
        }
    } while (opcao != 5); // Repete o loop até o usuário escolher sair
}

// Função para exibir o menu de uma categoria específica
void menuCategoria(int categoria)
{
    if (!caixaAberto)
    {
        printf("\n|----------------------------------------------|\n");
        printf("\n| O caixa está fechado. Não é possível operar. |\n");
        printf("\n|----------------------------------------------|\n");

        return;
    }

    int opcao;
    do
    {
        switch (categoria)
        {
        case 1:
            // Exibe os produtos e preços da categoria de Material de Limpeza

       printf("\n|======================|===========================|\n");
       printf("\n| Material de Limpeza  | Total na Categoria: R$%.2f|\n", Totalcategoria[0]);
       printf("\n| ID      |   Preco    | Produto      |\n");
            for (int i = 0; i < 7; i++)
            {
            if (strcmp(produtos[categoria - 1][i], "Esponja") == 0 && precos[categoria - 1][i] == 0)
               {
       printf("\n|--------------------------------------------------|\n");
       printf("\n| %d. | Produto Esgotado| %s          |\n", i + 1, produtos[categoria - 1][i]);
                }
                else
                {
       printf("\n|--------------------------------------------------|\n");
       printf("\n|%d. |      R$%.2f      | %s          |\n", i + 1, precos[categoria - 1][i], produtos[categoria - 1][i]);
                }
            }
            break;
        case 2:
            // Exibe os produtos e preços da categoria de Venda de Alimentos
      printf("\n|---------------------------------------------------|\n");
      printf("\n| Venda de Alimentos    |Total na Categoria: R$%.2f |\n", Totalcategoria[1]);
      printf("\n|   ID    |    Preco    |  Produto                  |\n");
            for (int i = 0; i < 7; i++)
            {
      printf("\n|   %d.   |   R$%.2f    | %s                        |\n", i + 1, precos[1][i], produtos[1][i]);
            }
            break;
        case 3:
            // Exibe os produtos e preços da categoria de Padaria
      printf("\n|---------------------- |---------------------------|\n");
      printf("\n|       Padaria         | Total na Categoria: R$%.2f|\n", Totalcategoria[2]);
      printf("\n|  ID     |   Preço     |  Produto                  |\n");
            for (int i = 0; i < 7; i++)
            {
            if (strcmp(produtos[categoria - 1][i], "Pao Integral") == 0 && precos[categoria - 1][i] == 0)
                {
     printf("\n|---------------------------------------------------|\n");
     printf("\n|  %d.     | Sem Estoque | %s                       |\n", i + 1, produtos[categoria - 1][i]);
                }
                else
                {
     printf("\n|---------------------------------------------------|\n");
     printf("\n|     %d.  |   R$%.2f    | %s                       |\n", i + 1, precos[categoria - 1][i], produtos[categoria - 1][i]);
                }
            }
            break;
        }
     printf("\n|---------------------------------------------------|\n");
     printf("\n| 8.  Voltar ao Menu Principal                      |\n");
     printf("\n|Digite a opcao desejada:                           |\n");
        scanf("%d", &opcao); // Processa a escolha do usuário
        if (opcao < 5)//talvez alterar 5 pelo 8
        {
            if (strcmp(produtos[categoria - 1][opcao - 1], "Esponja") == 0 && precos[categoria - 1][opcao - 1] == 0)
            {
                printf("Produto esgotado!\n");
            }
            else if (strcmp(produtos[categoria - 1][opcao - 1], "Pao Integral") == 0 && precos[categoria - 1][opcao - 1] == 0)
            {
                printf("Produto sem estoque!\n");
            }
            else
            {
                int quantidade;
                printf("Produto: %s\n", produtos[categoria - 1][opcao - 1]);
                printf("Preco: R$%.2f\n", precos[categoria - 1][opcao - 1]);
                printf("Quanto desse produto?\n");
                scanf("%d", &quantidade);
                Totalcategoria[categoria - 1] += precos[categoria - 1][opcao - 1] * quantidade;
                TotalCarrinho += precos[categoria - 1][opcao - 1] * quantidade;
                printf("Total no carrinho: R$%.2f\n", TotalCarrinho);
            }
        }
        else if (opcao == 5)
        {
            break;
        }
        else
        {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 8); // Repete o loop até o usuário escolher voltar
}

// Função para exibir o menu de pagamento
void menuPagamento(void)
{
    if (!caixaAberto)
    {
        printf("O caixa está fechado. Não é possível operar.\n");
        return;
    }

    int opcao;
    do
    {
        // Exibe o total do carrinho e os totais por categoria
        printf("\n Total no Carrinho: R$%.2f\n", TotalCarrinho);
        printf("Total por Categoria\n");
        printf("   | Material de Limpeza: R$%.2f\n", Totalcategoria[0]);
        printf("   | Venda de Alimentos: R$%.2f\n", Totalcategoria[1]);
        printf("   | Padaria: R$%.2f\n", Totalcategoria[2]);
        printf("Qual sera a forma de Pagamento?\n");
        printf("1. | Dinheiro\n");
        printf("2. | Cartao\n");
        printf("3. | Voltar\n");
        scanf("%d", &opcao);

        // Processa a escolha do usuário
        switch (opcao)
        {
        case 1:
            PagamentoDinheiro();
            break;
        case 2:
            PagamentoCartao();
            break;
        case 3:
            printf("Voltando ao Menu Principal...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 3); // Repete o loop até o usuário escolher voltar
}

// Função para pagamento em dinheiro
void PagamentoDinheiro(void)
{
    float valor;
    printf("Digite o valor recebido: ");
    scanf("%f", &valor);
    float desconto = calcularDesconto(TotalCarrinho);
    printf("Desconto: R$%.2f\n", desconto);
    printf("Total com desconto: R$%.2f\n", TotalCarrinho - desconto);
    printf("Troco: R$%.2f\n", valor - (TotalCarrinho - desconto));
}

// Função para calcular o desconto
float calcularDesconto(float total)
{
    float desconto = 0;
    if (total <= 50)
    {
        desconto = total * 0.05; // 5% de desconto
    }
    else if (total > 50 && total < 100)
    {
        desconto = total * 0.10; // 10% de desconto
    }
    else
    {
        desconto = total * 0.18; // 18% de desconto
    }
    return desconto;
}

// Função para pagamento com cartão
void PagamentoCartao(void)
{
    int opcao;
    printf("Pagamento com cartao\n");
    printf("Total: R$%.2f\n", TotalCarrinho);
    printf("O cartao foi aprovado na maquininha?\n");
    printf("1. Sim  2. Nao\n");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        printf("Pagamento efetuado com sucesso!\n");
    }
    else
    {
        printf("Pagamento nao aprovado!\n");
        printf("Deseja tentar novamente ou cancelar a operacao?\n");
        printf("1. Tentar novamente  2. Cancelar\n");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            PagamentoCartao();
        }
    }
}
