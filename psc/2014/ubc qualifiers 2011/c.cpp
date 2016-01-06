#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll s;
	cin >> s;
	do {
		//n^2+n-2s=0
		ll q = ceil((1 + sqrt(1 + 8 * s)) / 2);
		ll a = q * (q - 1) / 2;
		if (a - s == 0) {
			cout << "Not bored enough!\n";
		} else {
			cout << (a - s) << "\n";
		}
		cin >> s;
	} while (s != 0);
}
