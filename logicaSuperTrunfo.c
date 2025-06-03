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

    // Função para entrada dos dados de uma carta 
    void entradaDados(Carta *carta, int numero){ 
    
    printf("───────────────── ⋆⋅☆⋅⋆ ────────────────\n");
    printf("✦✦ Cadastro da Carta %d ✦✦ \n",numero);
    printf("┌───────────────── ⋆⋅☆⋅⋆ ────────────────┐\n");
    printf("│➜ Digite o Estado (ex: SP) ");
    scanf("%s", &carta->estado);
    printf("│➜ Digite o Código da Carta (ex: A01): ");
    scanf("%s", &carta->codigo);   
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
    
    // Função para calcular atributos derivados da carta
    void calcularDados(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    c->superPoder = (float)c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + (1 / c->densidade);
}

    void exibirCarta(Carta c, int numero) {
    printf("┌───────────────── ⋆⋅☆⋅⋆ ────────────────┐\n");
    printf("│✦✦ Carta %d ✦✦ \n",numero);
    printf("│Estado: %s\n", c.estado);
    printf("│Código: %s\n", c.codigo);
    printf("│Nome da Cidade: %s\n", c.nomeCidade);
    printf("│População: %d\n", c.populacao);
    printf("│Área: %.2f km²\n", c.area);
    printf("│PIB: %.2f bilhões de reais\n", c.pib);
    printf("│Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("│Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("│PIB per Capita: %.2f reais\n", c.pibPerCapita);
    printf("│Super Poder: %.2f\n", c.superPoder);
    printf("└────────────────────────────────────────┘\n");
    }

void exibirMenu()
{
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
    printf("│                                 \n");
    printf("└────────────────⋆˚✿˖°──────────────────┘\n");
    printf("Digite sua escolha (1-6): ");
}
void compararCartas()
{
    int opcao;
    exibirMenu();
    scanf("%d", &opcao);

    printf("\n┌───────────────₍^. .^₎⟆──────────────────┐\n");
    printf("│ COMPARAÇÃO DE CARTAS            \n");
    switch (opcao)
    {
        case 1:
            printf("│ Atributo: População        \n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.nomeCidade,
                   carta1.populacao, carta1.populacao);
            printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.nomeCidade,
                   carta2.estado, carta2.populacao;)
            printf("│                                 \n");
            if (carta1.populacao > carta2.populacao)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.populacao < carta2.populacao)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
            break;
        case 2: // Área
            printf("│ Atributo: Área                 \n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.nomeCidade,
                   carta1.estado, carta1.area);
            printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.nomeCidade,
                   carta2.estado, carta2.area);
            printf("│                                 \n");
            if (carta1.area > carta2.area)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.area < carta2.area)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
            break;

        case 3: // PIB
            printf("│ Atributo: PIB                  \n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.nomeCidade,
                   carta1.estado, carta1.pib);
            printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.nomeCidade,
                   carta2.estado, carta2.pib);
            printf("│                                 \n");
            if (carta1.pib > carta2.pib)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.pib < carta2.pib)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("│ Atributo: Pontos Turísticos    \n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %d         \n", carta1.nomeCidade,
                   carta1.estado, carta1.pontosTuristicos);
            printf("│ Carta 2 - %s (%s): %d         \n", carta2.nomeCidade,
                   carta2.estado, carta2.pontosTuristicos);
            printf("│                                 \n");
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
            break;

        case 5: // Densidade Populacional (regra inversa)
            printf("│ Atributo: Densidade Populacional\n");
            printf("│ (Menor valor é melhor)          \n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.nomeCidade,
                   carta1.estado, carta1.densidade);
            printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.nomeCidade,
                   carta2.estado, carta2.densidade);
            printf("│                                 \n");
            if (carta1.densidade < carta2.densidade)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.densidade >
                     carta2.densidade)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
            break;

        case 6: // PIB per Capita
            printf("│ Atributo: PIB per capita        \n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.nomeCidade,
                   carta1.estado, carta1.pibPerCapita);
            printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.nomeCidade,
                   carta2.estado, carta2.pibPerCapita);
            printf("│                                 \n");
            if (carta1.pibPerCapita > carta2.pibPerCapita)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.pibPerCapita < carta2.pibPerCapita)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
            break;

        default:
            printf("│ Opção inválida!                \n");
            printf("│ Usando PIB per capita como padrão\n");
            printf("│                                 \n");
            printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.nomeCidade,
                   carta1.estado, carta1.pibPerCapita);
            printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.nomeCidade,
                   carta2.estado, carta2.pibPerCapita);
            printf("│                                 \n");
            if (carta1.pibPerCapita > carta2.pibPerCapita)
            {
                printf("│ Carta 1 é a melhor!            \n");
            }
            else if (carta1.pibPerCapita < carta2.pibPerCapita)
            {
                printf("│ Carta 2 é a melhor!            \n");
            }
            else
            {
                printf("│ Empate!                        \n");
            }
    }
    printf("└────────────────⋆⭒˚.⋆ ⋆⭒˚.⋆─────────────────┘\n"); 
}
int main()
{
    entradaDados(&carta1, 1);
    calcularIndicadores(&carta1);
    mostrarCarta(&carta1, 1);

    entradaDados(&carta2, 2);
    calcularIndicadores(&carta2);
    mostrarCarta(&carta2, 2);

    compararCartas();
    return 0;
}


    

    
