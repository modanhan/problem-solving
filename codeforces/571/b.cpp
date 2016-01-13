#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
vector<ll> v,ps;
vector<vector<ll> > dp;

// a=# of n/k, b=# of n/k+1
int f(ll a,ll b){
	if(dp[a][b]!=-1)return dp[a][b];
	ll i=a*(n/k)+b*(1+n/k);
	if(i==0)return 0;
	i=n-i;
	ll t=LLONG_MAX;
	if(b!=0){
		t=min(t,f(a,b-1)+ps[i+n/k]-ps[i]);
	}
	if(a!=0){
		t=min(t,f(a-1,b)+ps[i+n/k-1]-ps[i]);
	}
//	t= min(f(a-1,b)+ps[i+n/k]-ps[i],f(a,b-1)+ps[i+n/k+1]-ps[i]);
	dp[a][b]=t;
//	cout<<"dp["<<a<<"]["<<b<<"]\t=\t"<<t<<"\n";
	return t;
}

int main(){
	cin>>n>>k;
	v.assign(n,0);
	ps.assign(n,0);
	ll m=n%k;
	dp.assign(k-m+1,vector<ll>(m+1,-1));
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ps[0]=0;
	for(int i=1;i<n;i++){
		ps[i]=abs(v[i]-v[i-1])+ps[i-1];
	}
	
	cout<<f(k-m,m);
}