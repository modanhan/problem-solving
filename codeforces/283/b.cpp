#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s, m;
	cin >> n >> s;
	m = s;
	for (int i = 0; i < n; i++) {
		char l = s[n - 1];
		for (int j = n - 1; j > 0; j--) {
			s[j] = s[j - 1];
		}
		s[0] = l;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < n; k++) {
				s[k]++;
				if (s[k] == ':') {
					s[k] = '0';
				}
			}
			m = min(m, s);
		}
		for (int k = 0; k < n; k++) {
			s[k]++;
			if (s[k] == ':') {
				s[k] = '0';
			}
		}

	}
	cout << m << "\n";
}
