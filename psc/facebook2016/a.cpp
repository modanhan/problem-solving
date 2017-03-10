#include <bits/stdc++.h>
using namespace std;

// i underestimated how hard this problem is

int n;
string a,b;
vector<int> l,r,sl,sr;
int main(){
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>a>>b;
		if(n==1){
			if(a==b)cout<<"Case #"<<tc<<": 0\n";
			else cout<<"Case #"<<tc<<": 1\n";
			continue;
		}
		// l[i]=# of move to fix [0,i)
		// r[i]=# of move to fix [i,n)
		// max(l[i],r[i])=# of move to fix
		// sl[i]=# of segment [0,i]
		// sr[i]=# of segment [i,n-1]
		sl.assign(n,1);
		sr.assign(n,1);
		for(int i=1;i<n;i++){
			if(b[i]!=b[i-1])sl[i]=sl[i-1]+1;
			else sl[i]=sl[i-1];
		}
		
		for(int i=n-2;i>=0;i--){
			if(b[i]!=b[i+1])sr[i]=sr[i+1]+1;
			else sr[i]=sr[i+1];
		}
		
/*		for(int x:sl)cout<<x<<' ';
		cout<<endl;
		for(int x:sr)cout<<x<<' ';
		cout<<endl;*/
		
		l.assign(n+1,0);
		r.assign(n+1,0);
		for(int i=0;i<n;i++){
			if(a[i]==b[i])l[i+1]=l[i];
			else l[i+1]=sl[i];
		}
		
		for(int i=n-1;i>=0;i--){
			if(a[i]==b[i])r[i]=r[i+1];
			else r[i]=sr[i];
		}
		
/*		for(int x:l)cout<<x<<' ';
		cout<<endl;
		for(int x:r)cout<<x<<' ';
		cout<<endl;*/
		
		int ans=9999999;
		
		for(int i=0;i<=n;i++){
			ans=min(ans,max(l[i],r[i]));
		}
		
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
}