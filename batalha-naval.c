#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    char linhainicial[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int navio1li, navio1col, navio2li, navio2col;

    printf("Batalha Naval:\n");
    for (int k = 0; k < 11; k++) {
        printf(" %c ", linhainicial[k]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        if (i == 9) { printf("%i", i + 1); } // Imprime 10
        else { printf("%i ", i + 1); }     // Imprime 1 a 9
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nSelecione a posicao do primeiro navio (3x1), na horizontal:\n");
    printf("Qual linha? (1-10) \n");
    scanf("%i", &navio1li);
    printf("Qual coluna? (use numeros, A=1, B=2, etc) \n");
    scanf("%i", &navio1col);

    int linha_1 = navio1li - 1;
    int col_1 = navio1col - 1;

    if (linha_1 < 0 || linha_1 > 9 || col_1 < 0 || col_1 + 2 > 9) {
        printf("Posicao invalida! O navio de 3 espacos nao cabe ai.\n");
    } else {
        tabuleiro[linha_1][col_1] = 3;
        tabuleiro[linha_1][col_1 + 1] = 3;
        tabuleiro[linha_1][col_1 + 2] = 3;
    }

    printf("\nBatalha Naval com o navio posicionado:\n");
    for (int k = 0; k < 11; k++) {
        printf(" %c ", linhainicial[k]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        if (i == 9) { printf("%i", i + 1); }
        else { printf("%i ", i + 1); }
        for (int j = 0; j < 10; j++) {

            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nSelecione a posicao do segundo navio (3x1), na vertical:\n");
    printf("Qual linha? (1-10) \n");
    scanf("%i", &navio2li);
    printf("Qual coluna? (use numeros, A=1, B=2, etc) \n");
    scanf("%i", &navio2col);

    int linha_2 = navio2li - 1;
    int col_2 = navio2col - 1;

    if (linha_2 < 0 || linha_2 + 2 > 9 || col_2 < 0 || col_2 > 9) {
        printf("Posicao invalida! O navio de 3 espacos nao cabe ai.\n");
    } else {
        tabuleiro[linha_2][col_2] = 3;
        tabuleiro[linha_2 + 1][col_2] = 3;
        tabuleiro[linha_2 + 2][col_2] = 3;
    }

    printf("\nBatalha Naval com o navio posicionado:\n");
    for (int k = 0; k < 11; k++) {
        printf(" %c ", linhainicial[k]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        if (i == 9) { printf("%i", i + 1); }
        else { printf("%i ", i + 1); }
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}