#include <stdio.h>

float calculaDensidadePopulacional(int populacaoCidade, float areaCidade){
    return populacaoCidade / areaCidade;
}

float calculaPibPercapita(float pibCidade, int populacaoCidade){
    return pibCidade / populacaoCidade;
}

void leDadosCarta(char *nome, int *populacao, float *area, float *pib, int *pontosTuristicos){
    printf("Nome da carta:\n");
    scanf("%s", nome);
    printf("População:\n");
    scanf(" %d", populacao);
    printf("Área:\n");
    scanf(" %f", area);
    printf("PIB:\n");
    scanf(" %f", pib);
    printf("Pontos turísticos:\n");
    scanf(" %d", pontosTuristicos);
    printf("\n");
}

void exibeDadosCarta(char *nome, int populacao, float area, float pib, int pontosTuristicos)
{
    printf("Nome da carta: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área: %f\n", area);
    printf("PIB: %f\n", pib);
    printf("Pontos turísticos: %d\n", pontosTuristicos);
    printf("Densidade populacional: %f\n", calculaDensidadePopulacional(populacao, area));
    printf("PIB percapita: %f\n", calculaPibPercapita(pib, populacao));
    printf("\n");
}

float calculaSuperPoderCarta(int populacao, float area, float pib, int pontosTuristicos, float pibPercapita, float densidadePopulacional)
{
    return (float) populacao + area + (float) pib + (float) pontosTuristicos + pibPercapita - densidadePopulacional;
}

void comparaCartas(int populacaoCarta1, int populacaoCarta2
, float areaCarta1, float areaCarta2
, float pibCarta1, float pibCarta2
, int pontosTuristicosCarta1, int pontosTuristicosCarta2
, float superPoderCarta1, float superPoderCarta2)
{
    printf("Comparação das cartas:\n");
    if(populacaoCarta1 > populacaoCarta2) printf("População: Carta 1 venceu\n");
    else printf("População: Carta 2 venceu\n");
    
    if(areaCarta1 > areaCarta2) printf("Área: Carta 1 venceu\n");
    else printf("Área: Carta 2 venceu\n");

    if(pibCarta1 > pibCarta2) printf("PIB: Carta 1 venceu\n");
    else printf("PIB: Carta 2 venceu\n");

    if(pontosTuristicosCarta1 > pontosTuristicosCarta2) printf("Pontos turísticos: Carta 1 venceu\n");
    else printf("Pontos turísticos: Carta 2 venceu\n");

    if(calculaDensidadePopulacional(populacaoCarta1, areaCarta1) 
        < calculaDensidadePopulacional(populacaoCarta2, areaCarta2)) printf("Densidade populacional: Carta 1 venceu\n");
    else printf("Densidade populacional: Carta 2 venceu\n");

    if(calculaPibPercapita(pibCarta1, populacaoCarta1) 
        > calculaPibPercapita(pibCarta2, populacaoCarta2)) printf("Pib percapita: Carta 1 venceu\n");
    else printf("Pib percapita: Carta 2 venceu\n");

    if(superPoderCarta1 > superPoderCarta2) printf("Super poder: Carta 1 venceu\n");
    else printf("Super poder: Carta 2 venceu\n");
}

int main() 
{
    char nomeCarta1 [50];
    int populacaoCarta1;
    float areaCarta1;
    float pibCarta1;
    int pontosTuristicosCarta1;
    float densidadePopulacionalCarta1;
    float pibPercapitaCarta1;
    float superPoderCarta1;

    char nomeCarta2 [50];
    int populacaoCarta2;
    float areaCarta2;
    float pibCarta2;
    int pontosTuristicosCarta2;
    float densidadePopulacionalCarta2;
    float pibPercapitaCarta2;
    float superPoderCarta2;

    printf("SuperTrunfo!\n");
    printf("Cadastre a primeira carta:\n");
    leDadosCarta(nomeCarta1, &populacaoCarta1, &areaCarta1, &pibCarta1, &pontosTuristicosCarta1);
    printf("Cadastre a segunda carta:\n");
    leDadosCarta(nomeCarta2, &populacaoCarta2, &areaCarta2, &pibCarta2, &pontosTuristicosCarta2);
    
    superPoderCarta1 = calculaSuperPoderCarta(populacaoCarta1, areaCarta1, pibCarta1, pontosTuristicosCarta1,
    calculaPibPercapita(pibCarta1, populacaoCarta1), calculaDensidadePopulacional(populacaoCarta1, areaCarta1));

    superPoderCarta2 = calculaSuperPoderCarta(populacaoCarta2, areaCarta2, pibCarta2, pontosTuristicosCarta2,
    calculaPibPercapita(pibCarta2, populacaoCarta2), calculaDensidadePopulacional(populacaoCarta2, areaCarta2));

    comparaCartas(populacaoCarta1, populacaoCarta2, areaCarta1, areaCarta2, pibCarta1, pibCarta2,
         pontosTuristicosCarta1, pontosTuristicosCarta2, superPoderCarta1, superPoderCarta2);

    // exibeDadosCarta(nomeCarta1, populacaoCarta1, areaCarta1, pibCarta1, pontosTuristicosCarta1);
    // exibeDadosCarta(nomeCarta2, populacaoCarta2, areaCarta2, pibCarta2, pontosTuristicosCarta2);
    return 0;
}