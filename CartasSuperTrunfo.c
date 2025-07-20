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
    scanf("%d", populacao);
    printf("Área:\n");
    scanf("%f", area);
    printf("PIB:\n");
    scanf("%f", pib);
    printf("Pontos turísticos:\n");
    scanf("%d", pontosTuristicos);
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

int main() {
    char nomecarta1 [50];
    int populacaocarta1;
    float areacarta1;
    float pibcarta1;
    int pontosturisticoscarta1;
    float densidadePopulacional1;
    float pibPercapita1;

    char nomecarta2 [50];
    int populacaocarta2;
    float areacarta2;
    float pibcarta2;
    int pontosturisticoscarta2;
    float densidadePopulacional2;
    float pibPercapita2;

    printf("SuperTrunfo!\n");
    printf("Cadastre a primeira carta:\n");
    leDadosCarta(nomecarta1, &populacaocarta1, &areacarta1, &pibcarta1, &pontosturisticoscarta1);
    printf("Cadastre a segunda carta:\n");
    leDadosCarta(nomecarta2, &populacaocarta2, &areacarta2, &pibcarta2, &pontosturisticoscarta2);
    
    exibeDadosCarta(nomecarta1, populacaocarta1, areacarta1, pibcarta1, pontosturisticoscarta1);
    exibeDadosCarta(nomecarta2, populacaocarta2, areacarta2, pibcarta2, pontosturisticoscarta2);
    return 0;
}