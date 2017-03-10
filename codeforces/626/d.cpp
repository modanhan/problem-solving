#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;cin>>n;
	ll tw=n*(n-1)/2;
	tw*=tw*tw;
	vector<ll> v(n,0),pd(13000,0),pref(13000,0);
	for(ll i=0;i<n;i++){cin>>v[i];}
	sort(v.begin(),v.end());
	for(ll i=0;i<n;i++){
		for(ll j=0;j<i;j++){
			pd[v[i]-v[j]]++;
		}
	}
	
	for(ll i=10500;i>0;i--){
		pref[i]=pref[i+1]+pd[i];
	}
	
	ll answ=0;
	for(ll r1=1;r1<6000;r1++){
		for(ll r2=1;r2<6000;r2++){
			answ+=pd[r1]*pd[r2]*pref[r1+r2+1];
		}
	}
	double ans=(double)answ/tw;
	printf("%.10f\n",ans);

	//pref[i] = # of ways to win with at least i points

}