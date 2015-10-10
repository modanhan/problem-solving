#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	//modulo d with m coin=dp[d][m]
	ll c=1;while(++c){
		ll n,q;cin>>n>>q;
		if(n==0&&q==0){
			break;
		}
		vector<ll> v(n,0);
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}
		for(ll t=1;t<=q;t++){
			ll d,m;cin>>d>>m;
			vector<vector<ll> > dp(d,vector<ll>(n+1,0));
			dp[0][0]=1;
			for(int i=0;i<n;i++){
				for(int j=n;j>=0;j--){
					for(int k=d-1;k>=0;k--){
						if(dp[k][j]){
							// ok this is very wrong
							// i might be incrementing single element multiple times
							// doesnt explain why my output is actually less tho..
							dp[(k+v[i])%d][j+1]++;
						}
					}
				}
			}
			for(int i=0;i<d;i++){
				for(int j=0;j<=n;j++){
					cout<<dp[i][j];
				}cout<<"\n";
			}
			cout<<dp[0][m]<<"\n";
		}
	}
}