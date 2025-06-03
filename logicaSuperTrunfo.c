#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

Carta carta1, carta2;

void calcularDados(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    c->superPoder = (float)c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + (1 / c->densidade);

    if (c->densidade > 1000)
        printf("\nAlta densidade populacional!\n");

    if (c->pibPerCapita > 50000)
        printf("Cidade com alto desenvolvimento econômico!\n");
    else if (c->pibPerCapita > 25000)
        printf("Cidade com médio desenvolvimento econômico!\n");
    else
        printf("Cidade em desenvolvimento econômico!\n");
}

void entradaDados(Carta *carta, int numero) {
    printf("───────────────── ⋆⋅☆⋅⋆ ────────────────\n");
    printf("✦✦ Cadastro da Carta %d ✦✦ \n", numero);
    printf("┌───────────────── ⋆⋅☆⋅⋆ ────────────────┐\n");

    printf("│➜ Digite o Estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("│➜ Digite o Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("│➜ Digite o Nome da Cidade: ");
    while (getchar() != '\n');
    fgets(carta->nomeCidade, 50, stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0;

    printf("│➜ Digite a População: ");
    scanf("%ld", &carta->populacao);

    printf("│➜ Digite a Área (em km²): ");
    scanf("%f", &carta->area);

    printf("│➜ Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("│➜ Digite os Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    printf("└──────────────────────────────────────┘\n");
}

void exibirCarta(Carta c, int numero) {
    printf("┌───────────────── ⋆⋅☆⋅⋆ ────────────────┐\n");
    printf("│✦✦ Carta %d ✦✦ \n", numero);
    printf("│Estado: %s\n", c.estado);
    printf("│Código: %s\n", c.codigo);
    printf("│Nome da Cidade: %s\n", c.nomeCidade);
    printf("│População: %ld\n", c.populacao);
    printf("│Área: %.2f km²\n", c.area);
    printf("│PIB: %.2f bilhões de reais\n", c.pib);
    printf("│Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("│Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("│PIB per Capita: %.2f reais\n", c.pibPerCapita);
    printf("│Super Poder: %.2f\n", c.superPoder);
    printf("└────────────────────────────────────────┘\n");
}

void exibirMenu() {
    printf("\n┌───────────────⋆˚✿˖°──────────────────┐\n");
    printf("│ MENU DE COMPARAÇÃO              \n");
    printf("│                                 \n");
    printf("│ Escolha um atributo:            \n");
    printf("│ 1. População                    \n");
    printf("│ 2. Área                         \n");
    printf("│ 3. PIB                          \n");
    printf("│ 4. Pontos Turísticos            \n");
    printf("│ 5. Densidade Populacional       \n");
    printf("│ 6. PIB per Capita               \n");
    printf("└────────────────⋆˚✿˖°──────────────────┘\n");
    printf("Digite sua escolha (1-6): ");
}

void compararCartas() {
    int opcao;
    exibirMenu();
    scanf("%d", &opcao);

    float valor1, valor2;

    printf("\n┌───────────────₍^. .^₎⟆──────────────────┐\n");
    printf("│ COMPARAÇÃO DE CARTAS            \n");

    switch (opcao) {
        case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; printf("│ Atributo: População\n"); break;
        case 2: valor1 = carta1.area; valor2 = carta2.area; printf("│ Atributo: Área\n"); break;
        case 3: valor1 = carta1.pib; valor2 = carta2.pib; printf("│ Atributo: PIB\n"); break;
        case 4: valor1 = carta1.pontosTuristicos; valor2 = carta2.pontosTuristicos; printf("│ Atributo: Pontos Turísticos\n"); break;
        case 5: valor1 = carta1.densidade; valor2 = carta2.densidade; printf("│ Atributo: Densidade Populacional\n"); printf("│ (Menor valor é melhor)\n"); break;
        case 6: valor1 = carta1.pibPerCapita; valor2 = carta2.pibPerCapita; printf("│ Atributo: PIB per Capita\n"); break;
        default: printf("│ Opção inválida! Usando PIB per Capita.\n"); valor1 = carta1.pibPerCapita; valor2 = carta2.pibPerCapita; break;
    }

    printf("│ Carta 1 - %s: %.2f\n", carta1.nomeCidade, valor1);
    printf("│ Carta 2 - %s: %.2f\n", carta2.nomeCidade, valor2);

    if ((opcao == 5 && valor1 < valor2) || (opcao != 5 && valor1 > valor2))
        printf("│ Carta 1 é a melhor!\n");
    else if (valor1 == valor2)
        printf("│ Empate!\n");
    else
        printf("│ Carta 2 é a melhor!\n");

    printf("└────────────────⋆⭒˚.⋆ ⋆⭒˚.⋆─────────────────┘\n");
}

int main() {
    entradaDados(&carta1, 1);
    calcularDados(&carta1);
    exibirCarta(carta1, 1);

    entradaDados(&carta2, 2);
    calcularDados(&carta2);
    exibirCarta(carta2, 2);

    compararCartas();
    return 0;
}

    

    
