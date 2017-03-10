#include <bits/stdc++.h>
using namespace std;

bool special = 0;

bool b(string& s) {
	if (s[0] != '1') {
		if (s[0] == '0')
			special = 1;
		return 0;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != '0')
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	string nb = "1";
	int l = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (!b(s)) {
			nb = s;
		} else {
			l += s.size() - 1;
		}
	}
	if (special) {
		cout << 0;
		return 0;
	}
	cout << nb;
	for (int i = 0; i < l; i++)
		cout << '0';

}
