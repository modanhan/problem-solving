#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,k;cin>>n>>k;
	int ans=n-1;
	while(k--){
		int m;cin>>m;
		ans+=m-1;
		vector<int> v(m,0);
		for(int i=0;i<m;i++){
			cin>>v[i];
		}
		if(v[0]==1){
		for(int i=0;i<m-1;i++){
			if(v[i]==v[i+1]-1){
				ans-=2;
			}else{
				break;
			}
		}}
	}
	cout<<ans<<"\n";
}