#include <stdio.h>

#define SIZE 5

void buscarValor(int matrix[SIZE][SIZE], int valor, int* posicaoX, int* posicaoY) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == valor) {
                *posicaoX = i;
                *posicaoY = j;
                return;
            }
        }
    }
    *posicaoX = -1;
    *posicaoY = -1;
}


int calculaDistancia(int posicaoX1, int posicaoY1, int posicaoX2, int posicaoY2){
    int distanciaX =  posicaoX1 - posicaoX2;
    int distanciaY = posicaoY1 - posicaoY2;

    if(distanciaX < 0)
        distanciaX *= -1;

    if(distanciaY < 0)
        distanciaY *= -1;

    return distanciaX + distanciaY;
}


int main() {
    int matrix[SIZE][SIZE];

    int posicaoCorujaX, posicaoCorujaY;
    int posicaoCobraX, posicaoCobraY;

    int rodada = 0;
    while(1){ 

        // receber os valores da matriz
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        // encontrar posicao da cobra
        if(rodada ==  0){
            buscarValor(matrix, 42, &posicaoCobraX, &posicaoCobraY);
        }
 
        // encontrar posicao da coruja
        buscarValor(matrix, 13, &posicaoCorujaX, &posicaoCorujaY);

        // todas as corujas foram salvas
        if(posicaoCorujaX == -1 && posicaoCorujaY == -1){
            printf("Todas as corujas foram resgatadas XD\n");
            return 0;
        }

        int distancia = calculaDistancia(posicaoCobraX, posicaoCobraY, posicaoCorujaX, posicaoCorujaY); 

        printf("A cobrinha percorreu %d casas para salvar a coruja %d\n", distancia, rodada);
       
        posicaoCobraX = posicaoCorujaX;
        posicaoCobraY = posicaoCorujaY;
        rodada++;
    }
    return 0;

}
