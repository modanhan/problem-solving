#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int s,b,m;cin>>s>>b>>m;
		cout<<"Practice #"<<t<<": "<<s<<' '<<b<<'\n';
		while(m--){
			int g;cin>>g;
			while(g>=b){
				b<<=1;
			}
			b-=g;
			cout<<g<<' '<<b<<'\n';
		}
		cout<<'\n';
	}
}