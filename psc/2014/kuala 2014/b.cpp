#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	for(int tc=1;tc<=t;tc++){
		int n,k,ones=0;cin>>n>>k;
		vector<int> v(n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];
			ones+=v[i];
		}
		k-=ones;
		if(k%2){
			cout<<"Case #"<<tc<<": 0\n";
			continue;
		}
	}
}