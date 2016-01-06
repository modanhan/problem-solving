#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		ll d,n;cin>>d>>n;
	/*	if(n>6){
			cout<<"Grid #"<<t<<": "<<d*2*(n-1)<<"\n\n";
			continue;
		}
		ll k=1;
		for(int i=2*n-2;i>n-1;i--){
			k*=i;
		}*/
		if(n*n-2*(n-1)>=d){
			cout<<"Grid #"<<t<<": "<<d*2*(n-1)<<"\n\n";
		}else{
			cout<<"Grid #"<<t<<": impossible\n\n";
		}
	}
	
}