/*
 * ==============================================================================
 *  SUPER TRUNFO DE PAÍSES - Nível Mestre
 *  Linguagem: C
 * ==============================================================================
 *
 *  Descrição:
 *      Programa completo do jogo Super Trunfo de Países. Permite cadastrar
 *      duas cartas com dados de cidades, calcular propriedades derivadas
 *      (densidade populacional, PIB per capita e Super Poder) e comparar
 *      as cartas atributo por atributo para determinar a vencedora.
 *
 *  Conceitos aplicados:
 *      - Variáveis e tipos de dados (char, int, unsigned long int, float, char[])
 *      - Operadores de atribuição (=)
 *      - Operadores aritméticos (+, /)
 *      - Operadores relacionais (>, <)
 *      - Conversão de tipos (cast)
 *      - Estruturas condicionais (if, else)
 *      - Funções de entrada e saída (printf, scanf)
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

    /* ------------------------------------------------------------------
     *  VARIÁVEIS DA CARTA 1
     * ------------------------------------------------------------------
     */

    char            estado1;
    char            codigo1[TAMANHO_CODIGO];
    char            nomeCidade1[TAMANHO_NOME];
    unsigned long   int populacao1;
    float           area1;
    float           pib1;
    int             pontosTuristicos1;

    /* Variáveis calculadas - Carta 1 */
    float           densidadePopulacional1;
    float           pibPerCapita1;
    float           superPoder1;

    /* ------------------------------------------------------------------
     *  VARIÁVEIS DA CARTA 2
     * ------------------------------------------------------------------
     */

    char            estado2;
    char            codigo2[TAMANHO_CODIGO];
    char            nomeCidade2[TAMANHO_NOME];
    unsigned long   int populacao2;
    float           area2;
    float           pib2;
    int             pontosTuristicos2;

    /* Variáveis calculadas - Carta 2 */
    float           densidadePopulacional2;
    float           pibPerCapita2;
    float           superPoder2;

    /*
     * ==================================================================
     *  TELA INICIAL DO JOGO
     * ==================================================================
     */

    printf("==============================================\n");
    printf("       SUPER TRUNFO DE PAÍSES\n");
    printf("       Nível Mestre - Batalha de Cartas\n");
    printf("==============================================\n\n");

    /*
     * ==================================================================
     *  CADASTRO DA CARTA 1
     *
     *  NOTA SOBRE O BUFFER:
     *  Após cada scanf, usamos getchar() para consumir APENAS o '\n'
     *  (Enter) deixado no buffer. Isso evita que o Enter residual
     *  interfira na próxima leitura, sem consumir dados válidos.
     *
     *  ATENÇÃO: Use apenas NÚMEROS no campo População.
     *  Caracteres como '!' ou '.' causam erro de leitura.
     * ==================================================================
     */

    printf("--- Cadastro da Carta 1 ---\n\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado1);
    getchar();

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    getchar();

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    getchar();

    printf("População (apenas números, ex: 12325000): ");
    scanf("%lu", &populacao1);
    getchar();

    printf("Área (em km²): ");
    scanf("%f", &area1);
    getchar();

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    getchar();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    getchar();

    /*
     * ==================================================================
     *  CADASTRO DA CARTA 2
     * ==================================================================
     */

    printf("\n--- Cadastro da Carta 2 ---\n\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &estado2);
    getchar();

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo2);
    getchar();

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    getchar();

    printf("População (apenas números, ex: 6748000): ");
    scanf("%lu", &populacao2);
    getchar();

    printf("Área (em km²): ");
    scanf("%f", &area2);
    getchar();

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    getchar();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    getchar();

    /*
     * ==================================================================
     *  CÁLCULOS - Densidade Populacional, PIB per Capita e Super Poder
     * ==================================================================
     */

    /* --- Cálculos da Carta 1 --- */
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    superPoder1 = (float)populacao1
                + area1
                + pib1
                + (float)pontosTuristicos1
                + pibPerCapita1
                + (1.0f / densidadePopulacional1);

    /* --- Cálculos da Carta 2 --- */
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    superPoder2 = (float)populacao2
                + area2
                + pib2
                + (float)pontosTuristicos2
                + pibPerCapita2
                + (1.0f / densidadePopulacional2);

    /*
     * ==================================================================
     *  EXIBIÇÃO DAS CARTAS CADASTRADAS
     * ==================================================================
     */

    printf("\n");
    printf("==============================================\n");
    printf("           CARTAS CADASTRADAS\n");
    printf("==============================================\n\n");

    /* --- Exibição da Carta 1 --- */
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    /* --- Exibição da Carta 2 --- */
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    /*
     * ==================================================================
     *  COMPARAÇÃO DE CARTAS - BATALHA
     * ==================================================================
     */

    printf("\n");
    printf("==============================================\n");
    printf("       COMPARAÇÃO DE CARTAS\n");
    printf("==============================================\n\n");

    /* População: MAIOR vence */
    if (populacao1 > populacao2) {
        printf("População: Carta 1 venceu (1)\n");
    } else {
        printf("População: Carta 2 venceu (0)\n");
    }

    /* Área: MAIOR vence */
    if (area1 > area2) {
        printf("Área: Carta 1 venceu (1)\n");
    } else {
        printf("Área: Carta 2 venceu (0)\n");
    }

    /* PIB: MAIOR vence */
    if (pib1 > pib2) {
        printf("PIB: Carta 1 venceu (1)\n");
    } else {
        printf("PIB: Carta 2 venceu (0)\n");
    }

    /* Pontos Turísticos: MAIOR vence */
    if (pontosTuristicos1 > pontosTuristicos2) {
        printf("Pontos Turísticos: Carta 1 venceu (1)\n");
    } else {
        printf("Pontos Turísticos: Carta 2 venceu (0)\n");
    }

    /* Densidade Populacional: MENOR vence (regra especial!) */
    if (densidadePopulacional1 < densidadePopulacional2) {
        printf("Densidade Populacional: Carta 1 venceu (1)\n");
    } else {
        printf("Densidade Populacional: Carta 2 venceu (0)\n");
    }

    /* PIB per Capita: MAIOR vence */
    if (pibPerCapita1 > pibPerCapita2) {
        printf("PIB per Capita: Carta 1 venceu (1)\n");
    } else {
        printf("PIB per Capita: Carta 2 venceu (0)\n");
    }

    /* Super Poder: MAIOR vence */
    if (superPoder1 > superPoder2) {
        printf("Super Poder: Carta 1 venceu (1)\n");
    } else {
        printf("Super Poder: Carta 2 venceu (0)\n");
    }

    printf("\n");
    printf("==============================================\n");
    printf("         Batalha concluída!\n");
    printf("==============================================\n\n");

    return 0;
}
