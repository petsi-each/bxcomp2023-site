#include <stdio.h>
#include <string.h>

int main() {
  int N, M, dps, itemDps;
  char hero[50], item[50];

  scanf("%d\n", &N);

  for (int i = 0; i < N; i++) {
    dps = 0;

    fgets(hero, sizeof(hero), stdin);
    hero[strcspn(hero, "\n")] = '\0';

    scanf("%d\n", &M);

    for (int j = 0; j < M; j++) {
      fgets(item, sizeof(item) - 4, stdin);
      sscanf(strrchr(item, ' '), "%d", &itemDps);
      dps += itemDps;
    }

    printf("%s: %d DPS\n", hero, dps);
  }

  return 0;
}
