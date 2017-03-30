#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

ll a,n,m;

ll exp(ll x, ll e){
	if(e==0)return 1;
	ll y=1;
	while(e>1){
		if(e%2){y*=x;x*=x;e>>=1;}
		else {x*=x;e>>=1;}
		y%=m;x%=m;
	}
	return (x*y)%m;
}

ll calc(ll e){
	if(e==1)return 1;
	ll t=calc(e>>1);
	ll ans=(t+t*exp(a,e>>1)%m)%m;
	if(e%2){
		ans+=exp(a,e-1);
	}
	//cout<<e<<' '<<t<<' '<<t*exp(a,e>>1)<<' '<<ans<<endl;
	return ans%m;
}

int main(){
	unsigned long long asdfa,asdfn,asdfm;
	cin>>asdfa>>asdfn>>asdfm;
	a=asdfa;n=asdfn;m=asdfm;
	a%=m;
	unsigned long long asdfans=calc(n+1)%m;
	cout<<asdfans<<'\n';
}
