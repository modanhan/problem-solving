#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		int n;
		double mm;
		cin >> n >> mm;
		int m = (int) (mm * 100);
		if (n == 0 && m == 0)
			break;
		vector<pair<int,int> > v(n);
		vector<int> dp(m+1,0);
		for(int i=0;i<n;i++){
			int c;double pp;
			cin>>c>>pp;
			int p=(int)(pp*100);
			v[i].first=c;
			v[i].second=p;
		}
		for(int i=0;i<=m;i++){
			for(int j=0;j<n;j++){
				if(i>=v[j].second){
					dp[i]=max(dp[i],dp[i-v[j].second]+v[j].first);
				}
			}
		}
		cout<<dp.back()<<"\n";
	}
}
