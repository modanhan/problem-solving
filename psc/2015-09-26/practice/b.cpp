#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	while(n!=0){
		map<string, int> m;int ans=0;
		while(n--){
			string a;cin>>a;
			if(m.find(a)==m.end())m[a]=1;
			else m[a]++;
			for(int i=0;i<1002;i++){
				int t=0;
				for(auto it:m){
					if(it.second>=i)t+=i;
				}
				ans=max(ans,t);
			}
		}
		cout<<ans<<"\n";
		cin>>n;
	}
}