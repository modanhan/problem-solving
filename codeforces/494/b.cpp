#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll x, y;
	cin >> x >> y;

	if (y > x) {
		cout << "0\n";
		return 0;
	}
	if (x == y) {
		cout << "infinity\n";
		return 0;
	}

	x -= y;
	ll ans = 0;
	for (ll i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) {
			if (x / i > y) {
				ans++;
			}
			if (i!=x/i&&i > y) {
				ans++;
			}
		}
	}
	cout << ans<<"\n";

}
