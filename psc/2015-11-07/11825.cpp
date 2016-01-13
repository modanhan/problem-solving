#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > adj_list;
adj_list g;
int n,x;
vector<int> dp;

int f(int mask){
	if(dp[mask]!=-1)return dp[mask];
	int t=0;
	for(int i=0;i<n;i++){
		if(mask&(1<<i)){
			t|=(1<<i);
			for(int x:g[i])t|=(1<<x);
		}
	}
	if(t==(1<<n)-1)t=1;
	else t=0;
	
//	cout<<""<<bitset<6>(mask)<<"\t"<<t<<"\n";
	for(int x=(mask-1)&mask;x>0;x=(x-1)&mask){
	//	cout<<bitset<5>(mask)<<' '<<bitset<5>(x)<<' '<<bitset<5>(x^mask)<<'\n';
		t=max(t,f(x)+f(x^mask));
	}
	dp[mask]=t;
	return t;
}

int main(){
	int t=1;
	while(cin>>n){
		if(n==0)break;
		g.clear();
		dp.assign(1<<18,-1);
		dp[0]=0;
		for(int i=0;i<n;i++){
			cin>>x;
			g.push_back(vector<int>(x,0));
			for(int j=0;j<x;j++)cin>>g[i][j];
		}
		cout<<"Case "<<t<<": "<<f((1<<n)-1)<<'\n';
		t++;
	}
}