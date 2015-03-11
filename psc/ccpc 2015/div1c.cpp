#include <bits/stdc++.h>
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
		vector<string> ans(n, "");
		queue<ll> q;
		if (s.size()==1&&s[0]==0) {
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
				v[0] = t;
				ans[0] = ans[t];
				goto good;
			}
			for (int nb : s) {
				ll m = (t * 16 + nb) % n;
				if (m == 0){
					ans[0] = ans[t] + hexc(nb);
					goto good;
				}
				if (v[m] == 0) {
					ans[m] =ans[t]+ hexc(nb);
					v[m] = 1;
					q.push(m);
				}
			}
		}
		if (v[0] == 0){
			cout << "no solution\n";
		}
		else{
		good: cout <<ans[0] << "\n";
		}
	}
}
