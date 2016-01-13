#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	vector<int> v,l,r;
	// l[i]=lis that ends at i including i
	// r[i]=lds that starts at i
	while(cin>>n){
		v.assign(n,0);
		l.assign(n,1);
		r.assign(n,1);
		for(int i=0;i<n;i++)cin>>v[i];
		vector<int> L,R;
		for(int i=0;i<n;i++){
			int x=v[i];
			auto it=lower_bound(L.begin(),L.end(),x);
			if(it==L.end())L.push_back(x);else *it=x;
			l[i]=L.size();
		}
		for(int i=n-1;i>=0;i--){
			int x=v[i];
			auto it=lower_bound(R.begin(),R.end(),x);
			if(it==R.end())R.push_back(x);else *it=x;
			r[i]=R.size();
		}
	/*	for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(v[i]>v[j]){
					l[i]=max(l[i],l[j]+1);
				}
			}
		}
		for(int i=n-2;i>=0;i--){
			for(int j=i+1;j<n;j++){
				if(v[i]>v[j]){
					r[i]=max(r[i],r[j]+1);
				}
			}
		}*/
		int ans=0;
		for(int i=0;i<n;i++){
			if(l[i]==r[i])ans=max(ans,l[i]*2-1);
		}
		cout<<ans<<'\n';
	}
}