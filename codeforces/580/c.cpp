#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > adjlist;

vector<bool> v;
vector<int> cat;
adjlist g;
int ans=0,n,m;
void dfs(int s,int c,bool l){
	v[s]=1;
	if(cat[s]){
		if(l)c++;
		else{ c=1;}
		l=1;
	}else{
		l=0;
	}
	if(c>m){
		return;
	}
/*	if(g[s].empty()){
		ans++;
		return;
	}*/
	bool did=0;
	for(int t:g[s]){
		if(!v[t]){
			did=1;
			dfs(t,c,l);
		}
	}
	if(!did){
		ans++;
	}
}

int main(){
	cin>>n>>m;
	cat.assign(n,0);
	v.assign(n,0);
	g.assign(n,vector<int>());
	for(int i=0;i<n;i++){
		cin>>cat[i];
	}
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0,0,0);
	cout<<ans<<'\n';
}