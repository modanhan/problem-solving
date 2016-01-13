#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int x;cin>>x;
		if(x&1){
			cout<<x<<" is odd\n";
		}else cout<<x<<" is even\n";
	}
}