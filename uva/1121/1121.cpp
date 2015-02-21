#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, s;
	while (cin >> n >> s) {
		vector<ll> v(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
		}
		ll bi = 0, ei = 1, sum = v[0], ans = 1000025;
		while (ei != n || bi != n) {
			if (ei == n) {
				sum -= v[bi];
				bi++;
			} else if (sum >= s) {
				sum -= v[bi];
				bi++;
			} else {
				sum += v[ei];
				ei++;
			}
			if (sum >= s) {
				ans = min(ans, ei - bi);
			}
		//	cout << sum << "\t" << ans << "\n";
		}
		if (ans == 1000025) {
			cout << "0\n";
		} else {
			cout << ans << '\n';
		}
	}
}
