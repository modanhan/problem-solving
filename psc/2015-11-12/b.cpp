// bad bad bad bad bad

// https://open.kattis.com/problems/indoorienteering

#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<int> > v;
vector<vector<set<int> > > dp; //dp[mask] returns set of possible ls

set<int> f(int mask, int last, int start) { //last is in mask
	if (!dp[mask][last].empty()) {
		return dp[mask][last];
	}
	if (__builtin_popcount(mask) == 1) { //been nowhere
		dp[mask][last].insert(v[start][last]);
		return dp[mask][last];
	}
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) && i != last) { //been to i
			for (int x : f(mask ^ (1 << last), i,start)) { //turn off i, last is i
				dp[mask][last].insert(x + v[last][i]);
			}
		}
	}
	return dp[mask][last];
}

int main() {
	cin >> n >> l;
	v.assign(n, vector<int>(n, 0));
	dp.assign(1 << n,vector<set<int> >(n, set<int>()));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	bool ans = 0;
	for (int i = 0; i < n; i++) {
		set<int> s = f((1 << n)-1, i,i);
		ans |= find(s.begin(), s.end(), l) == s.end() ? 0 : 1;
	}
	for(int i=0;i<(1<<n);i++){
		cout<<bitset<4>(i)<<"\n";
		for(int last=0;last<n;last++){cout<<"\t"<<last<<"\t";
			for(int x:dp[i][last])cout<<x<<" ";cout<<"\n";}
		cout<<"\n";
	}
	cout << (ans ? "possible\n" : "impossible\n");
}
