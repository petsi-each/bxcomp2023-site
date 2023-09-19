#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int mun, gas, gra;

bool mata(char c) {
	switch (c) {
		case '1':
		if (mun >= 3) mun -=3;
		else if (gas) {
			--gas;
			mun = 10;
			if (gra < 2)
				++gra;
		}
		else if (gra) --gra;
		else return false;
		break;
		case '2':
		if (mun >= 5) mun -= 5;
		else if (gas) {
			--gas;
			mun = 10;
			if (gra < 2) 
				++gra;
		}
		else if (gra) --gra;
		else return false;
		break;
		case '3':
		if (gra) --gra;
		else return false;
		break;
	}
	return true;
}

void solve() {
	char vec[101];
	scanf("%s", vec);
	
	int len = strlen(vec);
	mun = 10, gas = 1, gra = 2;
	int diabos = 0;

	for (int i = 0; i < len; ++i) {
		if (!mata(vec[i])) {
			puts("Perdao padre.... eu falhei... Doom Guy.... OUT");
			return;
		}
		if (!gas) ++diabos;
		if (diabos == 4) { //nessa contagem, acabamos incrementando diabos desde a rodada que a gasolina foi gasta (mas isso só deveria ser feito a partir da rodada seguinte), por isso precisamos fazer a comparação com 4 e não com 3
			diabos = 0;
			++gas;
		}
	}
	puts("Padre? Mas que shape tao... AESTHETIC?! vamo deitar esses diabo!!!");
}

int main() {
	int n; scanf("%d", &n);
	while (n--) solve();

	return 0;
}
