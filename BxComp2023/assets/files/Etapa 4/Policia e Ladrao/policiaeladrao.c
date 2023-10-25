#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int posicoesParaAlinharColunas(int colunaP, int colunaL) {
  return colunaL - colunaP;
}

bool intercepta(int linhaL, int linhaP, int colL, int colP) {
  if (((linhaL == linhaP) && (colL == colP) && (linhaL < 9)) ||
      ((colL == colP) && (linhaL < linhaP) && (linhaL < 9))) {
    return true;
  } else
    return false;
}

int main() {
  /* casos teste*/
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    /* recebe inteiros */
    int velocPolicia, velocLadrao;
    scanf("%d %d", &velocPolicia, &velocLadrao);
    /* recebe matriz e posicoes Policia e Ladrao */
    char matriz[10][10];
    int linhaP, linhaL, colunaP, colunaL;
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        scanf(" %c", &matriz[j][k]);
      }
    }
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (matriz[j][k] == 'P') {
          linhaP = j;
          colunaP = k;
        } else if (matriz[j][k] == 'L') {
          linhaL = j;
          colunaL = k;
        }
      }
    }

    int tempo = 0;
    bool interceptou = false, chegouNaBase = false, colAlinhada;
    if (colunaL == colunaP)
      colAlinhada = true;
    else
      colAlinhada = false;

    /* Itera o tempo, realiza os deslocamentos enquanto ainda nao interceptou ou
     * chegou na base */
    while (tempo < 3 && !interceptou && !chegouNaBase) {
      tempo++;

      /* desloca ladrao */
      linhaL = linhaL + velocLadrao;

      /* desloca policia */
      if (!colAlinhada) {
        int p = posicoesParaAlinharColunas(colunaP, colunaL);
        int modulo = abs(p);
        if (modulo < velocPolicia) { // se sobrou posicoes, alinhou a coluna com
                                     // a do ladrao e andou verticalmente
          int sobraVertical = abs(velocPolicia - modulo);
          colAlinhada = true;
          colunaP = colunaP + p;
          linhaP = linhaP + sobraVertical;
        } else if (modulo == velocPolicia) { // se alinhou perfeitamente
          colAlinhada = true;
          colunaP = colunaL;
        } else { // se não alinhou
          if (colunaL > colunaP) {
            colunaP = colunaP + velocPolicia;
          } else {
            colunaP = colunaP - velocPolicia;
          }
        }
        // se ja alinhou a coluna no início da iteração, percorrer na vertical
        // (policia)
      } else {
        linhaP = linhaP + velocPolicia;
      }

      /* compara as posições para ver se interceptou ou se ladrao chegou na
       * base antes */
      interceptou = intercepta(linhaL, linhaP, colunaL, colunaP);
      if (linhaL >= 9)
        chegouNaBase = true;
      // interceptou chegando na mesma posição final ou com o ladrao chegando
      // em uma posicao adiantada
      if (chegouNaBase) {
        printf("Dessa vez o crime compensou...\n");
        break;
      } else if (interceptou) {
        printf("Hoje nao, essa cidade eh pequena demais para nos dois\n");
        break;
      }
    }
    if (!chegouNaBase && !interceptou) {
      printf("Olha so, nem preciso me mexer!\n");
    }
  }
}
