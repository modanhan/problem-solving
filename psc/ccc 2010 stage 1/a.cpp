#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct m{
	bool operator()(pair<ll,string> f,pair<ll,string> s){
		if(f.first<s.first){
			return true;
		}else if(f.first>s.first){
			return false;
		}else{
			return f.second>s.second;
		}
	}
}whatisthis;
//oh this is a comparator cool i learned something new today
//oh apparently i can also use function as comparator

int main(){
	ll n;
	cin>>n;
	if(n<=0){
		return 0;
	}
	if(n==1){
		string s;
		cin>>s;
		cout<<s<<"\n";
		return 0;
	}
	vector<pair<ll,string> > v;
	for(int i=0;i<n;i++){
		string name;
		ll r,s,d;
		cin>>name>>r>>s>>d;
		pair<ll,string> p(2*r+3*s+d,name);
		v.push_back(p);
	}
	sort(v.begin(),v.end(),whatisthis);
	cout<<v[n-1].second<<"\n"<<v[n-2].second<<"\n";
}