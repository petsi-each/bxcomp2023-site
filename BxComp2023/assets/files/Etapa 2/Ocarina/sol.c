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

bool can_be_palindrome(char str[]) {
  int frequency[10] = {
      0}; // Array para armazenar a frequência de cada dígito de 0 a 9

  for (int i = 0; i < 13; i++) {
    frequency[str[i] - '0']++; // Incrementa a frequência do dígito atual
  }

  int odd_count = 0;
  for (int i = 0; i < 10; i++) {
    if (frequency[i] % 2 != 0) {
      odd_count++;
    }
  }

  // No máximo uma unidade pode ter uma contagem ímpar para ser rearranjado como
  // palíndromo
  return odd_count <= 1;
}

void solve(void) {
  char number[14]; // 13 unidades + 1 para o caractere nulo

  scanf("%13s", number);

  if (can_be_palindrome(number)) {
    printf("Na vasta densa floresta de Hyrule, por longo tempo, servi como "
           "espirito guardiao\n");
  } else {
    printf("Ocarina Ocarina\n", number);
  }
}
