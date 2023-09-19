#include <stdio.h>
#include <math.h>

int main() {
    int numCasos;
    scanf("%d", &numCasos);

    for (int i = 0; i < numCasos; i++) {
        int numInteiros;
        scanf("%d", &numInteiros);

        int numMisterioso = pow(2, numInteiros);
      
        if(numInteiros == 7){
          printf("Almeida 7: \"Voce eh frango, te falta fraco, fiz %d desafios do BX!\"\n", numMisterioso);
        }else if(numInteiros == 6){
          printf("Almeida 6: \"Rato melequento!\"\n");
        }else{
          printf("Sonic: \"Eu te falei, eu nao sou um RATO! eu sou um OURICO! Faltaram soh mais %d...\"\n", 64 - numMisterioso);
        }
    }

    return 0;
}
