#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v,u;

int lis(vector<int>& l,int m){
	vector<int> L; // L[x] = smallest end of length x LIS
	for (int x:l) {
		if(m>x)continue;
		auto it = lower_bound(L.begin(), L.end(), x);
		if (it == L.end()) L.push_back(x); else *it = x;
	}
	return L.size();
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		v.assign(n,0);u.assign(n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];u[i]=-v[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,lis(v,v[i])+lis(u,u[i])-1);
		}
		cout<<ans<<endl;
	}
}