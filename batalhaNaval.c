#include <stdio.h>

// Constantes Gerais
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Estruturas de Impressão
void imprimirTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Nível Novato
void nivelNovato() {
    int tabuleiro[5][5] = {0};

    // Navio horizontal (3 espaços)
    int x1 = 1, y1 = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[x1][y1 + i] = 1;
        printf("Navio horizontal: (%d, %d)\n", x1, y1 + i);
    }

    // Navio vertical (3 espaços)
    int x2 = 3, y2 = 2;
    for (int i = 0; i < 3; i++) {
        tabuleiro[x2 + i][y2] = 1;
        printf("Navio vertical: (%d, %d)\n", x2 + i, y2);
    }

    printf("\n");
}

// Nível Aventureiro
void nivelAventureiro() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Horizontal
    for (int i = 1; i <= 4; i++) tabuleiro[1][i] = 3;

    // Vertical
    for (int i = 5; i <= 8; i++) tabuleiro[i][2] = 3;

    // Diagonal principal
    for (int i = 0; i < 4; i++) tabuleiro[i][i] = 3;

    // Diagonal secundária
    for (int i = 0; i < 4; i++) tabuleiro[i][9 - i] = 3;

    printf("Tabuleiro (Aventureiro):\n");
    imprimirTabuleiro(TAMANHO_TABULEIRO, TAMANHO_TABULEIRO, tabuleiro);
}

// Nível Mestre
void habilidadeCone() {
    int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if ((i == 0 && j == 2) ||
                (i == 1 && j >= 1 && j <= 3) ||
                (i == 2)) {
                matriz[i][j] = 1;
            }
        }
    }

    printf("Habilidade: Cone\n");
    imprimirTabuleiro(TAMANHO_HABILIDADE, TAMANHO_HABILIDADE, matriz);
}

void habilidadeOctaedro() {
    int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][2] = 1;
    matriz[3][2] = 1;

    printf("Habilidade: Octaedro\n");
    imprimirTabuleiro(TAMANHO_HABILIDADE, TAMANHO_HABILIDADE, matriz);
}

void habilidadeCruz() {
    int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        matriz[2][i] = 1;
        matriz[i][2] = 1;
    }

    printf("Habilidade: Cruz\n");
    imprimirTabuleiro(TAMANHO_HABILIDADE, TAMANHO_HABILIDADE, matriz);
}

void nivelMestre() {
    habilidadeCone();
    habilidadeOctaedro();
    habilidadeCruz();
}

// Função Principal
int main() {
    printf("=== NÍVEL NOVATO ===\n");
    nivelNovato();

    printf("=== NÍVEL AVENTUREIRO ===\n");
    nivelAventureiro();

    printf("=== NÍVEL MESTRE ===\n");
    nivelMestre();

    return 0;
}
