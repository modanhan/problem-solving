#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c1, c2, x, y;

bool f(ll n) {
	if (n - n / x < c1)
		return 0;
	if (n - n / y < c2)
		return 0;
	return c1 + c2 <= n - n / (x * y);
}

int main() {
	cin >> c1 >> c2 >> x >> y;
	ll l = 0, u = 9999999999999999, m;
	for (int i = 0; i < 500; i++) {
		m = (l + u) / 2;
		if (f(m)) {
			u = m;
		} else {
			l = m;
		}
	}
	if (!f(m))
		m++;
	cout << m;
}
