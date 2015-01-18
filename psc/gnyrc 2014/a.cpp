#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	for(int tc=1;tc<=t;tc++){
		int asdf=20;
		int ugh;cin>>ugh;
		vector<int> v(20,0);
		for(int i=0;i<20;i++){
			cin>>v[i];
		}
		int ans=0;
		for(int i=0;i<20;i++){
			for(int j=0;j<i;j++){
				if(v[j]>v[i]){
					ans++;
				}
			}
		}
		cout<<tc<<" "<<ans<<"\n";
	}
}