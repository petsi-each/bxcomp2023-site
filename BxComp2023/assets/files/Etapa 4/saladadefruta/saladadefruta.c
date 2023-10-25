#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

char *removerRepeticao(char *str) {
  char last = '/';
  char *newStr = malloc(1000);
  int index = 0;

  for (int i = 0; i < strlen(str); ++i) {
    if (tolower(str[i]) == last)
      continue;
    newStr[index++] = tolower(str[i]);
    last = tolower(str[i]);
  }
  return newStr;
}

int removertops(char *str) {
  const char s = 's';
  const char t = 't';
  const char o = 'o';
  const char p = 'p';
  char *newStr = malloc(1000);
  int count = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == s && str[i + 1] == t && str[i + 2] == o && str[i + 3] == p) {
      count++;
    } else {
      continue;
    }
  }
  return count;
}

void solve() {
  char str[1000];
  int ans = 0, flag = 0, tamanho;
  char *stop = "stop", *fim = "fim";

  scanf("%s", str);
  strcpy(str, removerRepeticao(str));
  int a = removertops(str);

  if (a == 0)
    printf("Petiane falhou :(\n");
  else
    printf("%d\n", a);
}

int main(void) {
  int n;

  scanf("%d", &n);

  while (n--)
    solve();

  return 0;
}
