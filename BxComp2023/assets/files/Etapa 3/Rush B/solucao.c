#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void sort(int* serie_numerica, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            if(serie_numerica[i] > serie_numerica[j]) {
                swap(&serie_numerica[i], &serie_numerica[j]);
            }
        }
    }
}

// função apenas para testes 
void printSerie(int* serie_numerica, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", serie_numerica[i]);
    }
    printf("\n");
}

int main() {
    int num_casos;
    scanf("%d", &num_casos);
    for(int i = 0; i < num_casos; i++) {
        char serie[999];
        scanf("%s", serie);
        int serie_numerica[999];
        int tamanho = strlen(serie);
        for(int i = 0; i < tamanho; i++) {
            // colocar conversão no enunciado
            serie_numerica[i] = (serie[i]) - '0';
        }
        sort(serie_numerica, tamanho);
        if(serie_numerica[tamanho - 1] % 2 == 0) { // se for par
            for(int i = 0; i < tamanho; i++) {
                printf("%d", serie_numerica[i]);
            }
            printf("\n");
        } else { // se for ímpar
            printf("Fallen guarda a AWP porque vai explodir.\n");
        }
    }
    return 0;
}
