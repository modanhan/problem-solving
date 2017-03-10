#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;ll n;
ll l;

char f(ll x){
//cout<<x<<endl;
	if(x<l)return s[x];
	ll tl=l;
	while((tl<<1)<=x){
		tl<<=1;
	}
//	cout<<'t'<<tl<<endl;
	if(tl==x)return f(x-1);
	else return f(x-tl-1);
}

int main(){
	cin>>s>>n;n--;
	l=s.length();
	cout<<f(n)<<endl;
//	for(int i=0;i<24;i++)cout<<f(i);cout<<endl;
}
