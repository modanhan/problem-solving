#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> v(n, 0);
	for (ll i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	m--;
	for (ll i = 0; i < m; i++) {
		next_permutation(v.begin(), v.end());
	}
	for (ll i : v) {
		cout << (i) << " ";
	}
	cout << "\n";
}
