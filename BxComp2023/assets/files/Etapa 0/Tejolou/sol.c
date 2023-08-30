#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dbg(args...) printf(args);
#define dbgi(args) dbg(#args) dbg(" = %ld\n", args)
#define dbgf(args) dbg(#args) dbg(" = %lf\n", args)
#define fir(i, a, b) for (int i = (a); i < (b); i++)
#define f0r(i, a) fir(i, 0, a)

#define ROWS 6
#define COLS 10

typedef long long ll;

void solve(void);

int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int main() {

  int t;

  scanf("%d", &t);

  while (t--)
    solve();

  return 0;
}

int pontuacao(int x, int y, int entradaInt[ROWS][COLS]) {
  int baixo, esquerda, direita, cima;
  baixo = esquerda = direita = cima = 0;
  for (int i = y; i < ROWS; i++) {
    baixo += entradaInt[i][x];
  }
  for (int i = y; i >= 0; i--) {
    cima += entradaInt[i][x];
  }
  for (int j = x; j < COLS; j++) {
    direita += entradaInt[y][j];
  }
  for (int j = x; j >= 0; j--) {
    esquerda += entradaInt[y][j];
  }
  int menor1 = min(baixo, esquerda);
  int menor2 = min(cima, direita);
  return min(menor1, menor2);
}

void solve(void) {
  char entrada[ROWS][COLS];
  int entradaInt[ROWS][COLS];
  char tempChar;
  char itemPet;
  int itemPetX = -1;
  int itemPetY = -1;
  int somaMatriz = 0;
  int somaPontos = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      scanf(" %c", &entrada[i][j]);
      tempChar = entrada[i][j];
      if (tempChar >= '0' && tempChar <= '9') {
        entradaInt[i][j] = tempChar - '0';
      } else {
        itemPet = tempChar;
        itemPetY = i;
        itemPetX = j;
        entradaInt[i][j] = 0;
      }
    }
  }
  if (itemPetY == -1 && itemPetX == -1) {
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        somaMatriz += entradaInt[i][j];
      }
    }
    printf("Nossa, cheio de predas, consegui %d pontos.\n", somaMatriz);
  } else {
    switch (entrada[itemPetY][itemPetX]) {
    case 'F':
      somaPontos = pontuacao(itemPetX, itemPetY, entradaInt);
      printf("Opa, achei o item, Nitrato de Fala coruja297, esta na posicao "
             "%dx%d, terei que fazer %d pontos para conseguir chegar la.\n",
             itemPetY, itemPetX, somaPontos);
      break;
    case 'O':
      somaPontos = pontuacao(itemPetX, itemPetY, entradaInt);
      printf("Opa, achei o item, O2wlficiNASA, esta na posicao "
             "%dx%d, terei que fazer %d pontos para conseguir chegar la.\n",
             itemPetY, itemPetX, somaPontos);
      break;
    case 'G':
      somaPontos = pontuacao(itemPetX, itemPetY, entradaInt);
      printf("Opa, achei o item, GTX-Grace 4090, esta na posicao "
             "%dx%d, terei que fazer %d pontos para conseguir chegar la.\n",
             itemPetY, itemPetX, somaPontos);
      break;
    case 'C':
      somaPontos = pontuacao(itemPetX, itemPetY, entradaInt);
      printf("Opa, achei o item, Paodo-Competech2077, esta na posicao "
             "%dx%d, terei que fazer %d pontos para conseguir chegar la.\n",
             itemPetY, itemPetX, somaPontos);
      break;
    default:
      break;
    }
  }
}