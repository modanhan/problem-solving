#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll x,c[5]={1,5,10,25,50};
	vector<vector<ll> > dp(30001,vector<ll>(5,1));
	for(int i=1;i<5;i++){
		for(int m=0;m<30001;m++){
			dp[m][i]=dp[m][i-1];
			ll t=m-c[i];
			while(t>=0){
				dp[m][i]+=dp[t][i-1];
				t-=c[i];
			}
		}
	}
	while(cin>>x){
		if(dp[x][4]==1){
			cout<<"There is only 1 way to produce "<<x<<" cents change.\n";
		}else{
			cout<<"There are "<<dp[x][4]<<" ways to produce "<<x<<" cents change.\n";
		}
			
	}
}
