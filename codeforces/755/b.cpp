#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_set<string> a,b;

int main(){
	cin>>n>>m;
	int asdf=n;
	while(asdf--){
		string x;cin>>x;
		a.insert(x);
	}
	asdf=m;
	bool bb=1;
	while(asdf--){
		string x;cin>>x;
		if(a.find(x)!=a.end()){
			if(bb){
				m--;
			}else{
				n--;
			}
			bb=!bb;
		}
	}
	cout<<(n>m?"YES\n":"NO\n");
}
