#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    int populacaocarta1;
    float areacarta1;
    float pibcarta1;
    int pontosturisticoscarta1;

    int populacaocarta2;
    float areacarta2;
    float pibcarta2;
    int pontosturisticoscarta2;
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("SuperTrunfo!\n");
    printf("Cadastre a primeira carta:\n");
    printf("População:\n");
    scanf("%d", &populacaocarta1);
    printf("Área:\n");
    scanf("%f", &areacarta1);
    printf("PIB:\n");
    scanf("%f", &pibcarta1);
    printf("Pontos turísticos:\n");
    scanf("%d", &pontosturisticoscarta1);
    printf("\n");

    printf("Cadastre a segunda carta:\n");
    printf("População:\n");
    scanf("%d", &populacaocarta2);
    printf("Área:\n");
    scanf("%f", &areacarta2);
    printf("PIB:\n");
    scanf("%f", &pibcarta2);
    printf("Pontos turísticos:\n");
    scanf("%d", &pontosturisticoscarta2);
    printf("\n");

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    printf("Carta 1\n");
    printf("População: %d\n", populacaocarta1);
    printf("Área: %f\n", areacarta1);
    printf("PIB: %f\n", pibcarta1);
    printf("Pontos turísticos: %d\n", pontosturisticoscarta1);
    printf("\n");
    
    printf("Carta 2\n");
    printf("População: %d\n", populacaocarta2);
    printf("Área: %f\n", areacarta2);
    printf("PIB: %f\n", pibcarta2);
    printf("Pontos turísticos: %d\n", pontosturisticoscarta2);
    
    return 0;
}
