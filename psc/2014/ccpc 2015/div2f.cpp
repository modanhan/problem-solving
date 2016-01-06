#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(6, 0);
		for (int i = 0; i < 6; i++) {
			cin >> v[i];
		}
		int p = 0;
		int d = 0;
		int ans=0;
		while (p < n) {
			p += v[d];
			
			if (p > n) {
				p -= v[d];
			}else{
				ans+=p;
				}
			
			d++;
			d %= 6;
		}
		cout<<ans<<"\n";
	}
}
