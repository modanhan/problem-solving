#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll x;cin>>x;
	vector<vector<ll> > v(20,vector<ll>(20,1));
	for(int i=1;i<20;i++){
		for(int j=1;j<20;j++){
			v[i][j]=v[i-1][j]+v[i][j-1];
		}
	}
	cout<<v[x-1][x-1]<<"\n";
}