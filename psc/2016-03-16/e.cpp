#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > g;
vector<int> dp;

//f(mask)=num of ways to permutate the 0s
int f(unsigned int mask){
	if(dp[mask]!=-1)return dp[mask];
	int pc=__builtin_popcount(mask);
	if(pc==n)return 1;
	// pc gives to who?
	int ans=0;
	for(int i=0;i<n;i++){
		if(((mask&(1<<i))==0)&&g[pc][i])
			ans+=f(mask|(1<<i));
	}
	dp[mask]=ans;
	return ans;
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		g.assign(n,vector<int>(n,1));
		for(int i=0;i<n;i++)g[i][i]=0;
		dp.assign(1<<n,-1);
		while(m--){
			int x,y;cin>>x>>y;x--;y--;
			g[x][y]=0;
		}
		int t=f(0);
		
		for(int i=2;i<n;i++)g[0][i]=0;
		dp.assign(1<<n,-1);
		
		int w=f(0);
		
		printf("%.10f\n",(double)w/t);
	}
}
