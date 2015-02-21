#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	vector<ll> v(7, 0);
	v[1] = 1;
	v[2] = 8;
	v[3] = 30;//!ok
	v[4] = 68;//!
	v[5] = 75;//!
	v[6] = 30;
	vector < vector<ll> > choose(7, vector < ll > (1100, 0));
	for (int i = 0; i < 1100; i++) {
		choose[0][i] = 1;
	}
	for (int j = 1; j < 7; j++) {
		for (int i = j; i < 1100; i++) {

			choose[j][i] = choose[j - 1][i - 1] + choose[j][i - 1];
		}
	}
	ll n;
	cin >> n;
	while (n != 0) {
		ll ans = 0;
		for (int i = 1; i < 7; i++) {
			ans += choose[i][n] * v[i];
		}
		cout << ans << "\n";
		cin >> n;
	}
}
