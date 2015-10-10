#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//i fucking give up idk when i can make it and when i cant
//my condition is fucked up
bool can(vector<ll> v, ll l, ll k) {
	auto it = v.begin();
	for (int i = 0; i < k; i++) {
		it = upper_bound(v.begin(), v.end(), *it + l);
	}
	if (it == v.end()) {
		return true;
	} else {
		if ((*it+l>999999)&&upper_bound(v.begin(), v.end(), (*it + l) % 999999)
				>= upper_bound(v.begin(), v.end(), *v.begin() + l)){
			return true;
		}
			return false;
	}
}

int main() {
	ll n;
	cin >> n;
	vector<ll> v(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll k;
	cin >> k;

	if (n <= k) {
		cout << "0\n";
		return 0;
	}
	

	ll hi = 1000000, lo = 0, mid = 500000;
	while (hi != lo) {
	//	cout << mid << "\n";
		if (can(v, mid, k)) {
			if (!can(v, mid - 1, k)) {
				break;
			}
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
		mid = (hi + lo) / 2 + 1;
	}
	if (mid & 1) {
		cout << mid / 2 + 1 << "\n";
	} else {
		cout << mid / 2 << "\n";
	}
}
