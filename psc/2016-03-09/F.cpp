#include <bits/stdc++.h>
using namespace std;

int main(){
//	cout<<(double)7*6/8/7;
	
	long long t,a,b;cin>>t;
	while(t--){
		cin>>a>>b;
		// a/b=k(k-1)/n(n-1)
		// an(n-1)=bk(k-1)
		long long n=2,k=2;
		for(;n<1000001;n++){
			long long x=a*n*(n-1);
			// bk(k-1)=x
			long long l=2,h=(long long)sqrt(x),m=(l+h)/2;
			for(long long i=0;i<35;i++){
				m=(l+h)/2;
				if(x>b*m*(m-1)){
					l=m+1;
				}else h=m;
			}
			if(x==b*m*(m-1)){k=m;goto done;}
		}
		done:;
		cout<<n<<" "<<k<<"\n";
	}
}