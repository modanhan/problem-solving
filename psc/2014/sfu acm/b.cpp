#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v(500, 0);
	v[1] = 2;
	v[2] = 4;
	v[3] = 6;
	v[4] = 7;
	for (int i = 5; i < 500; i++) {
		v[i] = i * 2;
	}
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		cout << v[n] << "\n";
	}
}
