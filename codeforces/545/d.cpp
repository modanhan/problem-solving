#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int> v(n,0);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int t=0;
	int ans=0;
	for(int i=0;i<n;i++){
		
	//	cout<<t<<" ";
		if(v[i]>=t){
			ans++;
			t+=v[i];
		}
		
	}
	cout<<ans<<"\n";
}