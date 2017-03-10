#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	string s;cin>>s;
	ll n=s.size();
	vector<vector<ll> > dp(4,vector<ll>(n,0));
	
	dp[(s[0]-'0')%4][0]++;
	//dp[m][i]= # of substrings ending at i that's m mod 4
	for(int i=1;i<n;i++){
		ll x=(s[i]-'0')%4;
		dp[x][i]++;
		for(int m=0;m<4;m++){
			ll t=(m*10+x)%4;
			dp[t][i]+=dp[m][i-1];
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=dp[0][i];
	}
	cout<<ans<<endl;
}