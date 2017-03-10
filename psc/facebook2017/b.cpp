#include <bits/stdc++.h>
using namespace std;

int main(){
	int casenumber=0;
	int t;cin>>t;
	while(t--){
		casenumber++;
		int n,ans=0;cin>>n;
		list<int> l(0,0);
		for(int i=0;i<n;i++){int x;cin>>x;l.push_back(x);}
		l.sort();
		while(l.size()){
			int back=l.back();			l.pop_back();
			int sum=back;
			while(sum<50){if(l.size()){l.pop_front();sum+=back;}else goto done;}
			ans++;
		}
	done:;
	cout<<"Case #"<<casenumber<<": "<<ans<<'\n';
	}
}
