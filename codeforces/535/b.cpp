#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	string s;
	cin>>s;
	ll ans=0;
	for(char c:s){
		ans*=2;
		if(c=='4'){
			ans++;
		}else{
			ans+=2;
		}
	}
	cout<<ans<<"\n";
}