#include <stdio.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

/* Estrutura da carta */
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    float densidade;
} Carta;

/* Protótipos */
void desafio1(Carta c1, Carta c2);
void desafio2(Carta c1, Carta c2);
void desafio3(Carta c1, Carta c2);

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif

    /* Cartas de exemplo */
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1.92, 25.1};
    Carta carta2 = {"Argentina", 46000000, 2780400.0, 0.63, 16.5};

    int opcao;

    do {
        printf("\n=== SUPER TRUNFO EM C ===\n");
        printf("1 - Desafio 1 (1 atributo | if / else)\n");
        printf("2 - Desafio 2 (múltiplos atributos | switch / if-else)\n");
        printf("3 - Desafio 3 (2 atributos | operador ternário)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desafio1(carta1, carta2);
                break;
            case 2:
                desafio2(carta1, carta2);
                break;
            case 3:
                desafio3(carta1, carta2);
                break;
            case 0:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

void desafio1(Carta c1, Carta c2) {
    printf("\n--- DESAFIO 1 ---\n");
    printf("Comparando POPULAÇÃO\n");

    if (c1.populacao > c2.populacao) {
        printf("%s vence!\n", c1.nome);
    } else if (c2.populacao > c1.populacao) {
        printf("%s vence!\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

void desafio2(Carta c1, Carta c2) {
    int escolha;

    printf("\n--- DESAFIO 2 ---\n");
    printf("Escolha o atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf("%s vence!\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("%s vence!\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 2:
            if (c1.area > c2.area)
                printf("%s vence!\n", c1.nome);
            else if (c2.area > c1.area)
                printf("%s vence!\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 3:
            if (c1.pib > c2.pib)
                printf("%s vence!\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("%s vence!\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 4:
            if (c1.densidade > c2.densidade)
                printf("%s vence!\n", c1.nome);
            else if (c2.densidade > c1.densidade)
                printf("%s vence!\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }
}

void desafio3(Carta c1, Carta c2) {
    int pontos1 = 0;
    int pontos2 = 0;

    printf("\n--- DESAFIO 3 ---\n");
    printf("Atributos: População e PIB\n");

    pontos1 += (c1.populacao > c2.populacao) ? 1 : 0;
    pontos2 += (c2.populacao > c1.populacao) ? 1 : 0;

    pontos1 += (c1.pib > c2.pib) ? 1 : 0;
    pontos2 += (c2.pib > c1.pib) ? 1 : 0;

    printf("Pontuação %s: %d\n", c1.nome, pontos1);
    printf("Pontuação %s: %d\n", c2.nome, pontos2);

    (pontos1 > pontos2) ? printf("%s vence!\n", c1.nome) :
    (pontos2 > pontos1) ? printf("%s vence!\n", c2.nome) :
                          printf("Empate!\n");
}
