#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll n) {
	ll ans = n;
	for (ll p = 2; p*p <= n; p++) {
		if (n%p == 0) {
			ans /= p;
			ans *= (p - 1);
			while (n%p == 0)n /= p;
		}
	}
	if (n>1) {
		ans /= n; ans *= (n - 1);
	}
	return ans;
}

ll exp(ll n, ll e, ll m) {
	if (e == 0)return 1;
	ll y = 1;
	while (e>1) {
		if (e % 2) { y *= n; y %= m; }
		n *= n; n %= m;
		e >>= 1;
	}
	return (n*y) % m;
}

ll f(ll n, ll m) {//cout<<n<<' '<<m<<endl;
	if (n == 1)return 1%m;
	if(n==2)return 2%m;
	if(n==3)return 9%m;
	if(n==4)return exp(4,9,m);
	if(n==5)return exp(5,f(4,phi(m)),m);
	if (m == 1)return 0;
	ll e = f(n - 1, phi(m));
	return exp(n, e, m);
}

int main() {//cout<<phi(123456789)<<endl;
	ll n, m;
	cin >> n >> m;
	cout << f(n, m) << endl;
}
