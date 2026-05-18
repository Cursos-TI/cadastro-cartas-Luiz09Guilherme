/*
 * ==============================================================================
 *  SUPER TRUNFO DE PAÍSES - Nível Aventureiro
 *  Linguagem: C
 * ==============================================================================
 *
 *  Descrição:
 *      Programa que permite cadastrar duas cartas do jogo Super Trunfo,
 *      contendo informações sobre cidades. Os dados são lidos do teclado,
 *      armazenados em variáveis e exibidos na tela de forma organizada.
 *
 *      Além disso, calcula e exibe duas propriedades derivadas:
 *        - Densidade Populacional (hab/km²)
 *        - PIB per Capita (reais por habitante)
 *
 *  Conceitos aplicados:
 *      - Variáveis e tipos de dados (char, int, float, char[])
 *      - Operadores de atribuição (=)
 *      - Operadores aritméticos (+, /)
 *      - Conversão de tipos (cast)
 *      - Funções de entrada e saída (printf, scanf)
 *
 *  Estrutura de cada carta:
 *      - Estado:                char   (letra de 'A' a 'H')
 *      - Código da Carta:       char[] (letra do estado + número 01 a 04)
 *      - Nome da Cidade:        char[] (nome da cidade)
 *      - População:             int    (número de habitantes)
 *      - Área:                  float  (área em km²)
 *      - PIB:                   float  (Produto Interno Bruto)
 *      - Pontos Turísticos:     int    (quantidade de pontos turísticos)
 *      - Densidade Populacional:float  (hab/km²)  → CALCULADO
 *      - PIB per Capita:        float  (reais)    → CALCULADO
 *
 * ==============================================================================
 */

#include <stdio.h>

/* ==============================================================================
 *  CONSTANTES
 * ============================================================================== */

#define TAMANHO_CODIGO  4      // 3 caracteres + \0 (ex: "A01\0")
#define TAMANHO_NOME    100    // Tamanho máximo para o nome da cidade

/* ==============================================================================
 *  FUNÇÃO PRINCIPAL
 * ============================================================================== */

