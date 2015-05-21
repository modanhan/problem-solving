#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> c(1000003, 0);
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		c[x]++;
	}
	for (ll i = 1000003; i >= 1; i--) {
		if (c[i] % 2) {
			c[i]--;
			if (c[i - 1] != 0) {
				c[i - 1]++;
			}
		}
	}

	ll last = 0, ans = 0;
	for (ll i = 1000003; i >= 1; i--) {
		if (c[i] != 0) {
			if (last != 0) {
				if(c[i]%4==0){
					ans+=last*i;
					ans+=i*i*((c[i]-2)/4);
					last=i;
				}else{
					ans+=last*i;
					ans+=i*i*((c[i]-2)/4);
					last=0;
				}
			} else {
				ans+=i*i*(c[i]/4);
				if (c[i] % 4==0) {
				}else{
					last=i;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
