#include <stdio.h>

void espelharMatriz(int matriz[7][7]) {
  int temp;
  int auxM[7][7];

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      auxM[i][j] = matriz[i][j];
    }
  }

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      // Troca os elementos da diagonal principal com os elementos da diagonal
      // secundária
      if (i < j) {
        matriz[j][i] = auxM[i][j];
      }
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);

  for (int caso = 1; caso <= N; caso++) {
    int matriz[7][7];
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7; j++) {
        scanf("%d", &matriz[i][j]);
      }
    }
    espelharMatriz(matriz);
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7; j++) {
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
} 