int main(void) {

    /*
     * ------------------------------------------------------------------
     *  VARIÁVEIS DA CARTA 1
     *
     *  Cada variável armazena uma informação diferente da carta.
     *  Usamos tipos adequados para cada tipo de dado:
     *    - char       : um único caractere (o estado)
     *    - char[]     : um array de caracteres para textos (string)
     *    - int        : números inteiros (população, pontos turísticos)
     *    - float      : números decimais (área, PIB)
     * ------------------------------------------------------------------
     */

    char estado1;                          // Letra do estado (A a H)
    char codigo1[TAMANHO_CODIGO];         // Código da carta (ex: A01)
    char nomeCidade1[TAMANHO_NOME];        // Nome da cidade
    int  populacao1;                       // Número de habitantes
    float area1;                           // Área em km²
    float pib1;                            // PIB em bilhões de reais
    int  pontosTuristicos1;                // Quantidade de pontos turísticos
    float densidadePopulacional1;          // Densidade populacional (hab/km²) - CALCULADO
    float pibPerCapita1;                   // PIB per capita (reais por habitante) - CALCULADO

    /*
     * ------------------------------------------------------------------
     *  VARIÁVEIS DA CARTA 2
     *
     *  Mesma estrutura de dados da carta 1, com nomes diferentes
     *  para armazenar as informações da segunda carta.
     * ------------------------------------------------------------------
     */

    char estado2;
    char codigo2[TAMANHO_CODIGO];
    char nomeCidade2[TAMANHO_NOME];
    int  populacao2;
    float area2;
    float pib2;
    int  pontosTuristicos2;
    float densidadePopulacional2;          // Densidade populacional (hab/km²) - CALCULADO
    float pibPerCapita2;                   // PIB per capita (reais por habitante) - CALCULADO

    /*
     * ==================================================================
     *  TELA INICIAL DO JOGO
     * ==================================================================
     */

    printf("==============================================\n");
    printf("       SUPER TRUNFO DE PAÍSES\n");
     printf("       Cadastro de Cartas de Cidades\n");
    printf("==============================================\n\n");

    /*
     * ==================================================================
     *  CADASTRO DA CARTA 1
     *
     *  Usamos scanf() para ler cada dado informado pelo usuário.
     *
     *  Formatos utilizados:
     *    %c              : lê um único caractere (estado)
     *    %s              : lê uma palavra sem espaços (código)
     *    %[^\n]          : lê texto com espaços (nome da cidade)
     *    %d              : lê um número inteiro (população, pontos)
     *    %f              : lê um número decimal (área, PIB)
     *
     *  O operador & antes do nome da variável passa o ENDEREÇO
     *  de memória onde o valor lido será armazenado.
     *  (Não é necessário para strings/arrays.)
     * ==================================================================
     */

    printf("--- Cadastro da Carta 1 ---\n\n");

    /* Leitura do Estado: uma única letra de 'A' a 'H' */
    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1);

    /* Leitura do Código: ex: A01, B03 (sem espaços) */
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    /* Leitura do Nome da Cidade: permite nomes com espaços */
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    /* Leitura da População: número inteiro de habitantes */
    printf("População: ");
    scanf("%d", &populacao1);

    /* Leitura da Área: valor decimal em km² */
    printf("Área (em km²): ");
    scanf("%f", &area1);

    /* Leitura do PIB: valor decimal em bilhões de reais */
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    /* Leitura dos Pontos Turísticos: número inteiro */
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    /*
     * ==================================================================
     *  CADASTRO DA CARTA 2
     *
     *  Mesmo processo da carta 1, mas armazenando nas variáveis
     *  com sufixo "2". O operador de atribuição é feito internamente
     *  pela função scanf(), que escreve o valor lido no endereço
     *  da variável indicada.
     * ==================================================================
     */

    printf("\n--- Cadastro da Carta 2 ---\n\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    /*
     * ==================================================================
     *  CÁLCULOS - Densidade Populacional e PIB per Capita
     *
     *  Usamos operadores aritméticos e de atribuição para calcular
     *  as duas novas propriedades de cada carta:
     *
     *  DENSIDADE POPULACIONAL:
     *      fórmula: população / área
     *      resultado: habitantes por km² (hab/km²)
     *      exemplo: 12.325.000 / 1521.11 = 8102.47 hab/km²
     *
     *  PIB PER CAPITA:
     *      fórmula: PIB / população
     *      resultado: reais por habitante
     *      atenção: o PIB está em bilhões, então multiplicamos
     *               por 1.000.000.000 para obter o valor em reais
     *      exemplo: (699.28 * 1e9) / 12.325.000 = 56.724,32 reais
     *
     *  Utilizamos cast (float) na população para garantir que
     *  a divisão seja decimal e não inteira (truncada).
     * ==================================================================
     */

    /* --- Cálculos da Carta 1 --- */
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;

    /* --- Cálculos da Carta 2 --- */
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;

    /*
     * ==================================================================
     *  EXIBIÇÃO DAS CARTAS CADASTRADAS
     *
     *  Usamos printf() para mostrar os dados armazenados em cada
     *  variável. Os especificadores de formato indicam como exibir
     *  cada tipo de dado:
     *    %c   → caractere          (estado)
     *    %s   → string/texto       (código, nome da cidade)
     *    %d   → inteiro            (população, pontos turísticos)
     *    %.2f → float com 2 casas  (área, PIB)
     * ==================================================================
     */

    printf("\n");
    printf("==============================================\n");
    printf("         CARTAS CADASTRADAS\n");
    printf("==============================================\n\n");

    /* --- Exibição da Carta 1 --- */

    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    /* --- Exibição da Carta 2 --- */

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    printf("\n");
    printf("==============================================\n");
    printf("Cadastro concluído com sucesso!\n");
    printf("==============================================\n\n");

    return 0;
}
