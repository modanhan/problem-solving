#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		unsigned int x;cin>>x;
int ans=0;
while(x){
ans=max(ans, __builtin_popcount(x));
x/=10;
}
		cout<<ans<<endl;
	}
}
