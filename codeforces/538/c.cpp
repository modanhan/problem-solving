#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	ll n,m;
	cin>>n>>m;
	map<ll,ll> g;
	g[1]=0;
	for(int i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		g[a]=b;
	}
	for(pair<ll,ll> p:g){
		
	}
}