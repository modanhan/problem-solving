#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<int> p(n,0),w(n,0);
		for(int i=0;i<n;i++){
			cin>>p[i]>>w[i];
		}
		vector<vector<int> > ans(n,vector<int>(40,0));
		for(int i=0;i<40;i++){
			if(i>=w[0]){
				ans[0][i]=p[0];
			}else{
			ans[0][i]=0;}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<40;j++){
				if(j>=w[i]){
					ans[i][j]=p[i]+ans[i-1][j-w[i]];
				}
				ans[i][j]=max(ans[i][j],ans[i-1][j]);
			}
		}
		int g;cin>>g;
		int a=0;
		while(g--){
			int x;cin>>x;
			a+=ans[n-1][x];
		}
		cout<<a<<"\n";
	}
}