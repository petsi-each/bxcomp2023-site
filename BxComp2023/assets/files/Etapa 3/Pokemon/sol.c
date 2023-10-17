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

typedef long long ll;

void solve(void);

float min(float a, float b) {
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

void solve(void) {
  char input[255];
  int a, b, c, d, e;
  int sum;
  bool startsWithQUXY;

  scanf("\n%[^\n]", input);

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &e);

  sum = a + b + c + d + e;

  startsWithQUXY = input[0] == 'Q' || input[0] == 'U' || input[0] == 'X' ||
                   input[0] == 'Y' || input[0] == 'q' || input[0] == 'u' ||
                   input[0] == 'x' || input[0] == 'y';

  if (sum > 744 || sum < 195 || startsWithQUXY) {
    printf("%s ta esquisito hein, deve ser um Digimon!\n", input);
  } else {
    printf("%s parece legitimo, da ate pra acreditar.\n", input);
  }
}
