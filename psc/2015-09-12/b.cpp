#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	while(n--){
		int usum=0,rsum=0;
		vector<int> usa(3),rus(3);
		for(int i=0;i<3;i++){
			cin>>usa[i];
			cout<<usa[i]<<' ';
			usum+=usa[i];
		}
		for(int i=0;i<3;i++){
					cin>>rus[i];
					cout<<rus[i]<<' ';
					rsum+=rus[i];
				}
		if(usa>rus){
			if(usum>rsum){
				cout<<"\nboth\n\n";
			}else cout<<"\ncolor\n\n";
		}else{
			if(usum>rsum){
				cout<<"\ncount\n\n";
			}else cout<<"\nnone\n\n";
		}
	}
}