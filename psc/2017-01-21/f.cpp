#include <bits/stdc++.h>
using namespace std;

int n,k;

vector<int> v;

vector<vector<vector<int> > > dp;

int convert(char c){
	if(c=='H')return 0;
	if(c=='S')return 1;
	if(c=='P')return 2;
}

int beat(int a, int b){
	if( (a==0&&b==1)||(a==2&&b==0)||(a==1&&b==2))return 1;
	return 0;
}

// f(g, s, c)=about to play game g, s switches left, current char is c
int f(int g, int s, int c){
	if(dp[g][s][c]!=-1)return dp[g][s][c];

	if(g==n-1){
		if(s==0)return beat(c,v[n-1]);
		else return 1;
	}
	//does not switch
	int ans=f(g+1,s,c)+beat(c,v[g]);
	if(s>0){
		//switch to something
		ans=max(ans, f(g+1, s-1, 2)+beat(2,v[g]));
		ans=max(ans, f(g+1, s-1, 0)+beat(0,v[g]));
		ans=max(ans, f(g+1, s-1, 1)+beat(1,v[g]));
	}
	dp[g][s][c]=ans;
//	cout<<g<<' '<<s<<' '<<c<<' '<<ans<<endl;
	return ans;
}

int main(){
	cin>>n>>k;
	v.assign(n,0);
	dp.assign(n, vector<vector<int> >(k+1, vector<int>(3,-1)));
	for(int i=0;i<n;i++){char x;cin>>x;v[i]=convert(x);}
	int ans=f(0, k, 0);
	ans=max(ans, f(0, k, 1));
	ans=max(ans, f(0, k, 2));
	cout<<ans<<endl;
}
