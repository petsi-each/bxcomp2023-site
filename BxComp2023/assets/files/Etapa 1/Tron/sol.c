#include <stdio.h>
#include <stdbool.h>

bool perdeu() {
	int cateto, angulo;

	scanf("%d, %d", &cateto, &angulo);

	int cosseno10;

	switch(angulo) {
		case 30:
			cosseno10 = 8; //trabalhar com inteiros
			break;
		case 45:
			cosseno10 = 7;
			break;
		case 60:
			cosseno10 = 5;
			break;
	}

	return ((cateto * 10) % (cosseno10)); 
}
	
void solve() {
	int t = 3;
	bool derrota = false;
	
	while (t--) 
		if (perdeu()) {
			derrota = true;
		}
	if (derrota) {
		puts("Lamentron, mas perdi, teremos que derrotar ele na batalha de motos de luz.");
		return;
	}
	puts("Ele teve um encontron com a derrota, hora de tomar cafe no PET.");
}
	
int main () {
	int n;

	scanf("%d", &n);

	while (n--) solve();

	return 0;
}

