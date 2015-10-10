#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	while(n--){
		bool z=0,m=0;
		for(int i=0;i<10;i++){
		int x;cin>>x;
		cout<<x<<' ';
		if(x==17){
			z=1;
		}
		if(x==18){
			m=1;
		}
		}
		if(z){
			if(m){
				cout<<"\nboth\n\n";
			}else{
				cout<<"\nzack\n\n";
			}
		}else{
			if(m){
				cout<<"\nmack\n\n";
			}else cout<<"\nnone\n\n";
		}
	}
}