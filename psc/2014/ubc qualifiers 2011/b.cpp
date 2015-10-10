#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 1) {
		vector<int> v(n, 0), maxl(n, 0), minl(n, 0), maxr(n, 0), minr(n, 0);

		int maxx = 0, minn = 3000000;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] > maxx) {
				maxx = v[i];
			}
			maxl[i] = maxx;
			if (v[i] < minn) {
				minn = v[i];
			}
			minl[i] = minn;
		}
		maxx = 0;
		minn = 3000000;
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] > maxx) {
				maxx = v[i];
			}
			maxr[i] = maxx;
			if (v[i] < minn) {
				minn = v[i];
			}
			minr[i] = minn;
		}

	/*	for (int i : maxl) {
			cout << i<<"\t";
		}
		cout << "\n";
		for (int i : minl) {
			cout << i<<"\t";
		}
		cout << "\n";
		for (int i : maxr) {
			cout << i<<"\t";
		}
		cout << "\n";
		for (int i : minr) {
			cout << i<<"\t";
		}
		cout << "\n";*/
		
		int minb = 3000000;
		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			if (max(maxl[i] - minl[i], maxr[i+1] - minr[i+1]) < minb) {
				minb = max(maxl[i] - maxr[i], maxr[i+1] - minr[i+1]);
			//	cout << minb <<"\t"<<i<< "\n";
				ans = i;
			}
		}
		cout << ans+1 << "\n";
		cin >> n;
	}

}
