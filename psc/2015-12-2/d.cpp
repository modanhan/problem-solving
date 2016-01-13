#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	string s;
	getline(cin,s);
	t=stoi(s);
	while(t--){
		vector<int> v(500,0);
		getline(cin,s);
		for(char c:s){
			if(isalpha(c))v[(tolower(c))]=1;
		}
		string missing="";
		for(char c='a';c<='z';c++){
			if(v[c]==0)missing+=c;
		}
		if(missing==""){
			cout<<"pangram\n";
		}else{
			cout<<"missing "<<missing<<"\n";
		}
	}
}