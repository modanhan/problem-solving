#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	for(int T=1;T<=t;T++){
		int n,m,k;
		cin>>n>>m>>k;

		vector<int> v(n,1);
		v[1]=2;
		v[2]=3;
		for(int i=3;i<n;i++){
			v[i]=(v[i-1]+v[i-2]+v[i-3])%m+1;
		}
		int b=0,e=0,ans=100000000;
		vector<int> u(m+1,0);
		set<int> s;
		while(b!=n){
			if(s.size()>=k){
				ans=min(ans,e-b);
				u[v[b]]--;
				if(u[v[b]]==0){
					s.erase(v[b]);
				}
				b++;
			}else{
				if(e==n)break;
				u[v[e]]++;
				if(v[e]<=k)s.insert(v[e]);
				e++;
			}
		}
		cout<<"Case "<<T<<": ";
		if(ans!=100000000){
			cout<<ans<<"\n";
		}else{
			cout<<"sequence nai\n";
		}
	}
}