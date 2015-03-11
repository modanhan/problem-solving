#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll tc;
	cin >> tc;
	while (tc--) {
		ll n, d;
		cin >> n >> d;
		vector<int> s(d, 0);
		for (int i = 0; i < d; i++) {
			char x;cin>>x;
			if(x>='0'&&x<='9'){
				s[i]=x-48;
			}else{
				s[i]=x-87;
			}
		}
		vector<ll> v(n, 0);
		queue<ll> q;
		if (s[0] != 0) {
			q.push(s[0]);
			v[s[0]] = s[0];
		} else if (s.size() >= 2) {
			q.push(s[1]);
			v[s[1]] = s[1];
		} else {
			cout << "no solution\n";
			continue;
		}
		while (!q.empty()) {
			ll t = q.front();
			q.pop();
			if(t%n==0){
				v[0]=t;
				goto good;
			}
			for (ll nb : s) {
				ll m = (t * 16 + nb) % n;
				if(m==0){
					v[0]=(t*16+nb);
					goto good;
				}
				if (v[m] == 0) {
					v[m] = t*16+nb;
					q.push(t * 16 + nb);
				}
			}
		}
		if(v[0]==0){
		cout << "no solution\n";
		}else{
		good: cout<<hex << v[0] << "\n";}
	}
}
