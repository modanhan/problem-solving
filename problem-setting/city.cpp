#include <bits/stdc++.h>
using namespace std;

int n,d,ans,dead,tans;
vector<int> h,e,v,th,ansv,isdead;

int destroy(int hp){
	if(hp<0)return 0;
	return (hp+d-1)/d;
}

void ondeath(int idx){
	if(isdead[idx])return;
	th[idx]=0;
	dead++;
	isdead[idx]=1;
	if(idx-1>=0){th[idx-1]-=e[idx]; if(th[idx-1]<=0)ondeath(idx-1);}
	if(idx+1<n){th[idx+1]-=e[idx]; if(th[idx+1]<=0)ondeath(idx+1);}
}

int main(){
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>d;
		h.assign(n,0);
		e.assign(n,0);
		v.assign(n,0);
		for(int i=0;i<n;i++)cin>>h[i];
		for(int i=0;i<n;i++)cin>>e[i];
		for(int i=0;i<n;i++)v[i]=i;
		ans=1000000000;
		do{
			tans=0;dead=0;
			th=h;
			isdead.assign(n,0);
			for(int i=0;i<n;i++){
				//destroy v[i]-th building
				tans+=destroy(th[v[i]]);
				ondeath(v[i]);
			}
			//ans=min(tans,ans);
			if(tans<ans){ans=tans;ansv=v;}
//			for(int i=0;i<n;i++)cout<<v[i]<<' ';cout<<": "<<tans<<endl;
		}while(next_permutation(v.begin(),v.end()));
//		for(int i=0;i<n;i++)cout<<ansv[i]<<' ';cout<<": ";
		cout<<ans<<endl;
	}
}
