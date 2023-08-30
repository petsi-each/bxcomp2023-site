#include <stdio.h>

void solve() {
	int mapa[10], indiceNave = -1, meteorosFrente = 0, indiceUltimoMeteoroTras = -10;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &mapa[i]);
		if (mapa[i] == 2) indiceNave = i;
		if (mapa[i] == 1) {
			if (indiceNave == -1) indiceUltimoMeteoroTras = i;
			else meteorosFrente++;
		}
	}
	if (meteorosFrente <= 2 && ( (indiceNave - indiceUltimoMeteoroTras) >= (10 - indiceNave) ) )
		puts("Explorador do espaço para base alpha, conseguimos passar pela chuva de meteoros!");
	else puts("Nu, vou tascar um beijo numa pedra do espaço se eu entrar aí, paia.");
}

int main() {
	int n;

	scanf("%d", &n);

	while (n--) solve();

	return 0;
}
