#include <math.h>
#include <stdio.h>
#include <string.h>
double pi = 3.14159265;
// Função que retorna a circunferência truncada
double circ(float raio) { return (2 * raio * pi); }

int main(void) {
  int vezes;
  char str[20];
  char cod[23];
  float raio;
  scanf("%d", &vezes);
  
  for (int i = 0; i < vezes; i++) {
    scanf("%f", &raio);
    double circun = circ(raio);
    int circ = trunc(circun);
    sprintf(str, "%d", circ);
    scanf("%s", cod);
    char *result = strstr(cod, str);
    if (circun > 43075) {
      printf("OLHA O TAMANHO DESSE PLANETA\n");
    } else if (result == NULL) {
      printf("Ferrou, estamos no planeta errado\n");
    } else {
      printf("Foguete nao tem marcha re, vamo bora fml\n");
    }
  }
}