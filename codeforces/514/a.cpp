#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	if(s[0]>=53&&s[0]!='9'){
		s[0]=48+57-s[0];
	}
	if(s[0]=='0'){
		s[0]='9';
	}
	for(int i=1;i<s.size();i++){
		if(s[i]>=53){
			s[i]=48+57-s[i];
		}
	}
	cout<<s<<'\n';
}