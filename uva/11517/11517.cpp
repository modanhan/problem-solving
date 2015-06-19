#include <bits/stdc++.h>
using namespace std;

#define inf 123489273

int main() {
	int t;
	cin >> t;
	while (t--) {
		int p, n;
		cin >> p >> n;
		vector<int> c(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		if (p == 0) {
			cout << "0 0\n";
			continue;
		}
		vector<int> dp(30001,inf);
		dp[0]=0;
		for(int i=0;i<n;i++){
			for(int v=30001-c[i]-1;v>=0;v--){
				if(dp[v]!=inf){
					dp[v+c[i]]=min(dp[v+c[i]],dp[v]+1);
				}
			}
		}
		int ans=p;
		while(dp[ans]==inf){
			ans++;
		}
		cout<<ans<<" "<<dp[ans]<<"\n";
	}
}
