#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll x, c[5] = { 1, 5, 10, 25, 50 };
	vector<ll> dp(30001, 0);
	dp[0] = 1;
	for (int i = 0; i < 5; i++) {
		for (int m = 0; m < 30001; m++) {
			if (m >= c[i]) {
				dp[m] += dp[m - c[i]];
			}
		}
	}
	while (cin >> x) {
		if (dp[x] == 1) {
			cout << "There is only 1 way to produce " << x
					<< " cents change.\n";
		} else {
			cout << "There are " << dp[x] << " ways to produce " << x
					<< " cents change.\n";
		}

	}
}
