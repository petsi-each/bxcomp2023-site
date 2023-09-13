#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int n;

	scanf("%d", &n);
	bool deque[n]; //falso se o código i saiu errado
	int livre = 0;

	while (n--) {
		char s[1000];

		scanf("%s", s);

		int soma = 0;

		for (int i = 1; i < strlen(s) - 1; i += 2) {
			soma += s[i] - '0';
		}

		if (soma <= s[strlen(s)-1] - '0') {
			deque[livre++] = false;
		} else {
			livre -= s[strlen(s)-1] - '0';
			if (livre < 0) livre = 0;
			deque[livre++] = true;
		}
	}
	for (int i = 0; i < livre; i++) {
		if (deque[i]) puts("essa adaga não ta bixada");
		else puts("adaga do tempo miadissima to fora");
	}
	
	return 0;
}


