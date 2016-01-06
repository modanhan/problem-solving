#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
	int n,m;cin>>n>>m;
	vector<ii> e(m,ii(0,0));
	vector<vector<bool> > v(n,vector<bool>(n,0));
	vector<int> d(n,0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		e[i].first=a;e[i].second=b;
		v[a][b]=1;
		v[b][a]=1;
		d[a]++;
		d[b]++;
	}
	int ans=1000000000;
	for(ii a:e){
		for(int i=0;i<n;i++){
			if(v[a.first][i]&&v[a.second][i]){
				ans=min(ans,d[a.first]+d[a.second]+d[i]);
			}
		}
	}
	if(ans==1000000000)ans=5;
	cout<<(ans-6)<<"\n";
}