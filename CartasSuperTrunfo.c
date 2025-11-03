#include <stdio.h>
#include <math.h> // Necessário para evitar o warning de 'infinidade' em operações de divisão por zero.

// Definição da estrutura da Carta (Cidade), baseada nos requisitos do Nível Mestre.
typedef struct {
    unsigned long int populacao; // Nível Mestre: unsigned long int
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Nível Aventureiro: Calculado
    float pib_per_capita;         // Nível Aventureiro: Calculado
    float super_poder;            // Nível Mestre: Calculado
} Carta;

// =======================================================
// FUNÇÕES AUXILIARES DE CADA NÍVEL
// =======================================================

// Função para cadastrar uma carta (Nível Novato: Entrada de Dados)
void cadastrar_carta(Carta *c, int numero) {
    printf("--- Cadastro da Carta %d ---\n", numero);
    
    // Leitura dos atributos base
    printf("População (unsigned long int): ");
    scanf("%lu", &c->populacao);
    
    printf("Área (float): ");
    scanf("%f", &c->area);
    
    printf("PIB (float): ");
    scanf("%f", &c->pib);
    
    printf("Número de pontos turísticos (int): ");
    scanf("%d", &c->pontos_turisticos);
    
    printf("\n");
}

// Função para calcular atributos derivados (Nível Aventureiro)
void calcular_atributos_derivados(Carta *c) {
    // Cálculo da Densidade Populacional: População / Área
    // Garante que a área não é zero para evitar divisão por zero
    if (c->area > 0.0) {
        c->densidade_populacional = (float)c->populacao / c->area;
    } else {
        c->densidade_populacional = 0.0;
    }

    // Cálculo do PIB per Capita: PIB / População
    // Garante que a população não é zero
    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / (float)c->populacao;
    } else {
        c->pib_per_capita = 0.0;
    }

    // Nível Mestre: Cálculo do Super Poder
    // Soma de todos os atributos, com a densidade populacional *invertida* (1/densidade)
    float densidade_invertida = 0.0;
    if (c->densidade_populacional > 0.0) {
        densidade_invertida = 1.0f / c->densidade_populacional;
    }

    c->super_poder = (float)c->populacao + 
                      c->area + 
                      c->pib + 
                      (float)c->pontos_turisticos +
                      densidade_invertida + // Densidade Invertida
                      c->pib_per_capita;
}

// Função para exibir os dados de uma carta (Nível Novato: Saída de Dados)
void exibir_carta(const Carta *c, int numero) {
    printf("--- Dados da Carta %d ---\n", numero);
    printf("População: %lu\n", c->populacao);
    printf("Área: %.2f\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Pontos Turísticos: %d\n", c->pontos_turisticos);

    // Nível Aventureiro: Exibe atributos calculados
    printf("\n[ATRIBUTOS CALCULADOS]\n");
    printf("Densidade Populacional: %.2f hab/un\n", c->densidade_populacional);
    printf("PIB per Capita: %.2f\n", c->pib_per_capita);
    
    // Nível Mestre: Exibe Super Poder
    printf("Super Poder: %.2f\n", c->super_poder);
    printf("--------------------------\n\n");
}

// Função de comparação (Nível Mestre)
// Retorna 1 se Carta 1 vence, 0 se Carta 2 vence, -1 se empate
int comparar(float c1_valor, float c2_valor, int vence_o_maior) {
    if (c1_valor == c2_valor) {
        return -1; // Empate
    }
    
    if (vence_o_maior) {
        return (c1_valor > c2_valor) ? 1 : 0;
    } else {
        return (c1_valor < c2_valor) ? 1 : 0; // Vence o menor (para Densidade)
    }
}

// Função para exibir o resultado da comparação
void exibir_comparacao(const char *atributo, int resultado) {
    printf("-> %s: ", atributo);
    if (resultado == 1) {
        printf("Carta 1 VENCE (1)\n");
    } else if (resultado == 0) {
        printf("Carta 2 VENCE (0)\n");
    } else {
        printf("EMPATE\n");
    }
}


// =======================================================
// FUNÇÃO PRINCIPAL
// =======================================================

int main() {
    Carta carta1;
    Carta carta2;

    printf("=========================================================\n");
    printf("        🃏 Desafio Super Trunfo - Países\n");
    printf("=========================================================\n\n");

    // ----------------------------------------
    // NÍVEL NOVATO: Cadastro Básico (Entrada)
    // ----------------------------------------
    cadastrar_carta(&carta1, 1);
    cadastrar_carta(&carta2, 2);

    // ----------------------------------------
    // NÍVEL AVENTUREIRO: Cálculo de Atributos
    // ----------------------------------------
    calcular_atributos_derivados(&carta1);
    calcular_atributos_derivados(&carta2);
    
    printf("========================================\n");
    printf("       Exibição de Atributos (Níveis Novato e Aventureiro)\n");
    printf("========================================\n");

    // NÍVEL NOVATO: Saída de Dados (agora com atributos calculados)
    exibir_carta(&carta1, 1);
    exibir_carta(&carta2, 2);

    // ----------------------------------------
    // NÍVEL MESTRE: Comparação e Super Poder
    // ----------------------------------------
    printf("========================================\n");
    printf("       Comparação de Cartas (Nível Mestre)\n");
    printf("========================================\n");
    
    // Comparação de População (Vence o MAIOR)
    exibir_comparacao("População", comparar((float)carta1.populacao, (float)carta2.populacao, 1));
    
    // Comparação de Área (Vence o MAIOR)
    exibir_comparacao("Área", comparar(carta1.area, carta2.area, 1));
    
    // Comparação de PIB (Vence o MAIOR)
    exibir_comparacao("PIB", comparar(carta1.pib, carta2.pib, 1));
    
    // Comparação de Pontos Turísticos (Vence o MAIOR)
    exibir_comparacao("Pontos Turísticos", comparar((float)carta1.pontos_turisticos, (float)carta2.pontos_turisticos, 1));
    
    // Comparação de PIB per Capita (Vence o MAIOR)
    exibir_comparacao("PIB per Capita", comparar(carta1.pib_per_capita, carta2.pib_per_capita, 1));
    
    // Comparação de Densidade Populacional (Vence o MENOR)
    exibir_comparacao("Densidade Populacional", comparar(carta1.densidade_populacional, carta2.densidade_populacional, 0));
    
    printf("----------------------------------------\n");
    
    // Comparação do Super Poder (Vence o MAIOR)
    exibir_comparacao("SUPER PODER", comparar(carta1.super_poder, carta2.super_poder, 1));

    printf("========================================\n");
    printf("       Simulação Concluída!\n");
    printf("========================================\n");

    return 0;
}