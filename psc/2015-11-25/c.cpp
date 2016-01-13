#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int m,n;cin>>m>>n;
		vector<int> coins(n,0);
		for(int i=0;i<n;i++){
			cin>>coins[i];
		}
		vector<int> dp(40000,123456);
		dp[0]=0;
		dp[coins[0]]=1;
		for(int i=1;i<n;i++){
			for(int j=29999;j>=0;j--){
				if(dp[j]!=123456){
					dp[j+coins[i]]=min(dp[j+coins[i]],dp[j]+1);
				}
			}
		}
		for(int i=m;i<40000;i++){
			if(dp[i]!=123456){cout<<i<<" "<<dp[i]<<"\n";
			break;}
		}
	}
}