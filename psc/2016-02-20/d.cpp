#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t,asdf=0;
	while(cin>>n>>t){
		asdf++;
		int a=0,ans=0;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			a+=x;
			if(a<=t)ans++;
		}
		cout<<"Case "<<asdf<<": "<<ans<<endl;
	}
}