#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int main(){
	cin>>n;
	v.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,v[i]+i);
	}
	cout<<ans<<endl;
}