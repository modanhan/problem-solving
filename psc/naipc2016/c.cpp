#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct card{
	ll w,h,q;
};



int n,k;
vector<card> v;
ll dp[1<<15][16];
ll calcdp[1<<15];

ll calc(int mask){
	ll& ans=calcdp[mask];
	if(ans!=-1)return ans;
	ans=0;
	ll maxw=0,maxh=0,e;
	for(int i=0;i<n;i++){
		if(mask&(1<<i)){
			maxw=max(maxw,v[i].w);
			maxh=max(maxh,v[i].h);
		}
	}
	e=maxw*maxh;
	for(int i=0;i<n;i++){
		if(mask&(1<<i)){
			ans+=(e-v[i].w*v[i].h)*v[i].q;
		}
	}
//	cout<<ans<<endl;
	return ans;
}

//f(mask) = min waste when the 1-cards still need envelope and l left
ll f(int mask, int l){
	if(mask==0)return 0;
	ll& ans=dp[mask][l];
	if(ans!=-1)return ans;
	if(l==1){//calc min env size and waste
		ans=calc(mask);
		return ans;
	}
	int bs=mask;
	ans=LLONG_MAX;
	for (int bt = (bs) & bs; bt; bt = (bt-1) & bs) {
		int bu = bt ^ bs; // contains the opposite subset of bt (e.g. if bt = 10000, bu = 00110)
		ans=min(calc(bt)+f(bu,l-1),ans);
	}
	return ans;
}

int main(){
	cin>>n>>k;
	v.assign(n,card());
	for(int i=0;i<n;i++){
		cin>>v[i].w>>v[i].h>>v[i].q;
	}
	memset(dp,-1,sizeof(dp));
	memset(calcdp,-1,sizeof(calcdp));
	cout<<f((1<<n)-1,k)<<endl;
}
