#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n;

vector<vector<ll> > v;


int main(){
	ll t;cin>>t;
	while(t--){
		cin>>n;
		v.assign(50,vector<ll>(50, 0));
		v[25][25]=1;
		//center is 25 25
		while(n--){
		vector<vector<ll> > x(50,vector<ll>(50, 0));
			for(ll i=1;i<49;i++){
				for(ll j=1;j<49;j++){
					if(v[i][j]){
						x[i][j-1]+=v[i][j];
						x[i+1][j-1]+=v[i][j];
						x[i-1][j]+=v[i][j];
						x[i+1][j]+=v[i][j];
						x[i][j+1]+=v[i][j];
						x[i-1][j+1]+=v[i][j];
					}
				}
			}
		/*	for(int i=1;i<49;i++){
				for(int j=1;j<49;j++)
					cout<<v[i][j]<<' ';
					cout<<endl;}*/
					v=x;
		}
		cout<<v[25][25]<<endl;
	}
}
