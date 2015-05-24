#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> order(n, 0);
	for (int i = 0; i < n; i++) {
		cin>>order[i];
	}
	int t;
	while (cin >> t) {
		int ans=1;
		vector<int> v(n, 0), lis(n, 1);
		v[t-1] = 0;
		for (int i = 1; i < n; i++) {
			cin>>t;
			v[t-1]=i;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (order[v[j]] < order[v[i]]) {
					lis[i] = max(lis[i], lis[j] + 1);
				}
			}
			ans=max(ans,lis[i]);
		}

		cout << ans << "\n";
	}
}
