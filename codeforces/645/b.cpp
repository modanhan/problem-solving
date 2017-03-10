#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;cin>>n>>k;
	k*=2;
	long long ans=0;
	while(k--){
		if(n)
		n--;
		ans+=n;
	}
	cout<<ans<<endl;
}
