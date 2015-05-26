#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int> > v(n,vector<int>(m,0));
	
	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>v[i][j];
			}
		}
/*	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	while(q--){
		int x,y;cin>>x>>y;
		x--;y--;
		v[x][y]=1-v[x][y];
		int ans=0;
		for(int i=0;i<n;i++){
			int t=0,last=0;
			for(int j=0;j<m;j++){
				if(v[i][j]){
					last=1;
					t++;
				}else{
					last=0;
					t=0;
				}
				ans=max(ans,t);
			}
		}
		cout<<ans<<"\n";
	}
}