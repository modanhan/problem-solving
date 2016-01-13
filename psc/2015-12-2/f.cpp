#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v(n,0);
		int m=0,mx=0,mc=0,mi=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
			m+=v[i];
			if(v[i]>mx){
				mx=v[i];mc=0;mi=i;}
			else if(v[i]==mx)
				mc++;
		}
		if(mc){
			cout<<"no winner\n";
			continue;
		}
		if(mx*2>m){
			cout<<"majority winner "<<mi+1<<"\n";
		}else cout<<"minority winner "<<mi+1<<"\n";
		
	}
}