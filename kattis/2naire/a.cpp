#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
	while(1){
		int n;double t;
		cin>>n>>t;
		if(n==0)return 0;
		
		double ss=(1-t)/2000;
		double c=1;
		double asdf=0;
		for(double d=t;d<=1;d+=ss){
			asdf+=(d*c*2);
		}
		asdf/=2000;
		cout<<asdf<<endl;
	}

}
