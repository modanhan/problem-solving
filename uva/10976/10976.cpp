#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	while (cin >> k) {
		int ans = 0;
		for (int x = k + 1; x <= k * 2; x++) {
			if ((x * k) % (x - k) == 0) {
				ans++;
			}
		}
		cout << ans << "\n";
		for (int x = k + 1; x <= k * 2; x++) {
			if ((x * k) % (x - k) == 0) {
				int y = (x * k) / (x - k);
				cout << "1/" << k << " = 1/" << y << " + 1/" << x << "\n";
			}
		}
	}

}

