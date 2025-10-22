#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se a posição está dentro do tabuleiro
int dentroLimite(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar se a posição está livre (não tem navio)
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == 0);
}

// Função para posicionar navio horizontal
int posicionaNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int colunaAtual = colunaInicio + i;
        if (!dentroLimite(linha, colunaAtual) || !posicaoLivre(tabuleiro, linha, colunaAtual))
            return 0; // falha na validação
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][colunaInicio + i] = 3;
    }
    return 1; // sucesso
}

// Função para posicionar navio vertical
int posicionaNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual = linhaInicio + i;
        if (!dentroLimite(linhaAtual, coluna) || !posicaoLivre(tabuleiro, linhaAtual, coluna))
            return 0; // falha na validação
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][coluna] = 3;
    }
    return 1; // sucesso
}

// Função para posicionar navio diagonal (linha e coluna aumentam juntos)
int posicionaNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual = linhaInicio + i;
        int colunaAtual = colunaInicio + i;
        if (!dentroLimite(linhaAtual, colunaAtual) || !posicaoLivre(tabuleiro, linhaAtual, colunaAtual))
            return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio + i] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal decrescente (linha aumenta, coluna diminui)
int posicionaNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linhaAtual = linhaInicio + i;
        int colunaAtual = colunaInicio - i;
        if (!dentroLimite(linhaAtual, colunaAtual) || !posicaoLivre(tabuleiro, linhaAtual, colunaAtual))
            return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicio + i][colunaInicio - i] = 3;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona os dois navios horizontais/verticais
    if (!posicionaNavioHorizontal(tabuleiro, 1, 1)) {
        printf("Erro ao posicionar navio horizontal 1\n");
    }
    if (!posicionaNavioVertical(tabuleiro, 4, 5)) {
        printf("Erro ao posicionar navio vertical 1\n");
    }

    // Posiciona os dois navios diagonais
    if (!posicionaNavioDiagonalCrescente(tabuleiro, 6, 2)) {
        printf("Erro ao posicionar navio diagonal crescente\n");
    }
    if (!posicionaNavioDiagonalDecrescente(tabuleiro, 2, 7)) {
        printf("Erro ao posicionar navio diagonal decrescente\n");
    }

    // Mostra o tabuleiro no console
    printf("Tabuleiro do jogo de Batalha Naval:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
