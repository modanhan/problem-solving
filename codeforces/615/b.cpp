#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<vector<ll> > v;
vector<ll> tail;
int main() {
	cin >> n >> m;
	v.assign(n, vector<ll>());
	tail.assign(n, 1);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++) {
		for (ll nb : v[i]) {
			if (nb < i) {
				tail[i] = max(tail[i], tail[nb] + 1);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, tail[i] * (ll) v[i].size());
	}
	cout << ans;
}
