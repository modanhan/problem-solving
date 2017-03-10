#include <bits/stdc++.h>
using namespace std;

int m=100000000;

int main(){
	int t;cin>>t;
	int a,b;
	char c;
	while(t--){
		cin>>a>>c>>b;
		int g=__gcd(a,b);
		if(m%(b/g)==0){
			printf("%.8f\n",(double)a/b);
		}else{
			printf("ERROR\n");
		}
	}
}