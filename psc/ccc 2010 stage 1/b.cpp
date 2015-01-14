#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<pair<string,string> > v;
	for(int i=0;i<n;i++){
		pair<string,string> p;
		cin>>p.second;
		cin>>p.first;
		v.push_back(p);
	}
	string s;
	cin>>s;
	sort(v.begin(),v.end());
	int c=0;
	while(c<s.size()){
		for(auto p:v){
			if(s.size()-c>=p.first.size()){
				if(equal(s.begin()+c,s.begin()+c+p.first.size(),p.first.begin())){
					cout<<p.second;
					c+=p.first.size();
					break;
				}
			}
		}
	}
	cout<<"\n";
}