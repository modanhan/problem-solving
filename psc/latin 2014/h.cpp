#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<bool> v(24, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x += 11;
		v[x] = !v[x];
	}
	vector<int> c;
	for (int i = 0; i < 24; i++) {
		if (v[i]) {
			c.push_back(i);
		}
	}
	
	if(c.empty()){
		cout<<"0\n";
		return 0;
	}
	
	int tr = 0;
	for (int i = 0; i < c.size(); i += 2) {
		tr += min(c[i + 1] - c[i], 24 - (c[i + 1] - c[i]));
	}
	int tl = min(abs(c[0] - *(c.end() - 1)), 24 - abs(c[0] - *(c.end() - 1)));
	for (int i = 1; i < c.size() - 1; i += 2) {
		tl += min(abs(c[i] - c[i + 1]), 24 - abs(c[i] - c[i + 1]));
	}
	cout << (tr < tl ? tr : tl) << '\n';
}
