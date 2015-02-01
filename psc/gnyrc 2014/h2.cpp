#include <bits/stdc++.h>
using namespace std;

typedef __uint128_t ll;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

void ughhhhh(int t,ll n) {
	ll a = 0, b = 1, c = 1, d = n;
	ll num = 0, de = 1;
	ll lastb = 1, currentb;
	while (c <= n) {
		ll k = ((n + b) / d);
		ll ta = a, tb = b;
		a = c;
		b = d;
		c = k * c - ta;
		d = k * d - tb;
		currentb = b;
		
		ll tn = lastb * lastb + currentb * currentb;
		ll td = lastb * currentb;
		
		num = num * td + de * tn;
		de *= td;

		ll g=gcd(num,de);
		num/=g;
		de/=g;

		lastb = currentb;
		if (b == a * 2) {
			break;
		}
	}
	cout << t<<" " << num << "/" << de << "\n";
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ll x;
		cin >> x;
		cin >> x;
		ughhhhh(t,x);
	}
}
