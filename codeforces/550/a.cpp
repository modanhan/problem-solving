#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	if (s.size() < 4) {
		cout << "NO\n";
		return 0;
	}
	bool ab = 0, ba = 0, x = 1;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B') {
			if (!x) {
				x = 1;
			}else{

			ab = 1;
			if (i + 2 < s.size() && s[i + 2] == 'A') {
				ba = 1;
				i+=2;
				x = 0;
			}}
		} else if (s[i] == 'B' && s[i + 1] == 'A') {
			if (!x) {
				x = 1;
			}else{
			ba = 1;
			if (i + 2 < s.size() && s[i + 2] == 'B') {
				ab = 1;
				i+=2;
				x = 0;
			}}
		}
		if (ab && ba && x) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}
