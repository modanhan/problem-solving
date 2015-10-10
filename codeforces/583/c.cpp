#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;cin>>n;
	map<ll,ll> m;
	for(int i=0;i<n*n;i++){
		ll x;cin>>x;
		if(m.find(x)==m.end()){
			m[x]=0;
		}m[x]++;
	}
	vector<ll> ans;
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	for(auto a:m){
		if(a.second%2)ans.push_back(a.first);
	}
	auto it=m.end();
	while(ans.size()<n){
		it--;
		if(((int)sqrt(it->second))*((int)sqrt(it->second))==it->second)
		ans.push_back(it->first);
	}
	for(ll i:ans)cout<<i<<' ';
}