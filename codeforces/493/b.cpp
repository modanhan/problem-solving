#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> f;
	vector<ll> s;
	ll fs = 0, ss = 0;
	bool flast = true;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x > 0) {
			f.push_back(x);
			fs += x;
			flast = true;
		} else {
			s.push_back(-x);
			ss -= x;
			flast = false;
		}
	}
	if (fs > ss) {
		cout << "first\n";
	} else if (ss > fs) {
		cout << "second\n";
	} else {
		if (f > s) {
			cout << "first\n";
		} else if (s > f) {
			cout << "second\n";
		} else {
			if (flast) {
				cout << "first\n";
			} else {
				cout << "second\n";
			}
		}
	}

}
