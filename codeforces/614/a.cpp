#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
	ll l,r,k;
	cin>>l>>r>>k;
	ll x=1,c=0;
	while(x<=r){
		if(x>=l){
			cout<<x<<' ';
			c++;
		}
		x*=k;
	}
	if(c==0)cout<<-1;
}