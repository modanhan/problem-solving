#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,max;
	cin>>n>>k;
	
	if(n%2){
		max=n*n/2+1;
	}else{
		max=n*n/2;
	}
	if(k>max){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		for(int y=0;y<n;y++){
			for(int x=0;x<n;x++){
				if((y+x)%2){
					cout<<"S";
				}else{
					if(k>0){
						cout<<"L";
					}else{
						cout<<"S";
					}
					k--;
				}
			}
			cout<<"\n";
		}
	}
}