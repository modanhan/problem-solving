#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> v(n);

	if(n>=m){
			cout<<"YES\n";
			return 0;
		}
	
	for(int i=0;i<n;i++){
		cin>>v[i];
		v[i]%=m;
	}
	

	
	vector<vector<bool> > dp(n,vector<bool>(m,0));
	dp[0][v[0]]=1;
	for(int i=1;i<n;i++){
		dp[i][v[i]]=1;
		for(int j=0;j<m;j++){
			if(dp[i-1][j]){
				dp[i][j]=1;
				dp[i][(j+v[i])%m]=1;
			}
		}
	}
	if(dp[n-1][0]){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}