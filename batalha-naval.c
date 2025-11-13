#include <stdio.h>

void imprimir_tabuleiro(int tabuleiro[10][10]) {
    char linhainicial[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("\n");
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
    printf("\n");
}


void aplicar_cone(int tabuleiro[10][10], int origem_linha, int origem_col) {
    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
    };
    int centro = 2;

    printf("Aplicando Habilidade Cone em (%d, %d)\n", origem_linha + 1, origem_col + 1);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
        
            if (cone[i][j] == 1) {
                int target_linha = origem_linha + (i - centro);
                int target_col = origem_col + (j - centro);

                // Verifica se a posição está DENTRO dos limites do tabuleiro (0-9)
                if (target_linha >= 0 && target_linha < 10 && target_col >= 0 && target_col < 10) {
                    tabuleiro[target_linha][target_col] = 5;
                }
            }
        }
    }
}

void aplicar_cruz(int tabuleiro[10][10], int origem_linha, int origem_col) {
    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    int centro = 2;

    printf("Aplicando Habilidade Cruz em (%d, %d)\n", origem_linha + 1, origem_col + 1);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int target_linha = origem_linha + (i - centro);
                int target_col = origem_col + (j - centro);

                if (target_linha >= 0 && target_linha < 10 && target_col >= 0 && target_col < 10) {
                        tabuleiro[target_linha][target_col] = 6;
                }
            }
        }
    }
}

void aplicar_octaedro(int tabuleiro[10][10], int origem_linha, int origem_col) {
    int octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
    };
    int centro = 2;

    printf("Aplicando Habilidade Octaedro em (%d, %d)\n", origem_linha + 1, origem_col + 1);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int target_linha = origem_linha + (i - centro);
                int target_col = origem_col + (j - centro);

                if (target_linha >= 0 && target_linha < 10 && target_col >= 0 && target_col < 10) {
                        tabuleiro[target_linha][target_col] = 8;
                }
            }
        }
    }
}


