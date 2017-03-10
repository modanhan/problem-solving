#include <bits/stdc++.h>
using namespace std;

string s;
set<string> ans;

vector<int> dp2,dp3;

int f3(int idx);
int f2(int idx);

// insert size 2 string
int f2(int idx){
	if(idx>s.size())return 0;
	if(idx==s.size())return 1;
	int& ansx=dp2[idx];
	if(ansx!=-1)return ansx;
	ansx=0;
	string ss=s.substr(idx,2);
	if(f3(idx+2)){
		ans.insert(ss);
		ansx=1;
	}
	if(f2(idx+2)&&s.substr(idx+2,2)!=ss){
		ans.insert(ss);
		ansx=1;
	}
	return ansx;
}

// insert size 3 string
int f3(int idx){
	if(idx>s.size())return 0;
	if(idx==s.size())return 1;
	int& ansx=dp3[idx];
	if(ansx!=-1)return ansx;
	ansx=0;
	string ss=s.substr(idx,3);
	if(f3(idx+3)&&s.substr(idx+3,3)!=ss){
		ans.insert(ss);
		ansx=1;
	}
	if(f2(idx+3)){
		ans.insert(ss);
		ansx=1;
	}
	return ansx;
}

int main(){
	cin>>s;
	dp2.assign(s.size(),-1);
	dp3.assign(s.size(),-1);
	for(int i=5;i<s.size();i++){
		f2(i);f3(i);
	}
	cout<<ans.size()<<'\n';
	for(string s:ans){
		cout<<s<<'\n';
	}
}
