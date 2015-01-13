#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int ans=100000;
	for(int i=1;i<n-1;i++){
		vector<int> t=v;
		t.erase((t.begin()+i));
		int ma=0;
		for(int j=0;j<n-2;j++){
			ma=max(ma,t[j+1]-t[j]);
		}
		ans=min(ans,ma);
	}
	cout<<ans<<"\n";
}