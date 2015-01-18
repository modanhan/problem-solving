#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int blah;
		cin >> blah;
		vector<int> v(12, 0);
		for (int i = 0; i < 12; i++) {
			cin >> v[i];
	//		cout<<v[i]<<" ";
		}
	//	cout<<"\n";
		int ans = 0;
		for (int i = 1; i < 11; i++) {
			for (int j = i ; j < 11; j++) {
				int minn = 1234;
				for (int ugh = i; ugh <= j; ugh++) {
					minn = min(minn, v[ugh]);
				}
				if (minn > v[i - 1] && minn > v[j + 1]) {
					ans++;
				//	for (int ugh = i; ugh <= j; ugh++) {
				//		cout<<v[ugh]<<" ";
				//	}
				//	cout<<"\n";
				}
			}
		}
		cout << t << " " << ans << "\n";
	}
}
