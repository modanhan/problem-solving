#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	int ans=1000000000;
	for (int i = 0; i < n; i++) {
		int t=v[i]+n-i;
		ans=min(ans,t);
	}
	cout<<(ans)<<"\n";
}
