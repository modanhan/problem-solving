#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;cin>>n;
	while(n!=0){
		ll ans=0,c=0;
		
		for(int i=0;i<n;i++){
			int x;cin>>x;
			c+=x;
			if(c>ans){
				ans=c;
			}
			if(c<0){
				c=0;
			}
		}
		if(ans>0){
			cout<<"The maximum winning streak is "<<ans<<".\n";
		}else{
			cout<<"Losing streak.\n";
		}
		cin>>n;
	}
}