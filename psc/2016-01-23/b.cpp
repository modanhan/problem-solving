#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//dp[i][j]=#of ways using i single steps to go up j stairs
vector<vector<ll> > dp(5001,vector<ll>(5001,0));
int main(){
	for(int i=2;i<5001;i+=2)dp[0][i]=1;
	for(int i=1;i<5001;i++)dp[i][i]=1;
	
	for(int i=2;i<5001;i++){
		for(int j=1;j<i;j++){
			dp[j][i]+=dp[j-1][i-1]+dp[j][i-2];
		}
	}

/*	for(int j=0;j<7;j++){
	for(int i=0;i<7;i++){
		
			cout<<dp[j][i]<<" ";
		}cout<<endl;
	}
	return 0;*/
	
	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
		ll asdf, n;cin>>asdf>>n;
		n/=2;
		ll ans=0;
		for(int i=0;i<n;i++){
			if((n-i)/2<i)break;
			ans+=dp[i][n]*dp[i][n];
		}
		cout<<asdf<<' '<<ans<<endl;
	}
}