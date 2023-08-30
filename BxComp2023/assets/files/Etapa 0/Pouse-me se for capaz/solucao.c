#include "stdio.h"
#include "string.h"

int main() {
    char comando[999];
    scanf("%s", comando);
    while(strcmp(comando, "QAR")) {
        char endereco[999];
        scanf("\n%[^\n]", endereco);
        int letras_ruido = 0;
        int i = 0;
        char c = endereco[i];
        while(c != '\0') {
            if(c == '@' || c == '&' || c == '!' || c == '*')
                letras_ruido++;
            i++;
            c = endereco[i];
        }
        if(letras_ruido >= (float) strlen(endereco) / 2)
            printf("Base T, estou com muito QRT na mensagem, poderia reenviar ?\n");
        else
            printf("Imperatriz, o pouso sera na zona %s\n", endereco);
        scanf("%s", comando);
    }
}
