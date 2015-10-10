#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	vector<ll> f(17, 0);
	f[0] = 1;
	for (int i = 1; i < 17; i++) {
		f[i] = i * f[i - 1];
	}
	int n, r;
	while (1) {
		cin >> n >> r;
		if (n == 0 && r == 0) {
			break;
		}
		vector<pair<int, int> > con1, con2;
		while (r--) {
			int a, b;
			cin >> a >> b;
			if (a <= n / 2) {
				con1.push_back(pair<int, int>(a, b));
			} else {
				con2.push_back(pair<int, int>(a, b));
			}
		}
		vector<int> c1, c2;
		for (int i = 0; i < n / 2; i++) {
			c1.push_back(i + 1);
			c2.push_back(i + 1 + n / 2);
		}
		ll ans = 0;
		for (auto a : con1) {
			if (find(c1.begin(), c1.end(), a.first)
					< find(c1.begin(), c1.end(), a.second)) {
				goto go;
			}

		}
		ans++;
		go: ;
		while (next_permutation(c1.begin(), c1.end())) {
			for (auto a : con1) {
				if (find(c1.begin(), c1.end(), a.first)
						< find(c1.begin(), c1.end(), a.second)) {
					goto bad;
				}

			}
			ans++;
			bad: ;
		}
		ll ans2=0;
		for (auto a : con2) {
			if (find(c2.begin(), c2.end(), a.first)
					< find(c2.begin(), c2.end(), a.second)) {
				goto justgo2;
			}
		}
		ans2++;
		justgo2: ;
		while (next_permutation(c2.begin(), c2.end())) {
			for (auto a : con2) {
				if (find(c2.begin(), c2.end(), a.first)
						< find(c2.begin(), c2.end(), a.second)) {
					goto bad2;
				}
			}
			ans2++;
			bad2: ;
		}
		ans *= ans2*f[n] / f[n / 2] / f[n / 2];
		cout << ans << "\n";
	}
}
