#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int ball = 0;

	while (a[ball] > 0) {
		for (int i = 0; i < n; ++i) {
			--a[i];
		}
		++ball;
		if (ball == n) ball = 0;
	}

	printf("%d\n", ball+1);
	
}

int main() {
	int t; scanf("%d", &t);
	while (t--) solve();

	return 0;
}
