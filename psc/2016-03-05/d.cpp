#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,b;
vector<ll> v;

ll f(){
	ll l=0,h=10000000000000000,mid,x;
	ll asdf=100;
	while(asdf--){
		mid=(l+h)/2,x=mid;
		ll bs=1;
		for(int i=0;i<n;i++){
			if(mid<v[i]){
				bs=b+1;
				continue;
			}
			if(x-v[i]<0){
				x=mid-v[i];
				bs++;
			}else{
				x-=v[i];
			}
		}
		if(bs>b){
			l=mid;
		}else{
			h=mid+1;
		}
	}
	return mid;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>b;
		v.assign(n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
	/*	ll mid=3,x=mid;
				ll bs=1;
				for(int i=0;i<n;i++){
					
					if(mid<v[i]){
						bs=b+1;
						continue;
					}
					if(x-v[i]<0){
						x=mid-v[i];
						bs++;
					}else{
						x-=v[i];
					}
					cout<<x<<" ";
				}
				cout<<bs<<endl;*/
		cout<<f()<<'\n';
	}
}