#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorreRecursivo(int casas, char direcao) {
    if (casas > 0) {
        printf("%s\n", direcao == 'c' ? "Cima" : (direcao == 'b' ? "Baixo" : (direcao == 'e' ? "Esquerda" : "Direita")));
        moverTorreRecursivo(casas - 1, direcao);
    }
}

// Função recursiva para o movimento do Bispo
void moverBispoRecursivo(int casas, int linha, int coluna) {
    if (casas > 0) {
        if (linha > 0 && coluna > 0) {
            printf("Diagonal Cima-Esquerda\n");
            moverBispoRecursivo(casas - 1, linha - 1, coluna - 1);
        } else if (linha > 0 && coluna < 0) {
            printf("Diagonal Cima-Direita\n");
            moverBispoRecursivo(casas - 1, linha - 1, coluna + 1);
        } else if (linha < 0 && coluna > 0) {
            printf("Diagonal Baixo-Esquerda\n");
            moverBispoRecursivo(casas - 1, linha + 1, coluna - 1);
        } else if (linha < 0 && coluna < 0) {
            printf("Diagonal Baixo-Direita\n");
            moverBispoRecursivo(casas - 1, linha + 1, coluna + 1);
        }
    }
}

// Função recursiva para o movimento da Rainha (combina Torre e Bispo)
void moverRainhaRecursivo(int casas, int linha, int coluna) {
    if (casas > 0) {
        if (linha > 0 && coluna == 0) {
            printf("Cima\n");
            moverRainhaRecursivo(casas - 1, linha - 1, coluna);
        } else if (linha < 0 && coluna == 0) {
            printf("Baixo\n");
            moverRainhaRecursivo(casas - 1, linha + 1, coluna);
        } else if (linha == 0 && coluna > 0) {
            printf("Esquerda\n");
            moverRainhaRecursivo(casas - 1, linha, coluna - 1);
        } else if (linha == 0 && coluna < 0) {
            printf("Direita\n");
            moverRainhaRecursivo(casas - 1, linha, coluna + 1);
        } else if (linha > 0 && coluna > 0) {
            printf("Diagonal Cima-Esquerda\n");
            moverRainhaRecursivo(casas - 1, linha - 1, coluna - 1);
        } else if (linha > 0 && coluna < 0) {
            printf("Diagonal Cima-Direita\n");
            moverRainhaRecursivo(casas - 1, linha - 1, coluna + 1);
        } else if (linha < 0 && coluna > 0) {
            printf("Diagonal Baixo-Esquerda\n");
            moverRainhaRecursivo(casas - 1, linha + 1, coluna - 1);
        } else if (linha < 0 && coluna < 0) {
            printf("Diagonal Baixo-Direita\n");
            moverRainhaRecursivo(casas - 1, linha + 1, coluna + 1);
        }
    }
}

int main() {
    // Movimento da Torre
    printf("--- Movimento da Torre ---\n");
    int casasTorre = 5;
    char direcaoTorre = 'c'; // Cima
    moverTorreRecursivo(casasTorre, direcaoTorre);
    printf("\n");

    // Movimento do Cavalo (para cima e para a direita em "L")
    printf("--- Movimento do Cavalo ---\n");
    for (int cima = 2; cima >= 2; cima--) { // Move sempre duas casas para cima
        for (int direita = 1; direita <= 1; direita++) { // Move sempre uma casa para a direita
            printf("Cima\n");
            printf("Cima\n");
            printf("Direita\n");
        }
    }
    printf("\n");

    // Movimento do Bispo com loops aninhados
    printf("--- Movimento do Bispo (Loops Aninhados) ---\n");
    int casasBispo = 3;
    for (int i = 1; i <= casasBispo; i++) { // Loop para o número de casas (vertical)
        for (int j = 1; j <= i; j++) { // Loop para o número de casas (horizontal, dependente do vertical para diagonal)
            printf("Diagonal Cima-Direita\n");
        }
        if (i < casasBispo) {
            printf("\n"); // Separar cada "passo" diagonal
        }
    }
    printf("\n");

    // Movimento da Rainha
    printf("--- Movimento da Rainha ---\n");
    int casasRainha = 4;
    int linhaRainha = -casasRainha; // Movimento para baixo
    int colunaRainha = 0;
    moverRainhaRecursivo(casasRainha, linhaRainha, colunaRainha);
    printf("\n");

    return 0;
}
