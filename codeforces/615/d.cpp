#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mod 1000000007

ll exp(ll b, ll e) {
	if (e == 0)
		return 1;
	if (e == 1)
		return b;
	if (e % 2)
		return (b * exp((b * b) % mod, e >> 1)) % mod;
	else
		return exp((b * b) % mod, e >> 1) % mod;
}

ll n;
vector<ll> v;
map<ll, ll> m;
ll nd = 1;
int main() {
	cin >> n;
	v.assign(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
		if (m.count(v[i])) {
			m[v[i]]++;
		} else {
			m[v[i]] = 2;
		}
	}
	for (auto p : m) {
//		cout<<p.first<<" "<<p.second<<"\n";
		nd *= p.second;
		nd &= 1;
	}
	ll ans = 1;
	if (nd) {
		for (auto p : m) {
			ans *= exp(p.first, p.second >> 1);
			ans %= mod;
		}
		for (auto p : m) {
			ans = exp(ans, p.second);
		}
	} else {
		for (auto p : m) {
			ans *= exp(p.first, p.second-1);
			ans %= mod;
		}
		bool dived = 0;
		for (auto p : m) {
			if ((p.second%2 == 0)&&!dived) {
				dived = 1;
				ans = exp(ans, p.second / 2);
			} else
				ans = exp(ans, p.second);
		}
	}
	cout << ans % mod;

}
