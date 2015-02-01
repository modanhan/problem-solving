#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
		double d;int n;cin>>d>>n;
		double x=1;
		while(n--){
			x=x*(2+d)/2;
		}
		cout<<"Case #"<<t<<": "<<x<<"\n";
	}
}