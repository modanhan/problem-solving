#include <bits/stdc++.h>
using namespace std;

int n,s,f,ci;

vector<vector<int> > g;
vector<int> fort;

bool fu(int v, int p){
	if(fort[v]){
		return 0;
	}
	if(g[v].size()<=1){
		return 1;
	}
	for(int i:g[v]){
		if(i!=p){
			if(fu(i,v))return 1;
		}
	}
	return 0;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>s>>f;
		s--;
		g.assign(n,vector<int>());
		fort.assign(n,0);
		for(int i=0;i<n;i++){
			cin>>ci;
			while(ci--){
				int x;cin>>x;
				x--;
				g[i].push_back(x);
			}
		}

		for(int i=0;i<f;i++){
			int x;
			cin>>x;
			x--;
			fort[x]=1;
		}

		if(fu(s,-1))cout<<"yes\n";
		else cout<<"no\n";
		done:;
	}
	
}