int main() {
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int navio1li, navio1col, navio2li, navio2col, navio3li, navio3col, navio4li, navio4col;
    int origem_r, origem_c;

    printf("Batalha Naval:\n");
    imprimir_tabuleiro(tabuleiro);

    // --- NAVIO 1 (Horizontal) ---
    printf("\nSelecione a posicao do primeiro navio (3x1), na horizontal:\n");
    printf("Qual linha? (1-10) \n");
    scanf("%i", &navio1li);
    printf("Qual coluna? (A=1, B=2, etc) \n");
    scanf("%i", &navio1col);

    int linha_1 = navio1li - 1;
    int col_1 = navio1col - 1;

    if (linha_1 < 0 || linha_1 > 9 || col_1 < 0 || col_1 + 2 > 9) {
        printf("Posicao invalida! O navio de 3 espacos nao cabe ai.\n");
    } else if (tabuleiro[linha_1][col_1] == 3 || tabuleiro[linha_1][col_1 + 1] == 3 || tabuleiro[linha_1][col_1 + 2] == 3) {
        printf("Posicao invalida! Ja existe um navio ai.\n");
    } else {
        tabuleiro[linha_1][col_1] = 3;
        tabuleiro[linha_1][col_1 + 1] = 3;
        tabuleiro[linha_1][col_1 + 2] = 3;
    }
    imprimir_tabuleiro(tabuleiro);

    // --- NAVIO 2 (Vertical) ---
    printf("\nSelecione a posicao do segundo navio (3x1), na vertical:\n");
    printf("Qual linha? (1-10) \n");
    scanf("%i", &navio2li);
    printf("Qual coluna? (A=1, B=2, etc) \n");
    scanf("%i", &navio2col);

    int linha_2 = navio2li - 1;
    int col_2 = navio2col - 1;

    if (linha_2 < 0 || linha_2 + 2 > 9 || col_2 < 0 || col_2 > 9) {
        printf("Posicao invalida! O navio de 3 espacos nao cabe ai.\n");
    } 
    else if (tabuleiro[linha_2][col_2] == 3 || tabuleiro[linha_2 + 1][col_2] == 3 || tabuleiro[linha_2 + 2][col_2] == 3) {
        printf("Posicao invalida! Ja existe um navio ai.\n");
    } else {
        tabuleiro[linha_2][col_2] = 3;
        tabuleiro[linha_2 + 1][col_2] = 3;
        tabuleiro[linha_2 + 2][col_2] = 3;
    }
    imprimir_tabuleiro(tabuleiro);

    // --- NAVIO 3 (Diagonal) ---
    printf("\nSelecione a posicao do terceiro navio (3x1), na diagonal (\\):\n");
    printf("Qual linha? (1-10) \n");
    scanf("%i", &navio3li);
    printf("Qual coluna? (A=1, B=2, etc) \n");
    scanf("%i", &navio3col);

    int linha_3 = navio3li - 1;
    int col_3 = navio3col - 1;
    if (linha_3 < 0 || linha_3 + 2 > 9 || col_3 < 0 || col_3 + 2 > 9) {
        printf("Posicao invalida! O navio de 3 espacos nao cabe ai.\n");
    } else if (tabuleiro[linha_3][col_3] == 3 || tabuleiro[linha_3 + 1][col_3 + 1] == 3 || tabuleiro[linha_3 + 2][col_3 + 2] == 3) {
        printf("Posicao invalida! Ja existe um navio ai.\n");
    } else {
        tabuleiro[linha_3][col_3] = 3;
        tabuleiro[linha_3 + 1][col_3 + 1] = 3;
        tabuleiro[linha_3 + 2][col_3 + 2] = 3;
    }
    imprimir_tabuleiro(tabuleiro);

    // --- NAVIO 4 (Diagonal) ---
    printf("\nSelecione a posicao do quarto navio (3x1), na diagonal (\\):\n");
    printf("Qual linha? (1-10) \n");
    scanf("%i", &navio4li);
    printf("Qual coluna? (A=1, B=2, etc) \n");
    scanf("%i", &navio4col);

    int linha_4 = navio4li - 1;
    int col_4 = navio4col - 1;

    if (linha_4 < 0 || linha_4 + 2 > 9 || col_4 < 0 || col_4 + 2 > 9) {
        printf("Posicao invalida! O navio de 3 espacos nao cabe ai.\n");
    } 
    else if (tabuleiro[linha_4][col_4] == 3 || tabuleiro[linha_4 + 1][col_4 + 1] == 3 || tabuleiro[linha_4 + 2][col_4 + 2] == 3) {
        printf("Posicao invalida! Ja existe um navio ai.\n");
    } else {
        tabuleiro[linha_4][col_4] = 3;
        tabuleiro[linha_4 + 1][col_4 + 1] = 3;
        tabuleiro[linha_4 + 2][col_4 + 2] = 3;
    }
    imprimir_tabuleiro(tabuleiro);


    printf("\n--- HABILIDADES ESPECIAIS ---\n");

    printf("Defina a origem da habilidade CONE:\n");
    printf("Linha (1-10): ");
    scanf("%i", &origem_r);
    printf("Coluna (1-10): ");
    scanf("%i", &origem_c);
    aplicar_cone(tabuleiro, origem_r - 1, origem_c - 1); // -1 para converter para índice 0-9

    printf("Defina a origem da habilidade CRUZ:\n");
    printf("Linha (1-10): ");
    scanf("%i", &origem_r);
    printf("Coluna (1-10): ");
    scanf("%i", &origem_c);
    aplicar_cruz(tabuleiro, origem_r - 1, origem_c - 1);

    printf("Defina a origem da habilidade OCTAEDRO (LOSANGO):\n");
    printf("Linha (1-10): ");
    scanf("%i", &origem_r);
    printf("Coluna (1-10): ");
    scanf("%i", &origem_c);
    aplicar_octaedro(tabuleiro, origem_r - 1, origem_c - 1);

    printf("\n--- Tabuleiro Final com Habilidades Aplicadas (5) ---\n");
    imprimir_tabuleiro(tabuleiro);

    return 0;
}