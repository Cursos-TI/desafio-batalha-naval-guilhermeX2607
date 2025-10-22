#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5  // Usamos 5x5 para as matrizes de habilidades

// Definições para o tabuleiro
#define AGUA 0
#define NAVIO 3
#define AREA_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializaTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro, diferenciando água, navios e área afetada
void imprimeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");          // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");          // Navio
            else if (tabuleiro[i][j] == AREA_HABILIDADE)
                printf("* ");          // Área da habilidade
            else
                printf("? ");          // Qualquer outro valor (não esperado)
        }
        printf("\n");
    }
    printf("\n");
}

// Gerar matriz da habilidade Cone (ponteiro para matriz 5x5 que será preenchida)
void geraHabilidadeCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de cone que cresce em largura enquanto desce
            // Distância do centro na linha
            int distLinha = i;
            int centro = TAMANHO_HABILIDADE / 2;
            // A coluna está dentro do cone se a distância para o centro da coluna <= distLinha
            if (j >= centro - distLinha && j <= centro + distLinha)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Gerar matriz da habilidade Cruz (5x5)
void geraHabilidadeCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Ativa a linha e coluna do centro formando uma cruz
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Gerar matriz da habilidade Octaedro (5x5, losango)
void geraHabilidadeOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // A condição para formar um losango:
            // Soma ou diferença dos índices relativa ao centro
            int distLinha = abs(i - centro);
            int distColuna = abs(j - centro);
            if (distLinha + distColuna <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Sobrepor a matriz de habilidade ao tabuleiro, centralizando no ponto origem (linhaOrigem, colOrigem)
void sobrepoeHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                        int linhaOrigem, int colOrigem) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = linhaOrigem + i - offset;
                int colTab = colOrigem + j - offset;

                // Verifica limites para não sair do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colTab >= 0 && colTab < TAMANHO_TABULEIRO) {

                    // Marca o local da habilidade no tabuleiro, a menos que já tenha navio
                    if (tabuleiro[linhaTab][colTab] != NAVIO) {
                        tabuleiro[linhaTab][colTab] = AREA_HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializaTabuleiro(tabuleiro);

    // Coloca alguns navios para exemplo (podem ser posicionados como quiser)
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;

    tabuleiro[7][7] = NAVIO;
    tabuleiro[8][7] = NAVIO;
    tabuleiro[9][7] = NAVIO;

    // Matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Gerar as áreas de efeito (matrizes com 0 e 1)
    geraHabilidadeCone(cone);
    geraHabilidadeCruz(cruz);
    geraHabilidadeOctaedro(octaedro);

    // Sobrepõe habilidades em pontos escolhidos no tabuleiro
    sobrepoeHabilidade(tabuleiro, cone, 1, 4);       // Ponto origem da habilidade Cone
    sobrepoeHabilidade(tabuleiro, cruz, 6, 3);       // Ponto origem da habilidade Cruz
    sobrepoeHabilidade(tabuleiro, octaedro, 8, 8);   // Ponto origem da habilidade Octaedro

    // Exibe o tabuleiro final
    imprimeTabuleiro(tabuleiro);

    return 0;
}
