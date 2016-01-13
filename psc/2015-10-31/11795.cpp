#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<bool> mb;
vector<vector<bool> > v;

vector<ll> dp;
ll f(int mask){
	if(dp[mask]!=0)return dp[mask];
	// list of robots that can be killed with what we got
	vector<bool> killable=mb;
	for(int i=0;i<n;i++){
		if((mask&(1<<i))==0){// robot i is dead
			// get all weapon form i
			for(int j=0;j<n;j++)killable[j]=v[i][j]|killable[j];
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(mask&(1<<i)){//robot i alive
			if(killable[i]){//and can kil it
				ans+=f(mask^(1<<i));
			}
		}
	}
	dp[mask]=ans;
	return ans;
}

int main(){
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		mb.assign(n,0);
		v.assign(n,vector<bool>(n,0));
		dp.assign(1<<17,0);
		dp[0]=1;// all dead, so 1 way?
		string s;cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='1')mb[i]=1;
		}
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<n;j++){
				if(s[j]=='1')v[i][j]=1;
			}
		}
		
	//	cout<<((1<<n)-1);
		cout<<"Case "<<t<<": "<<f((1<<n)-1)<<"\n";
		for(int i=0;i<(1<<n);i++){
	//		printf("%u\t%d\n",i,dp[i]);
		}
	}
}