#include <bits/stdc++.h>
using namespace std;

float C; int n;
	
vector<int> v,w;
vector<vector<int> >dp;

int main(){
	while(cin>>C>>n){
		int c=floor(C);
		v.assign(n,0);
		w.assign(n,0);
		//dp[i][j]=v iff max value=v when looking at the i-th item, j weight left
		dp.assign(n,vector<int>(c+1,0));
		
		for(int i=0;i<n;i++){
			cin>>v[i]>>w[i];
		}
		
		//base case
		for(int i=0;i<=c;i++){
			if(w[0]<=i)dp[0][i]=v[0];
		}
		
		for(int i=1;i<n;i++){
			for(int j=0;j<=c;j++){
				int ans=dp[i-1][j];
				if(j>=w[i])ans=max(ans,dp[i-1][j-w[i]]+v[i]);
				dp[i][j]=ans;
			}
		}
	//	for(int i=0;i<n;i++){for(int j=0;j<=c;j++){cout<<dp[i][j]<<"\t";}cout<<endl;}
	//	cout<<dp.back().back()<<endl;		
		int cw=c;
		vector<int> ans;
		for(int i=n-1;i>0;i--){
			if(dp[i][cw]!=dp[i-1][cw]){
				// took the item
				ans.push_back(i);
				cw-=w[i];
			}
		}
		if(dp[0][cw]!=0)ans.push_back(0);
		cout<<ans.size()<<"\n";
		for(int i:ans)cout<<i<<" ";
		cout<<"\n";
		
		set<int> s;
		find(s.begin(),s.end(),5);
		auto it=s.begin();it++;it++;
		sort(s.begin(),s.end());
		s.find(5);
	}
}
