#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
//	cout<<(12|18);
	ll n,k,x;cin>>n>>k>>x;
	vector<ll> v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
	}
	ll e=1,ans=0;while(k--)e*=x;
	if(n==1){
		cout<<e*v[0];
		return 0;
	}
	vector<ll> f(n),b(n);
	f[0]=v[0];
	b[n-1]=v[n-1];
	for(int i=1;i<n;i++){
		f[i]=v[i]|f[i-1];
	}
	for(int i=n-2;i>=0;i--){
		b[i]=v[i]|b[i+1];
	}
//	cout<<e<<"\n";
	ans=max((v[0]*e)|b[1],(v.back()*e)|f[n-2]);
//	cout<<ans;
	for(ll i=1;i<n-1;i++){
		ll t=e*v[i];
		t|=f[i-1]|b[i+1];
		ans=max(ans,t);
	}
	cout<<ans;
	
}