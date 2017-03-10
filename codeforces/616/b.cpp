#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,ans=0;

int main(){
	cin>>n>>m;
	
	// find max (min cost in row)
	for(int i=0;i<n;i++){
		ll minr=999999999999;
		for(int j=0;j<m;j++){
			cin>>x;
			minr=min(minr,x);
		}
		ans=max(ans,minr);
	}
	cout<<ans;
	
	
}