#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m=1000000007;

ll n,w,h;

//dp[r][c]=#of ways when r ribbon left and at c-th column
vector<vector<ll> > dp;
ll f(ll r, ll c){
	if(c==w)return 1;

	ll& ans=dp[r][c];
	if(ans!=-1)return ans;
	
	ans=0;
	for(ll i=0;i<=h;i++){
		if(r-i<0)break;
		ans+=f(r-i,c+1);
		ans%=m;
	}
	return ans;
}

int main(){
	cin>>n>>w>>h;
	dp.assign(n+1,vector<ll>(w,-1));
	ll x=min(n,h*w)/w+1;
	cout<<(f(n,0)-x+m)%m<<endl;
}

