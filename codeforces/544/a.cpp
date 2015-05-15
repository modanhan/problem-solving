#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;string s;
	cin>>k>>s;
	int d=0;
	vector<bool> v(200,0);
	int cn=0;
	vector<bool> newchar(200,0);
	for(char c:s){
		if(!v[c]){
			d++;
			v[c]=1;
			newchar[cn]=1;
		}
		cn++;
	}
//	for(int i=0;i<7;i++){
//		cout<<newchar[i];
//	}
	if(d>=k){
		cout<<"YES";
		int current=0,words=0;
		while(current<s.size()){
			if(words>=k){
				break;
			}
			if(newchar[current]){
				words++;
				cout<<"\n";
			}
			cout<<s[current];
			current++;
		}
		while(current<s.size()){
			cout<<s[current];
			current++;
		}
		cout<<"\n";
	}else{
		cout<<"NO\n";
	}
}