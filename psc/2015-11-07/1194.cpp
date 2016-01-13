#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<int> > g;
vector<int> matchr,seen;

bool bpm(int u){
	for(int v=0;v<n;v++){
		if(g[u][v]>0&&!seen[v]){
			seen[v]=1;
			if(matchr[v]<0||bpm(matchr[v])){
				matchr[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(cin>>n>>m>>k){
		int asdf,x,y;
		g.assign(m,vector<int>(n,0));
		matchr.assign(n,-1);
		for(int i=0;i<k;i++){ 	
			cin>>asdf>>x>>y;
			if(x==0||y==0)continue;
			g[y][x]=1;
		}
		int ans=0;
		for(int u=0;u<m;u++){
			seen.assign(n,0);
			if(bpm(u))ans++;
		}
		cout<<ans<<'\n';
	}
}