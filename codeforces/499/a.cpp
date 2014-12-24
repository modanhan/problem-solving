#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll n,x;cin>>n>>x;
	vector<pair<ll,ll> > v;
	for(ll i=0;i<n;i++){
		ll b,r;cin>>b>>r;
		pair<ll,ll> p(b,r);
		v.push_back(p);
	}
	
	ll ans=0;
	
	sort(v.begin(),v.end());
	for(auto p:v){
		ans+=p.second-p.first+1;
	}
	ans+=(v[0].first-1)%x;
	for(int i=1;i<v.size();i++){
		ans+=(v[i].first-v[i-1].second-1)%x;
	}
	cout<<ans<<"\n";
}