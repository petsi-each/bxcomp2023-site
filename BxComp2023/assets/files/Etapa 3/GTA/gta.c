#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int calcularObstaculo(char* obstaculo){
  int sum=0;
  for(int i = 0; i < strlen(obstaculo); i++){
      sum += obstaculo[i];
  }
  return floor(sum/(strlen(obstaculo)*15));
}

int main() {
 
  
  int casosTeste;

  scanf("%d", &casosTeste);
  for(int teste = 0; teste < casosTeste; teste++){

    int erro = 0;
    char obstaculo[90]; 
    char controleJogador[90];
      
    while(1){
   
      scanf("%s", obstaculo);

      if(!strcmp(obstaculo, "fim")) break;
        
      scanf("%s", controleJogador);

      if(
        
        (calcularObstaculo(obstaculo) % 2 != 0 && !strcmp(controleJogador, "botaodireito")) || (calcularObstaculo(obstaculo) % 2 == 0 && !strcmp(controleJogador, "botaoesquerdo"))
        
        ){
        erro++;
      } 

    }

    if(erro!=0) printf("TUDO QUE A GENTE PRECISAVA FAZER ERA SEGUIR O MALDITO TREM, CJ!\n");
    else printf("MISSAO COMPLETA!! RESPECT + B)\n");
  
  }
  
  
  return 0;
}