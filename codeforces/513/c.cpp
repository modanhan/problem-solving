#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector < pair<int, int> > v(n, pair<int, int>(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	vector < vector<pair<int, double> > > dp(n, vector<pair<int, double> >());
	for (int i = v[0].second; i <= v[0].first; i++) {
		pair<int, double> p(i, 1 / (v[0].first - v[0].second+1));
		dp[0].push_back(p);
	}
	for (int i = 1; i < n; i++) {
		for (int j = v[i].second; j <= v[i].first; j++) {
			pair<int, double> p(0,0);
			for (int t=v[i-1].second;t<=v[i-1].first;t++) {
				if (j > t) {
					p.first = t;
					p.second = (double)1 / (double)(v[i].first - v[i].second+1);
				} else {
					p.first = j;
					p.second = dp[i-1][t-v[i-1].second].second;
					p.second/=(double)(v[i].first - v[i].second+1);
				}
			}
			dp[i].push_back(p);
		}
	}
	
	for(int i=0;i<n;i++){
		for(auto p:dp[i]){
			cout<<p.first<<" "<<p.second<<"\t";
		}cout<<"\n";
	}
	double ans=0;
	for(auto p:dp[n-1]){
		ans+=p.first*p.second;
	}
	cout<<ans<<"\n";
}
