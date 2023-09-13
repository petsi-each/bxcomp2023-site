#include <stdio.h>

#define COG 1
#define GOO 2

void solve() {
	int c, g, p, y;
	int mortal = 1, medo = 0, moveu = 0;

	scanf("%d %d %d %d", &c, &g, &p, &y);

	int mapa[p];
	for (int i = 0; i < p; ++i) {
		mapa[i] = 0;
	}

	for (int i = 0; i < c; ++i) {
		int lido;
		scanf("%d", &lido);
		mapa[lido] = COG;
	}

	for (int i = 0; i < g; ++i) {
		int lido;
		scanf("%d", &lido);
		mapa[lido] = GOO;
	}

	for (int i = 0; i < p; ++i) {
		if (medo && !moveu) {
			if (mortal) {
				printf("AH NAAAAOOOOO, O ENCANADOR FOI POR AGUA ABAIXO NO %d-ESIMO METRO\n", i);
				return;
			} else {
				mortal = 1;
				medo = 0;
			}
		}
		if (mapa[i] == GOO) {
			medo = 1;
		} else if (mapa[i] == COG) {
			mortal = 0;
		}
		moveu = 0;
		if ((i+1) % y == 0) { 
			moveu = 1; 
			if (mapa[p-1] == GOO) mapa[p-1] = 0;
			for (int j = p-2; j >= 0; --j) {
				if (mapa[j] == GOO) {
					mapa[j+1] = mapa[j];
					mapa[j] = 0;
				}
			}
		}
	}
	printf("AEEEEE VITORIAAA\n");
}

int main() {
	int t = 1;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
