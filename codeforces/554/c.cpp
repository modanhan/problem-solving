#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int main(){
	ll k;cin>>k;
	vector<ll> v(k,0);
	ll n=0;
	for(ll i=0;i<k;i++){
		cin>>v[i];
		n+=v[i];
	}
	ll t=v[0];
	vector<ll> dp(n,0);
	for(ll x=0;x<v[0];x++){
		dp[x]=1;
	}
	for(ll i=1;i<k;i++){
		dp[t]=dp[t-1];
		t++;ll c=t;
		for(ll x=1;x<v[i];x++){
			dp[t]=c*dp[t-1]%MOD;
			t++;
		}
	}
	for(int x:dp){
		cout<<x<<"\t";
	}cout<<"\n";
	cout<<dp.back()<<"\n";
}