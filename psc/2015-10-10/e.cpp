#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,w,l,h,a,m;
	while(1){
		cin>>n>>w>>l>>h>>a>>m;
		if(n==0){
			break;
		}
		int t=(w+l)*h*2+w*l;
		
		int x,y;
		while(m--){
			cin>>x>>y;
			t-=x*y;
		}
		
		t*=n;
		cout<<((t+a-1)/a)<<"\n";
	}
}