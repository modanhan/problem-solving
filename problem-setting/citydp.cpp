#include <bits/stdc++.h>
using namespace std;

int n,d,ans,dead,tans;
vector<int> h,e,dpy,dpn;

int destroy(int hp){
	if(hp<0)return 0;
	return (hp+d-1)/d;
}
//f(i,b)=min number of moves to destroy buildings (i,n] when (building (i-1) is destroyed == b)
int f(int i, int b){
	if(b){
		if(dpy[i]!=-1)return dpy[i];
	}else{
		if(dpn[i]!=-1)return dpn[i];
	}

	if(i==n-1){
		if(b)return destroy(h[i]-e[i-1]);
		else return destroy(h[i]);
	}
	if(b){
		int ans=destroy(h[i]-e[i-1])+f(i+1,1);
		int ans1=destroy(h[i]-e[i-1]-e[i+1])+f(i+1,0);
		dpy[i]=min(ans,ans1);
		return dpy[i];
	}else{
		int ans=destroy(h[i])+f(i+1,1);
		int ans1=destroy(h[i]-e[i+1])+f(i+1,0);
		dpn[i]=min(ans,ans1);
		return dpn[i];
	}
}

int main(){
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>d;
		h.assign(n,0);
		e.assign(n,0);
		dpy.assign(n,-1);
		dpn.assign(n,-1);
		for(int i=0;i<n;i++)cin>>h[i];
		for(int i=0;i<n;i++)cin>>e[i];
		cout<<f(0,0)<<endl;
	}
}
