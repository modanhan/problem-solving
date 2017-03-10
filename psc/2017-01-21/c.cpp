#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,t;
vector<ll> v;

bool can(ll k){
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	int i;
	for(i=0;i<k;i++){
		pq.push(v[i]);
	}
	for(;i<n;i++){
		ll top=pq.top();
		pq.pop();
		if(top>t)return 0;
		pq.push(top+v[i]);
	}
	while(!pq.empty()){
		ll top=pq.top();
		pq.pop();
		if(top>t)return 0;
	}
	return 1;
}

int main(){
	cin>>n>>t;
	v.assign(n,0);
	for(int i=0;i<n;i++)cin>>v[i];
	//for(int i=1;i<=n;i++)cout<<can(i)<<endl;
	ll l=1,h=n;
	while(h-l>1){
		if(can((h+l)/2)){
			h=(h+l)/2;
		}else{
			l=(h+l)/2;
		}
	}
	cout<<h<<endl;
}
