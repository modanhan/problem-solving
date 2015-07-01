#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	for(int u=1;u<=t;u++){
		int n,ans=0;string s;cin>>n>>s;
		for(int i=0;i<n-2;i++){
			if(s[i]=='.'){
				s[i+1]='#';
				s[i+2]='#';
				i+=2;
				ans++;
			}
		}
		if(s[n-1]=='.'||s[n-2]=='.'){
			ans++;
		}
		cout<<"Case "<<u<<": "<<ans<<"\n";
	}
}