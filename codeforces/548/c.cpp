#include <bits/stdc++.h>
using namespace std;

int main(){
	long long m,h1,a1,x1,y1,h2,a2,x2,y2;
	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	
	vector<bool> a(m,0),b(m,0);
	
	for(int i=0;i<m;i++){
		x1=(x1*h1+y1)%m;
		if(x1==a1){
			a[i]=1;
		}
		x2=(x2*h2+y2)%m;
		if(x2==a2){
			b[i]=1;
		}
	}
	
	for(int i=0;i<m;i++){
		if(a[i]&&b[i]){
			cout<<i<<"\n";
			return 0;
		}
	}
	
	cout<<"-1\n";
}
