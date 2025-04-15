#include <stdio.h>

int main() {
    char pais1[50], pais2[50];
    int pontosTuristicos1, pontosTuristicos2;
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    float densidadePop1, densidadePop2;
    int atributo1, atributo2;

    printf("Primeira Carta!\n");
    printf("Informe o país: \n");
    scanf(" %[^\n]", pais1);

    printf("Informe a populacão do país: \n");
    scanf(" %lu", &populacao1);

    printf("Informe a área do país (em km²): \n");
    scanf(" %f", &area1);

    printf("Informe o PIB do país (em bilhões): \n");
    scanf(" %f", &pib1);

    printf("Informe a quantidade de pontos turísticos no país: \n");
    scanf(" %d", &pontosTuristicos1);

    printf("\nSegunda Carta!\n");
    printf("Informe o país: \n");
    scanf(" %[^\n]", pais2);

    printf("Informe a populacão do país: \n");
    scanf(" %lu", &populacao2);

    printf("Informe a área do país (em km²): \n");
    scanf(" %f", &area2);

    printf("Informe o PIB do país (em bilhões): \n");
    scanf(" %f", &pib2);

    printf("Informe a quantidade de pontos turísticos no país: \n");
    scanf(" %d", &pontosTuristicos2);

    densidadePop1 = populacao1 / area1;
    densidadePop2 = populacao2 / area2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    if (atributo1 != 1) printf("1 - População\n");
    if (atributo1 != 2) printf("2 - Área\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turísticos\n");
    if (atributo1 != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo2);

    float v1_attr1 = 0, v2_attr1 = 0, v1_attr2 = 0, v2_attr2 = 0;

    switch (atributo1) {
        case 1: v1_attr1 = populacao1; v2_attr1 = populacao2; break;
        case 2: v1_attr1 = area1; v2_attr1 = area2; break;
        case 3: v1_attr1 = pib1; v2_attr1 = pib2; break;
        case 4: v1_attr1 = pontosTuristicos1; v2_attr1 = pontosTuristicos2; break;
        case 5: v1_attr1 = densidadePop1; v2_attr1 = densidadePop2; break;
    }

    switch (atributo2) {
        case 1: v1_attr2 = populacao1; v2_attr2 = populacao2; break;
        case 2: v1_attr2 = area1; v2_attr2 = area2; break;
        case 3: v1_attr2 = pib1; v2_attr2 = pib2; break;
        case 4: v1_attr2 = pontosTuristicos1; v2_attr2 = pontosTuristicos2; break;
        case 5: v1_attr2 = densidadePop1; v2_attr2 = densidadePop2; break;
    }

    int pontos1 = 0, pontos2 = 0;

    if (atributo1 == 5) {
        if (v1_attr1 < v2_attr1) pontos1++;
        else if (v2_attr1 < v1_attr1) pontos2++;
    } else {
        if (v1_attr1 > v2_attr1) pontos1++;
        else if (v2_attr1 > v1_attr1) pontos2++;
    }

    if (atributo2 == 5) {
        if (v1_attr2 < v2_attr2) pontos1++;
        else if (v2_attr2 < v1_attr2) pontos2++;
    } else {
        if (v1_attr2 > v2_attr2) pontos1++;
        else if (v2_attr2 > v1_attr2) pontos2++;
    }

    float soma1 = v1_attr1 + v1_attr2;
    float soma2 = v2_attr1 + v2_attr2;

    char* nomeAtributo1 = "";
    char* nomeAtributo2 = "";

    switch (atributo1) {
        case 1: nomeAtributo1 = "População"; break;
        case 2: nomeAtributo1 = "Área"; break;
        case 3: nomeAtributo1 = "PIB"; break;
        case 4: nomeAtributo1 = "Pontos Turísticos"; break;
        case 5: nomeAtributo1 = "Densidade Demográfica"; break;
    }

    switch (atributo2) {
        case 1: nomeAtributo2 = "População"; break;
        case 2: nomeAtributo2 = "Área"; break;
        case 3: nomeAtributo2 = "PIB"; break;
        case 4: nomeAtributo2 = "Pontos Turísticos"; break;
        case 5: nomeAtributo2 = "Densidade Demográfica"; break;
    }

    printf("\n--- Resultado da Rodada ---\n");
    printf("%s: %.2f x %.2f\n", nomeAtributo1, v1_attr1, v2_attr1);
    printf("%s: %.2f x %.2f\n", nomeAtributo2, v1_attr2, v2_attr2);
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    if (soma1 > soma2)
        printf("\n%s venceu a rodada!\n", pais1);
    else if (soma2 > soma1)
        printf("\n%s venceu a rodada!\n", pais2);
    else
        printf("\nEmpate!\n");

    return 0;
}