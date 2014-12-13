#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin>>s;
	ll l=0,r=0,h=0;
	for(char c:s){
		if(c=='('){
			l++;
		}else if(c==')'){
			r++;
		}else{
			h++;
		}
	}
	if(r+h<=l){
		ll c=0;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='#'){
				c++;
				s[i]=')';
				if(c==h){
					for(ll j=0;j<l-h-r;j++){
						s.insert(i,")");
					}
					break;
				}
			}
		}
		ll tl=0,tr=0;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='('){
				tl++;
			}else{
				tr++;
			}
			if(tr>tl){
				cout<<"-1\n";
				return 0;
			}
		}
		for(ll i=0;i<h-1;i++){
			cout<<"1 ";
		}
		cout<<l-h-r+1<<"\n";
	}else{
		cout<<"-1\n";
	}
}