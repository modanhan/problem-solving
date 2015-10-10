#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		double a,b,z,n;
		cin>>a>>b>>z>>n;
		double ans=z;
		while(n--){
			z=a*z+b;
			ans=max(ans,z);
		}
		printf("%.3f\n",ans);
	}
}