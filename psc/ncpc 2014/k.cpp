#include <bits/stdc++.h>
using namespace std;

int main() {
	int C, n;
	cin >> C >> n;
	int x = 0;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		x -= a;
		if (x < 0) {
			cout << "impossible\n";
			exit(0);
		}
		x += b;
		if (x > C) {
			cout << "impossible\n";
			exit(0);
		}
		if (c != 0 && x != C) {
			cout << "impossible\n";
			exit(0);
		}
	}
	if (c != 0) {
		cout << "impossible\n";
		exit(0);
	}
	if (x == 0) {
		cout << "possible\n";
	} else {
		cout << "impossible\n";
	}
}
