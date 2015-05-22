#include <bits/stdc++.h>
using namespace std;

const int u = 5000000;
int pf[5000001];

int main() {
	pf[1] = 0;
	for (int i = 2; i <= 5000000; i++) {
		pf[i] = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				pf[i] = pf[i / j] + 1;
				break;
			}
		}
	}
	for(int i=1;i<=5000000;i++){
		pf[i]+=pf[i-1];
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", pf[a] - pf[b]);
	}

}
