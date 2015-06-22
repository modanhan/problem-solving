#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a% b);
	}
}

int main(){
	long long m,h1,a1,x1,y1,h2,a2,x2,y2;
	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	
	vector<bool> a(m,0),b(m,0);
	
	int ansa=0,ansb=0;
	
	for(int i=0;i<m;i++){
		h1=(h1*x1+y1)%m;
		if(ansa==0&&h1==a1){
			a[i]=1;
			ansa=i;
		}
		h2=(h2*x2+y2)%m;
		if(ansb==0&&h2==a2){
			b[i]=1;
			ansb=i;
		}
	}
	
	if(ansa==0||ansb==0){
		goto bad;
	}
	
	cout<<ansa*ansb<<"\n";
	return 0;
	
	for(int i=0;i<m;i++){
		if(a[i]&&b[i]){
			cout<<i+1<<"\n";
			return 0;
		}
	}
	bad:
	cout<<"-1\n";
}
