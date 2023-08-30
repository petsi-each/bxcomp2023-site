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

int maxChamp(int a, int b, int* champ) {
  if(a == b){ 
    *champ = 0;
    return a;
  }
  if (a > b){
    *champ = 1;
    return a;
  }
  *champ = 2;
  return b;
}

int maxInt(int a, int b) {
  if (a > b) return 1;
  return 2;
}

int main() {

  int t;

  scanf("%d", &t);

  while (t--)
    solve();

  return 0;
}

void solve(void) {
    int numJogos, champ, score;
    int jog1[100], jog2[100];
    int champ1 = 0; int champ2 = 0; int empate = 0;
    scanf("%d", &numJogos);
    for(int i = 0; i < numJogos; i++){
        scanf("%d %d", &jog1[i], &jog2[i]);
        score = maxChamp(jog1[i], jog2[i], &champ);
        if(champ == 0) empate = 1;
        else if(champ == 1) champ1++;
        else if(champ == 2) champ2++;

        if(empate == 1){
            printf("%d-Empate ", score);
            empate = 0;
        }
        else printf("%d-%d ", score, champ);
    }
    if(champ1 == champ2) puts("Resultado: Empate");
    else printf("Resultado: %d\n", maxInt(champ1, champ2));
}