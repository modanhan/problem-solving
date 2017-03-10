#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v, c(1000002,0);
int main() {
	scanf("%d %d", &n, &k);
	v.assign(n+1, 0);
	v[n]=1000001;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int b = 0, e = 0, maxb = 0, maxe = 0, max = 0, d = 0;
	while (e <= n) {
		while (d > k) {
			c[v[b]]--;
			if (c[v[b]] == 0) {
				d--;
			}
			b++;
		}
		if (e - b > max) {
			max = e - b;
			maxb = b;
			maxe = e;
		}
		if (c[v[e]] == 0) {
			d++;
		}
		c[v[e]]++;
		e++;
	}
	cout << maxb + 1 << ' ' << maxe;
}
