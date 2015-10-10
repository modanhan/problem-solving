#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first * b.second < b.first * a.second;
	}
};

set<pair<int, int>, cmp> s;
vector<ll> bigfkingints(10002, 0);

int main() {
	s.insert(pair<int, int>(0, 1));
	bigfkingints[1] = 1;
	for (int i = 2; i < 10000; i++) {
		for (int cp = 1; cp < i / 2 + 1; cp++) {
			if (gcd(cp, i) == 1) {
				s.insert(pair<int, int>(cp, i));
			}
		}
		ll n = 0, d = 1;
	/*	for (auto it = s.begin(); it != (s.end()); it++) {
			int tn = it->second;
			it++;
			if (it == s.end()) {
				break;
			}
			ll td = it->second;
			it--;
			ll an = tn * tn + td * td;
			ll ad = td * tn;
			n = n * ad + d * an;
			d *= ad;
			ll g = gcd(n, d);
			n /= g;
			d /= g;
		}*/
		bigfkingints[i] = n;
	}
	cout << "done";
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int ugh;
		cin >> ugh;
		int x;
		cin >> x;
		/*	ll n = 0, d = 1;
		 for (auto it = v[x].begin(); it != (v[x].end()); it++) {
		 int tn = it->second;
		 it++;
		 if (it == v[x].end()) {
		 break;
		 }
		 ll td = it->second;
		 it--;
		 ll an = tn * tn + td * td;
		 ll ad = td * tn;
		 //	cout<<an<<"/"<<ad<<"\n";
		 n = n * ad + d * an;
		 d *= ad;
		 ll g = gcd(n, d);
		 n /= g;
		 d /= g;
		 }*/
		cout << bigfkingints[x] << "/2\n";
	}
}
