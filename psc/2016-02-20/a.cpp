#include <bits/stdc++.h>
using namespace std;

int main(){
	int asdf=1;
	int n;
	while(cin>>n){
		int x=1,m=1,ans=0;
		while(n>=x){
			ans+=x*m;
			n-=x;
			x*=2;
			m++;
		}
		ans+=n*m;
		
		cout<<"Case "<<asdf<<": "<<ans<<endl;
		asdf++;
	}
}