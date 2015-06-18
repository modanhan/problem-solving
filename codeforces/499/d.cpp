#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t;cin>>n>>t;
	double dp[n+1][t+1];
	memset(dp,0,sizeof dp);
	vector<pair<double,int> > v;
	for(int i=0;i<n;i++){
		pair<double,int> p;t
		cin>>p.first;
		p.first/=100;
		cin>>p.second;
		v.push_back(p);
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			if(v[i-1].second<=j){
				dp[i][j]=dp[i-1][j-v[i-1].second]+1;
			}else{
				for(int e=1;e<=t;e++){
					dp[i][j]=max(dp[i][j],1-pow(1-v[i-1].first,e)+dp[i-1][j-e]);
				}
			}
		}
	}
	for(int y=0;y<=n;y++){
		for(int x=0;x<=t;x++){
			cerr<<dp[y][x]<<" ";
		}
		cerr<<"\n";
	}
	printf("%.9f\n",dp[n][t]);
}