#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	string s;getline(cin,s);
	while(n--){
		vector<bool> v(300,0);
		getline(cin,s);
		for(char c:s){
			v[tolower(c)]=1;
		}
		vector<char> uv;
		for(char c='a';c<='z';c++){
			if(!v[c])uv.push_back(c);
		}
		if(uv.empty()){
			cout<<"pangram\n";
		}else{
			cout<<"missing ";
			for(char c:uv)cout<<c;
			cout<<'\n';
		}
	}
}