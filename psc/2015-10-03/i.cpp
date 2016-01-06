#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;string s,ss="Simon says";getline(cin,s);
	while(n--){
		getline(cin,s);
		if(s.size()>ss.size()){
			for(int i=0;i<ss.size();i++){
				if(s[i]!=ss[i])goto bad;
			}
		}
		for(int i=ss.size();i<s.size();i++)cout<<s[i];
		cout<<"\n";
		bad:;
	}
}