#include <stdio.h>

int firstNonEmpty(int column, int matrix[10][5]) {
  for (int i = 0; i < 10; i++) {
    if (matrix[i][column] == 1)
      return i;
  }
  return 10;
}

int fitL(int matrix[10][5]) {
  for (int j = 1; j < 5; j++) {
    int line = firstNonEmpty(j, matrix);
    if (line > 1 && !matrix[line - 2][j - 1] && matrix[line - 1][j - 1] && firstNonEmpty(j-1,matrix)>line-2)
      return 1;
  }
  return -1;
}

int fitI(int matrix[10][5]) {
  for (int j = 0; j < 5; j++) {
    int line = firstNonEmpty(j, matrix), sum = 0;
    if (line > 2) {
      if (j == 4)
        sum += 1;

      else if (matrix[line - 1][j + 1] && matrix[line - 2][j + 1] &&
               matrix[line - 3][j + 1])
        sum += 1;

      if (j == 0)
        sum += 1;
      else if (matrix[line - 1][j - 1] && matrix[line - 2][j - 1] &&
               matrix[line - 3][j - 1])
        sum += 1;
      if (sum == 2)
        return 1;

    } else
      continue;
  }
  return -1;
}

int main(void) {
  int qtd;
  scanf("%d", &qtd);

  for (int vez = 0; vez < qtd; vez++) {
    int matrix[10][5], biggest = 0;
    for (int i = 0; i < 10; i++) {
      int sum = 0;
      for (int j = 0; j < 5; j++) {

        scanf("%d", &matrix[i][j]);
        sum += matrix[i][j];
        if (sum > biggest)
          biggest = sum;
      }
    }

    if (biggest == 5)
      printf("Algo de errado nao esta certo...\n");

    else if (fitL(matrix) == 1 || fitI(matrix) == 1)
      printf("Eu amo jogar Tetrio.\n");

    else
      printf("AH NAO VEY\n");
  }

  return 0;
}