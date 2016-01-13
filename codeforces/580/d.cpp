#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> dishes;
vector<vector<ll> > rules,dp;
ll n,m,k,ans=0;


ll f(ll mask, ll dish){
	if(dp[mask][dish]!=-1)return dp[mask][dish];
	if(__builtin_popcountll(mask)==m)return 0;
	ll t=0;
	for(ll i=0;i<n;i++){
		if((mask&(1<<i))==0){
			t=max(t,f(mask|(1<<i),i)+dishes[i]+rules[dish][i]);
		}
	}
	dp[mask][dish]=t;
	return t;
}

int main(){
	cin>>n>>m>>k;
	dishes.assign(n,0);
	rules.assign(n,vector<ll>(n,0));
	dp.assign(1<<n,vector<ll>(n,-1));
	for(ll i=0;i<n;i++){
		cin>>dishes[i];
	}
	for(ll i=0;i<k;i++){
		ll x,y,c;cin>>x>>y>>c;
		x--;y--;
		rules[x][y]=c;
	}
	for(ll i=0;i<n;i++){
		ans=max(ans,f(1<<i,i)+dishes[i]);
	}
	cout<<ans<<"\n";
}