#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string,string> mp;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		string s1,s2;cin>>s1>>s2;
		if(s2.size()<s1.size()){
			mp[s1]=s2;
			mp[s2]=s2;
		}else{
			mp[s1]=s1;
			mp[s2]=s1;
		}
	}
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		cout<<mp[s]<<" ";
	}
	cout<<"\n";
}