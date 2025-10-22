#include <stdio.h>  // Biblioteca para funções de entrada e saída

// Define o tamanho do tabuleiro e o tamanho dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Cria uma matriz para representar o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    // Inicializa o tabuleiro com zero, ou seja, água
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define as posições iniciais dos navios
    int linhaNavioHorizontal = 2;   // navio posicionado na linha 2
    int colunaNavioHorizontal = 4;  // início na coluna 4

    int linhaNavioVertical = 5;     // navio posicionado na coluna 7
    int colunaNavioVertical = 7;    // início na linha 5

    // Vetores que representam os navios (todos valores 3 para indicar navio)
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Posiciona navio horizontal no tabuleiro
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Calcula a coluna atual somando o índice ao ponto inicial
        int colunaAtual = colunaNavioHorizontal + i;

        // Verifica se está dentro dos limites para evitar erros
        if (colunaAtual < TAMANHO_TABULEIRO) {
            tabuleiro[linhaNavioHorizontal][colunaAtual] = navioHorizontal[i];
        }
    }

    // Posiciona navio vertical no tabuleiro
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Calcula a linha atual somando o índice ao ponto inicial
        int linhaAtual = linhaNavioVertical + i;

        // Verifica se está dentro dos limites para evitar erros
        if (linhaAtual < TAMANHO_TABULEIRO) {
            tabuleiro[linhaAtual][colunaNavioVertical] = navioVertical[i];
        }
    }

    // Imprime o tabuleiro para o usuário ver onde os navios estão
    printf("Tabuleiro do jogo de Batalha Naval:\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");  // pular para a próxima linha no tabuleiro
    }

    return 0;  // finaliza o programa com sucesso
}
