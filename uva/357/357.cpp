#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll coins[5]={1,5,10,25,50};
	vector<vector<ll> > dp(5,vector<ll>(40000,0));
	for(ll i=0;i<5;i++){
		dp[i][0]=1;
	}
	for(ll i=0;i<35000;i++){
		dp[0][i]=1;
	}
	for(ll i=1;i<5;i++){
			for(ll j=1;j<35000;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=coins[i]){
					dp[i][j]+=dp[i][j-coins[i]];
				}
			}
		}
	ll x;
	while(cin>>x){
		if(dp.back()[x]!=1){
			cout<<"There are "<<dp.back()[x]<<" ways to produce "<<x<<" cents change.\n";
		}else{
			cout<<"There is only 1 way to produce "<<x<<" cents change.\n";
		}
	}
}

