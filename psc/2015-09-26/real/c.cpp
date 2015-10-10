#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		double b,m;cin>>b>>m;
		double p=m/2+b;
	//	cout<<p;
		double ans=0;
		while(p>.001){
			ans+=p;
			p*=p;
		}
		printf("%f\n",ans);
	}
}