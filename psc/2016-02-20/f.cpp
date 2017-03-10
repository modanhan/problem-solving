#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


vector<vector<ll> > c(70,vector<ll>(70,0));

// # of ways n int sum up to t
ll f(ll n,ll t){
	//t 1s.. n-1 pluses
	//t+n-1 choose t 
	return c[t+n-1][t];
}

int main(){
	
	for(int i=0;i<70;i++){
		c[i][0]=1;//i choose 0, 1 way
	}
	for(int i=1;i<70;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	int n,asdf=0;
	while(1){
		asdf++;
		cin>>n;
		if(n==0)break;
		vector<ll> v(n,0);
		ll ans=0,sum=0;
		for(ll i=0;i<n;i++){cin>>v[i];sum+=v[i];}
		for(ll i=0;i<sum;i++){
			ans+=f(n,i);
		}
		int ps=0,psi=0;
		for(ll x:v){
			for(ll i=0;i<x;i++){
				ans+=f(n-1-psi,sum-i-ps);
			}
			psi++;
			ps+=x;
		}
		cout<<"Case "<<asdf<<": "<<ans+1<<endl;
	}

	
}