#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str1 {
    int valor;
    char letra;
} letra;

void defineAlfabeto(letra *alfabeto) {
    for (int i = 0; i < 26; i++) {
        alfabeto[i].valor = i;
        alfabeto[i].letra = 'a' + i;
    }
}

int octalToDecimal(int octal) {
    int decimal = 0;
    int base = 1;

    while (octal != 0) {
        int digit = octal % 10;
        decimal += digit * base;
        base *= 8;
        octal /= 10;
    }

    return decimal;
}

int main() {
    letra alfabeto[26];
    defineAlfabeto(alfabeto);

    char line[256];
    while (1) {
        int prev = 0;
        fgets(line, sizeof(line), stdin);

        if (strcmp(line, "end\n") == 0) {
            break;
        }

        char *token = strtok(line, " ");
        while (token != NULL) {
            int current = octalToDecimal(atoi(token));
            int translated;

            if (prev == 0) {
                translated = current;
            } else {
                translated = current - prev;
                if (translated < 0) {
                    translated += 26;
                }
            }

            printf("%c", alfabeto[translated].letra);
            prev = current;

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    printf("Dag dag!\n");

    return 0;
}
