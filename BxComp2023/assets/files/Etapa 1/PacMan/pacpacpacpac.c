#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int casosTestes;
    scanf("%d", &casosTestes);

    for (int testen = 0; testen < casosTestes; testen++) {
        int tamanhoMatriz;
        int vidas = 3, pontos = 0;
        scanf("%d", &tamanhoMatriz);

        int** matriz = (int**)malloc(tamanhoMatriz * sizeof(int*));
        for (int i = 0; i < tamanhoMatriz; i++) {
            matriz[i] = (int*)malloc(tamanhoMatriz * sizeof(int));
            for (int j = 0; j < tamanhoMatriz; j++) {
                matriz[i][j] = 0;
            }
        }

        int* qtd = (int*)malloc((tamanhoMatriz - 1) * sizeof(int));
        for (int i = 0; i < tamanhoMatriz - 1; i++) {
            scanf("%d", &qtd[i]);
            if (qtd[i] > tamanhoMatriz - 1) {
                qtd[i] = tamanhoMatriz - 1;
            }
        }

        int qtdfantasmas;
        scanf("%d", &qtdfantasmas);

        for (int i = 0; i < qtdfantasmas; i++) {
            int linha, coluna;
            scanf("%d,%d", &linha, &coluna);
            matriz[linha][coluna] = 1;
        }

        int i = 0, j = 0;
        while (i != tamanhoMatriz - 1 || j != tamanhoMatriz - 1) {
            if (matriz[i][j] == 1) {
                vidas--;
                pontos = pontos - floor(pontos / 2);
            } else if (j != 0) {
                pontos++;
            }

            j++;

            if (i != tamanhoMatriz - 1) {
                if (j > qtd[i] || j > tamanhoMatriz - 1) {
                    j = 0;
                    i++;
                }
            }
        }

        pontos++;
        if (vidas <= 0)
            printf("GAME OVER!! vc eh muito ruim e morreu!\n");
        else
            printf("YOU WIN!!!!!!!!!!!!! campeao mandou muito com %d pontos e %d vidas :D\n", pontos, vidas);

        for (int i = 0; i < tamanhoMatriz; i++) {
            free(matriz[i]);
        }
        free(matriz);
        free(qtd);
    }

    return 0;
}
