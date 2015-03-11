//#include <bits/stdc++.h>

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;

char hexc(int i){
	if (i <= 9){
		return i + 48;
	}
	else{
		return i + 87;
	}
}

int main() {
	ll tc;
	cin >> tc;
	while (tc--) {
		ll n, d;
		cin >> n >> d;
		vector<int> s(d, 0);
		for (int i = 0; i < d; i++) {
			char x; cin >> x;
			if (x >= '0'&&x <= '9'){
				s[i] = x - 48;
			}
			else{
				s[i] = x - 87;
			}
		}
		vector<bool> v(n, 0);
		vector<char> ans(n, 0);
		vector<int> par(n, -1);
		queue<ll> q;
		if (s.size() == 1 && s[0] == 0) {
			cout << "no solution\n";
			continue;
		}
		else {
			for (int i : s){
				if (i != 0){
					q.push(i);
					v[i] = 1;
					ans[i] = hexc(i);
				}
			}
		}
		while (!q.empty()) {
			ll t = q.front();
			q.pop();
			if (t%n == 0){
				ans[0] = ans[t];
				goto good;
			}
			for (int nb : s) {
				ll m = (t * 16 + nb) % n;
				if (m == 0){
					ans[0] = hexc(nb);
					par[0] = t;
					goto good;
				}
				if (v[m] == 0) {
					ans[m] = hexc(nb);
					par[m] = t;
					v[m] = 1;
					q.push(m);
				}
			}
		}
		cout << "no solution\n";
		continue;

	good:{
		vector<char> fin;
		int ind = 0;
		while (ind != -1){
			fin.push_back(ans[ind]);
			ind = par[ind];
		}
		for (int i = fin.size() - 1; i >= 0; i--){
			cout << fin[i];
		}
		cout << "\n";
	}
	}
}
