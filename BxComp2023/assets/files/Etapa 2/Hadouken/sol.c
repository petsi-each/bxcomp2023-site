#include <stdio.h>
#include <string.h>

void solve() {
	char in[31]; // 30 caracteres + caractere nulo

	scanf("%s", in);

	if (strspn(in, "AWSDJK") < strlen(in)) { //procura caracteres inválidos
		puts("Para de apertar qualquer coisa noob");
	} else if (strstr(in, "ASDJ")) {
		puts("HADOUKEEEN");
	} else {
		puts("Uuugh Uuugh...Continue? 10, 9, 8, 7, 6, 5, 4, 3, 2, 1...");
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();

	return 0;
}

