#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long bin(int n) {
  long numbin=0,resto,f=1;
  while(n != 0)
  {
       resto = n % 2;
       numbin = numbin + resto * f;
       f = f * 10;
       n = n / 2;
  }
  return numbin;  
}

int uns(char *str){
  int qtd = 0;
  for(int i = 0;i<strlen(str);i++)
    {
      if(str[i] == '1')
      {
        qtd++;
      }
    }
  return qtd;
}

int main(void) {
  int vezes;
  scanf("%d",&vezes);
  char str1[20]; 
  char str2[20]; 
  int n1,n2;
  for(int i=0;i<vezes;i++){
    scanf("%d", &n1);
    scanf("%d", &n2);
    long bin1=bin(n1);
    long bin2=bin(n2);
    sprintf(str1,"%ld", bin1);
    sprintf(str2,"%ld", bin2);
    int qtd1 = uns(str1);
    int qtd2 = uns(str2);
    if(((qtd1-qtd2)%2) == 0){
      printf("DEU GREEN MARCHAAAA ESTOREI NA BET VAMO PRA DUBAI\n");
    }
    else{
      printf("Vermelhou aqui, ja era. Pai vou ter que vender a casa\n");
    }
  }
  return 0;
}