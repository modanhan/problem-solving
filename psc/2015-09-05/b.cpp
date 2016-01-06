#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	while (n--) {
		int l;
		cin >> l;
		vector<int> v(l);
		for (int i = 0; i < l; i++) {
			cin >> v[i];
		}
		for (int i = 1; i < l; i++) {
			if (v[i] < v[i - 1] * 2) {
				goto bad;
			}
		}

		cout << "Denominations: ";
		for (int i = 0; i < l; i++) {
			cout << v[i]<<" ";
		}
		cout << "\nGood coin denominations!\n\n";
		continue;

		bad: cout << "Denominations: ";
		for (int i = 0; i < l; i++) {
			cout << v[i]<<" ";
		}
		cout << "\nBad coin denominations!\n\n";
	}
}
