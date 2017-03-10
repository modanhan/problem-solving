#include <bits/stdc++.h>
using namespace std;

int n,k;
string s;
vector<int> v;

int main(){
	cin>>n>>k>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')v.push_back(i);
	}
	
	int ans=10000000;
	for(int i=0;i<v.size()-k;i++){
		int m=v[i]+v[i+k];
		m>>=1;
		auto it=lower_bound(v.begin(),v.end(),m);
		ans=min(ans,max(*it-v[i],v[i+k]-(*it)));
		it--;
		ans=min(ans,max(*it-v[i],v[i+k]-(*it)));
	}
	cout<<ans<<endl;
}
