#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll t;cin>>t;
	while(t--){
		ll n,m=1;cin>>n;
		vector<ll> v(n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];
			m+=v[i];
		}
		vector<bool> dp(m,0);
		dp[0]=1;
		for(int i=0;i<n;i++){
			for(int j=m-1;j>=0;j--){
				if(dp[j]){
					dp[j+v[i]]=1;
				}
			}
		}
		for(int diff=0;diff<=m/2;diff++){
			if(dp[m/2-diff]||dp[m/2+diff]){
				cout<<diff*2+1-m%2<<"\n";
				break;
			}
		}
	}
}