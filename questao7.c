#include <stdio.h>

int main() {
    int N;

    do {
        printf("Digite o valor de N (N >= 3): ");
        scanf("%d", &N) != 1;
        
        if (N < 3) {
            printf(" ERRO! VALOR INVALIDO!\n\n");
        }
    } while (N < 3);

    int matriz[N][N];

    int linha_inicio = 0, linha_fim = N - 1;
    int col_inicio = 0, col_fim = N - 1;
    
    int valor = 1;
    int limite_maximo = N * N;

    while (valor <= limite_maximo) {
        for (int j = col_inicio; j <= col_fim && valor <= limite_maximo; j++) {
            matriz[linha_inicio][j] = valor++;
        }
        linha_inicio++;

        for (int i = linha_inicio; i <= linha_fim && valor <= limite_maximo; i++) {
            matriz[i][col_fim] = valor++;
        }
        col_fim--;

        for (int j = col_fim; j >= col_inicio && valor <= limite_maximo; j--) {
            matriz[linha_fim][j] = valor++;
        }
        linha_fim--;

        for (int i = linha_fim; i >= linha_inicio && valor <= limite_maximo; i--) {
            matriz[i][col_inicio] = valor++;
        }
        col_inicio++; 
        }   

    int num_maximo = N * N;
    int largura_coluna = 0;
    while (num_maximo > 0) {
        largura_coluna++;
        num_maximo /= 10;
    }

    printf("\nEspiral gerada para N = %d:\n\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%*d ", largura_coluna, matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}