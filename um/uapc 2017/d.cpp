#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,r,t,maxdiff=0;
vector<ll> v;

bool can(ll s){
	ll time=0, remS=s;
	for(int i=0;i<n;i++){
		ll losing = v[i] - (i?v[i-1]:0);
		if (remS < losing) {
			// Need to rest at prev step
			time += r;
			remS = s;
		}
		remS -= losing;
	
		/*for(int j=i+1;j<n;j++){
			if(v[j]-v[i]>s||j==n-1){
				i=j;
				break;
			}
		}
		time+=r;*/
	}
	//time-=r;
	return time+v.back()<=t;
}

int main(){
	cin>>n>>r>>t;
	v.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i)maxdiff=max(maxdiff,v[i]-v[i-1]);
	}
	maxdiff=max(maxdiff,v[0]);
	//binary search from maxdiff to t
	ll lo=maxdiff-1,hi=t+1,mi;
	while(1){
		if(hi-lo<=1)break;
		mi=(hi+lo)>>1;
		if(can(mi))hi=mi;
		else lo=mi;
	}
	cout<<(hi)<<endl;
}
